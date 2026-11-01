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


# 🔬 PicoScope-X (Pico-DualScope HUD)

**PicoScope-X** is a compact, open-source, dual-channel digital storage oscilloscope and 4-channel logic analyzer powered by the **Raspberry Pi Pico 2 (RP2350)**. Built specifically for Hack Club Week 4 ("Displays Week"), this project packs powerful hardware debugging capabilities into a portable, handheld device featuring a crisp 3.2" TFT display, auto-ranging analog front-end (AFE), real-time power monitoring, and onboard micro-SD data logging.

---

## 🌟 Key Features

* **Dual-Channel Oscilloscope:** Real-time waveform rendering powered by RP2350's dual-core architecture and high-speed ADCs (`ADC0` / `ADC1`) buffered via a TL072 op-amp AFE.
* **4-Channel Logic Analyzer:** Synchronous digital signal capture utilizing RP2350 PIO (`PIO0`) for debugging SPI, I2C, UART, and GPIO states.
* **Auto-Ranging Input (1x / 10x):** DG419 analog switches dynamically switch between direct input and a precision resistor divider network for multi-range voltage measurements.
* **Real-Time Power & Battery Monitor:** Integrated INA219 high-side current sensor tracks live current, voltage, and power consumption, enabling automated battery capacity (`mAh`) discharge testing.
* **Interactive UI & Storage:** Dual rotary encoders for seamless menu navigation, timebase/voltage scaling, and a Micro-SD card slot for saving screenshots and waveform data logs.
* **Portable Power Management:** Powered by a 3.7V Li-Po battery with slide-switch control and Schottky diode reverse-polarity/USB-isolation protection.

---

## 🛠️ Bill of Materials (BOM) & Budget (~$41.00 Tier 2)

| Component | Description | Qty | Estimated Cost ($) |
| :--- | :--- | :---: | :---: |
| **Raspberry Pi Pico 2** | RP2350 Microcontroller MCU Board | 1 | $5.00 |
| **3.2" SPI TFT Display** | ILI9341 Display with Onboard Micro-SD Slot | 1 | $9.50 |
| **INA219 IC / Module** | High-Side Bi-Directional Current/Power Monitor | 1 | $1.80 |
| **DG419DJ IC** | Precision SPDT Analog Switch (Auto-Ranging) | 2 | $1.50 |
| **TL072CN IC** | Dual Low-Noise JFET Input Op-Amp (AFE Buffer) | 1 | $0.80 |
| **Rotary Encoders** | Incremental Encoder with Push Button Switch | 2 | $0.90 |
| **BNC Female Jacks** | Panel Mount RF Connectors (Ch-A & Ch-B) | 2 | $1.20 |
| **Active Buzzer & LED** | Audio feedback & Status Indicator | 1 | $1.50 |
| **Passives & Misc** | Resistors, Capacitors, Schottky Diode (1N5819), Slide Switch | Set | $2.00 |
| **Custom PCB (JLCPCB)** | 2-Layer FR-4 Custom Designed PCB | 5 pcs | $5.00 |
| **Total Estimated Cost** | | | **~$41.00** |

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

## ⚡ Power Architecture

* **USB Power (`VBUS`):** 5V supplied directly via USB connection for bench testing and programming.
* **Battery Power (`VSYS`):** 3.7V Li-Po battery routed through a physical slide switch and a **Schottky Diode (D1)** to isolate the battery from back-feeding when connected to USB.

---

## 📂 Repository Structure

```text
📦 PicoScope-X
├── 📂 hardware/         # EasyEDA schematic files, PCB layout, and gerbers
├── 📂 firmware/         # C++/MicroPython source code for RP2350
├── 📂 docs/             # Datasheets, pinout diagrams, and testing logs
└── 📄 README.md         # Project documentation
