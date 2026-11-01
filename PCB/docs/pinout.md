# PicoScope-X Hardware Pinout & Mapping

This document details the complete pin assignments and hardware mapping for the PicoScope-X (RP2350) project.

## Raspberry Pi Pico 2 (RP2350) Pin Connections

| Pin Number | Pin Name | Assigned Peripheral / Function | Connection Description |
| :--- | :--- | :--- | :--- |
| Pin 1 | GPIO 0 | Logic Analyzer Ch 0 | Digital input for signal capture |
| Pin 2 | GPIO 1 | Logic Analyzer Ch 1 | Digital input for signal capture |
| Pin 4 | GPIO 2 | Logic Analyzer Ch 2 | Digital input for signal capture |
| Pin 5 | GPIO 3 | Logic Analyzer Ch 3 | Digital input for signal capture |
| Pin 7 | GPIO 4 | DG419 Control | Range select (1x / 10x attenuation) |
| Pin 9 | GPIO 6 | Rotary Encoder 1 (A) | Navigation / Timebase encoder pin A |
| Pin 10 | GPIO 7 | Rotary Encoder 1 (B) | Navigation / Timebase encoder pin B |
| Pin 11 | GPIO 8 | Rotary Encoder 1 (SW) | Encoder push button switch |
| Pin 12 | GPIO 9 | Rotary Encoder 2 (A) | Voltage scale encoder pin A |
| Pin 14 | GPIO 10 | Rotary Encoder 2 (B) | Voltage scale encoder pin B |
| Pin 15 | GPIO 11 | Rotary Encoder 2 (SW) | Encoder push button switch |
| Pin 17 | GPIO 13 | Active Buzzer | Audio feedback output |
| Pin 19 | GPIO 14 | I2C1 SDA | INA219 current/power monitor data line |
| Pin 20 | GPIO 15 | I2C1 SCL | INA219 current/power monitor clock line |
| Pin 21 | GPIO 16 | SPI0 MISO | Shared MISO line for TFT & SD Card |
| Pin 22 | GPIO 17 | TFT CS | Dedicated Chip Select for ILI9341 display |
| Pin 23 | GPIO 18 | SPI0 SCK | Shared clock line for TFT & SD Card |
| Pin 24 | GPIO 19 | SPI0 MOSI | Shared data output line |
| Pin 25 | GPIO 20 | TFT RST | Display hardware reset |
| Pin 26 | GPIO 21 | TFT D/C | Display Data/Command control |
| Pin 29 | GPIO 22 | SD CS | Dedicated Chip Select for Micro-SD card |
| Pin 31 | GPIO 26 | ADC0 (Channel A) | Buffered analog input via TL072 op-amp |
| Pin 32 | GPIO 27 | ADC1 (Channel B) | Buffered analog input via TL072 op-amp |
| Pin 34 | GPIO 28 | Status LED | System heartbeat & indicator via 1k resistor |
| Pin 36 | 3V3 | System Power Output | 3.3V regulated rail for sensors and display |
| Pin 39 | VSYS | Battery Power Input | Power input from 3.7V Li-Po via switch & diode |
| Pin 40 | VBUS | USB 5V Input | 5V rail when connected via USB |
