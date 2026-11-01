/**
 * @file main.cpp
 * @brief PicoScope-X (RP2350) Main Firmware
 * @author Hack Club / Maker
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "hardware/pio.h"

// --- PIN DEFINITIONS ---
#define PIN_LA_0        0
#define PIN_LA_1        1
#define PIN_LA_2        2
#define PIN_LA_3        3
#define PIN_DG419_CTRL  4

#define PIN_ENC1_A      6
#define PIN_ENC1_B      7
#define PIN_ENC1_SW     8
#define PIN_ENC2_A      9
#define PIN_ENC2_B      10
#define PIN_ENC2_SW     11

#define PIN_BUZZER      13
#define PIN_I2C_SDA     14
#define PIN_I2C_SCL     15

// SPI0 Bus (TFT & SD Card shared)
#define PIN_SPI_MISO    16
#define PIN_TFT_CS      17
#define PIN_SPI_SCK     18
#define PIN_SPI_MOSI    19
#define PIN_TFT_RST     20
#define PIN_TFT_DC      21
#define PIN_SD_CS       22

#define PIN_ADC_CHA     26  // ADC0
#define PIN_ADC_CHB     27  // ADC1
#define PIN_STATUS_LED  28

// --- INA219 I2C CONFIG ---
#define INA219_ADDR     0x40
i2c_inst_t *i2c_port = i2c1;

void system_init() {
    // Standard stdio init for debugging if needed
    stdio_init_all();

    // Status LED & Buzzer setup
    gpio_init(PIN_STATUS_LED);
    gpio_set_dir(PIN_STATUS_LED, GPIO_OUT);
    gpio_init(PIN_BUZZER);
    gpio_set_dir(PIN_BUZZER, GPIO_OUT);

    // DG419 Range Select setup (Default 1x mode -> Low)
    gpio_init(PIN_DG419_CTRL);
    gpio_set_dir(PIN_DG419_CTRL, GPIO_OUT);
    gpio_put(PIN_DG419_CTRL, 0);

    // Rotary Encoders Setup with Pull-ups
    uint encoders[] = {PIN_ENC1_A, PIN_ENC1_B, PIN_ENC1_SW, PIN_ENC2_A, PIN_ENC2_B, PIN_ENC2_SW};
    for (int i = 0; i < 6; i++) {
        gpio_init(encoders[i]);
        gpio_set_dir(encoders[i], GPIO_IN);
        gpio_pull_up(encoders[i]);
    }

    // SPI0 Init for TFT & SD
    spi_init(spi0, 20 * 1000 * 1000); // 20 MHz SPI
    gpio_set_function(PIN_SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SPI_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SPI_MISO, GPIO_FUNC_SPI);

    gpio_init(PIN_TFT_CS); gpio_set_dir(PIN_TFT_CS, GPIO_OUT); gpio_put(PIN_TFT_CS, 1);
    gpio_init(PIN_SD_CS);  gpio_set_dir(PIN_SD_CS, GPIO_OUT);  gpio_put(PIN_SD_CS, 1);
    gpio_init(PIN_TFT_RST);gpio_set_dir(PIN_TFT_RST, GPIO_OUT);
    gpio_init(PIN_TFT_DC); gpio_set_dir(PIN_TFT_DC, GPIO_OUT);

    // I2C Init for INA219 Power Monitor
    i2c_init(i2c_port, 400 * 1000); // 400kHz Fast Mode
    gpio_set_function(PIN_I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_I2C_SDA);
    gpio_pull_up(PIN_I2C_SCL);

    // ADC Setup for Oscilloscope Channels (Ch-A & Ch-B)
    adc_init();
    adc_gpio_init(PIN_ADC_CHA);
    adc_gpio_init(PIN_ADC_CHB);
}

void ina219_write_register(uint8_t reg, uint16_t value) {
    uint8_t buf[3];
    buf[0] = reg;
    buf[1] = (value >> 8) & 0xFF;
    buf[2] = value & 0xFF;
    i2c_write_blocking(i2c_port, INA219_ADDR, buf, 3, false);
}

void ina219_init() {
    // Calibration and configuration for INA219
    ina219_write_register(0x00, 0x399F); // Config register (16V, 320mV range)
    ina219_write_register(0x05, 1024);   // Calibration register
}

int16_t ina219_read_current_mA() {
    uint8_t reg = 0x04; // Current register
    uint8_t buf[2];
    i2c_write_blocking(i2c_port, INA219_ADDR, &reg, 1, true);
    i2c_read_blocking(i2c_port, INA219_ADDR, buf, 2, false);
    return (int16_t)((buf[0] << 8) | buf[1]);
}

int main() {
    system_init();
    ina219_init();

    // Startup beep & LED flash
    gpio_put(PIN_BUZZER, 1);
    gpio_put(PIN_STATUS_LED, 1);
    sleep_ms(150);
    gpio_put(PIN_BUZZER, 0);
    gpio_put(PIN_STATUS_LED, 0);

    uint32_t last_tick = 0;
    
    while (true) {
        // Toggle heartbeat LED every 500ms
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time - last_tick >= 500) {
            last_tick = current_time;
            gpio_xor_mask(1ul << PIN_STATUS_LED);
        }

        // --- ADC Sampling Stub (Dual Channel Oscilloscope) ---
        adc_select_input(0); // Channel A (ADC0 / GPIO 26)
        uint16_t raw_val_a = adc_read();

        adc_select_input(1); // Channel B (ADC1 / GPIO 27)
        uint16_t raw_val_b = adc_read();

        // Read live current from INA219 for power monitoring / battery test
        int16_t current_mA = ina219_read_current_mA();

        // Feed background display refresh / UI tasks here
        sleep_us(100);
    }

    return 0;
}
