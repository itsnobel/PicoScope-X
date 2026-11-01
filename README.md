# PicoScope-X
**PicoScope-X** is a compact, handheld, lightweight and portable powerful oscilloscope powered by Raspberry Pi Pico 2 (RP2350). It has 4-channel logic analyzer. This build features auto-ranging analog front-end (AFE), real-time power monitoring, a 3.2" TFT display to show outputs in sine waves, rectangles or triangles according to which signal we'll measure. Also onboard micro-SD data logging can help to sort out all data.
## Features

* **Dual-Channel Oscilloscope:** Runs on RB2350's dual core processing power to actively measure the waves formed by buffering sine wave, rectangle or triangle signal like a oscilloscope using high-speed ADCs (ADC0/ADC1). 
* **4-Channel Logic Analyzer:**  Digital signal capture utilizing RP2350 PIO (PIO0) for debugging SPI, I2C, UART, and GPIO states.
* **Auto-Ranging Input (1x / 10x(can be upgraded to 100x):** DG419 analog switches automaticly switch between direct input and a precision resistor divider network for high range voltage measurements.
* **Real-Time Power & Battery Monitor:** Integrated INA219 high-side current sensor tracks live current, voltage, and power consumption, enabling automated battery capacity (mAh) discharge testing.
* **Interactive UI & Storage:** Dual rotary encoders for seamless menu navigation, timebase/voltage scaling, and a Micro-SD card slot for saving screenshots and waveform data logs.
* **Power Management:** Powered by a 3.7V Li-Po battery with slide-switch control and diode for battery protection and charging while switch is off.

---

## 🔌 Pin Allocation & Mapping (RP2350)

| Pico 2 Pin | Function / Peripheral | Description |
| :--- | :--- | :--- |
| **GPIO 0 - 3** | Logic Analyzer Ch 0–3 | High-speed digital capture inputs via PIO |
| **GPIO 4** | DG419 Control (Range Select) | Switches between 1x and 10x attenuation |
| **GPIO 6 - 8** | Rotary Encoder 1 | Navigation, Timebase, and Push Button |
| **GPIO 9 - 11** | Rotary Encoder 2 | Voltage Scale and Select Button |
| **GPIO 13** | Piezo Buzzer | Audible feedback and alert trigger |
| **GPIO 14 - 15** | I2C1 (SDA / SCL) | Communication bus for INA219 power monitor |
| **GPIO 16** | SPI0 MISO | Shared data input for TFT Display & Micro-SD |
| **GPIO 17** | TFT CS | Dedicated Chip Select for ILI9341 Display |
| **GPIO 18** | SPI0 SCK | Shared clock line for Display & SD Card |
| **GPIO 19** | SPI0 MOSI | Shared data output line |
| **GPIO 20** | TFT RST | Display hardware reset line |
| **GPIO 21** | TFT D/C | Display Data/Command control pin |
| **GPIO 22** | SD CS | Dedicated Chip Select for Micro-SD Card |
| **GPIO 26** | ADC0 (Channel A) | Buffered analog input for Oscilloscope Ch-A |
| **GPIO 27** | ADC1 (Channel B) | Buffered analog input for Oscilloscope Ch-B |
| **GPIO 28** | Status LED | System heartbeat and activity indicator |

---

## Power Architecture

* **USB Power (`VBUS`):** 5V supplied directly via USB connection for bench testing and programming.
* **Battery Power (`VSYS`):** 3.7V Li-Po battery routed through a physical slide switch and a **Schottky Diode (D1)** to isolate the battery from back-feeding when connected to USB.

---

## Repository Structure
PicoScope-X
├── PCB/         # EasyEDA schematic files, PCB layout, and gerbers
├── firmware/         # C++/MicroPython source code for RP2350
├── docs/             # Datasheets, pinout diagrams, and testing logs
└── README.md         # Project documentation
