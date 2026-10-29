# PicoScope-X
A portable dual-display digital storage oscilloscope and high-speed logic analyzer powered by the RP2040 MCU, featuring a 3.2" SPI TFT live waveform monitor, 0.91" I2C status OLED, PIO-driven parallel signal sampling, and custom analog front-end (AFE) protection circuitry on a custom PCB.

## Hardware Pin Allocation (Raspberry Pi Pico 2 / RP2350)

| Module / Component | Pins Used | Allocated GPIO Pins | Bus / Function Protocol |
| :--- | :--- | :--- | :--- |
| **3.2" SPI TFT Display** | 6 | `GPIO 16` (CS), `GPIO 17` (DC), `GPIO 18` (SCK), `GPIO 19` (MOSI), `GPIO 20` (RST), `GPIO 21` (BL) | Hardware SPI0 |
| **Micro-SD Card Slot** | 1 | `GPIO 22` (SD_CS) | Hardware SPI0 (Shared SCK/MOSI/MISO) |
| **Analog Front-End (AFE)** | 2 | `GPIO 26` (ADC0), `GPIO 27` (ADC1) | Internal High-Speed ADC |
| **Auto-Ranging Attenuator** | 2 | `GPIO 4` (Relay 1), `GPIO 5` (Relay 2) | Digital Gain Control |
| **INA219 Power/Battery Monitor**| 0 | `GPIO 14` (SDA), `GPIO 15` (SCL) | Shared Hardware I2C1 |
| **Battery Discharge Load Switch**| 1 | `GPIO 12` | PWM / Digital Control |
| **4-Channel Logic Analyzer** | 4 | `GPIO 0`, `GPIO 1`, `GPIO 2`, `GPIO 3` | Dedicated PIO0 State Machine |
| **Dual Rotary Encoders** | 6 | `GPIO 6` (E1_A), `GPIO 7` (E1_B), `GPIO 8` (E1_SW), `GPIO 9` (E2_A), `GPIO 10` (E2_B), `GPIO 11` (E2_SW) | Quadrature Decoding Interrupts |
| **Piezo Buzzer Alert** | 1 | `GPIO 13` | PWM Audio/Tone Output |
| **System Status LED** | 1 | `GPIO 28` | General Purpose Output |
| **Total GPIO Usage** | **26 / 26** | **100% Fully Utilized** | **Zero Pin Conflicts** |
