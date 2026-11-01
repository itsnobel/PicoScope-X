# PicoScope-X
**PicoScope-X** is a compact, handheld, lightweight and portable powerful oscilloscope powered by Raspberry Pi Pico 2 (RP2350). It has 4-channel logic analyzer. This build features auto-ranging analog front-end (AFE), real-time power monitoring, a 3.2" TFT display to show outputs in sine waves, rectangles or triangles according to which signal we'll measure. Also onboard micro-SD data logging can help to sort out all data.
## Features

* **Dual-Channel Oscilloscope:** Runs on RB2350's dual core processing power to actively measure the waves formed by buffering sine wave, rectangle or triangle signal like a oscilloscope using high-speed ADCs (ADC0/ADC1). 
* **4-Channel Logic Analyzer:**  Digital signal capture utilizing RP2350 PIO (PIO0) for debugging SPI, I2C, UART, and GPIO states.
* **Auto-Ranging Input (1x / 10x(can be upgraded to 100x):** DG419 analog switches automaticly switch between direct input and a precision resistor divider network for high range voltage measurements.
* **Real-Time Power & Battery Monitor:** Integrated INA219 sensor tracks live current, voltage, and power consumption, and battery capacity (mAh) discharge testing.
* **Interactive UI & Storage:** Dual rotary encoders for seamless menu navigation, timebase/voltage scaling, and a Micro-SD card slot for saving screenshots and waveform data logs.
* **Power Management:** Powered by a 3.7V Li-Po battery with slide-switch control and diode for battery protection and charging while switch is off.

## Photos
The schematic like like mess as There were too many pins
---
<img width="1672" height="944" alt="image" src="https://github.com/user-attachments/assets/e5944c0e-c660-4846-b218-90e5881c013d" />
---
The PCB designs are kinda cool. Looks like professional design.
---
<img width="1182" height="643" alt="Screenshot 2026-10-31 230450" src="https://github.com/user-attachments/assets/85957138-e758-453e-aeb5-cdec89aaff5c" />

<img width="1492" height="789" alt="Screenshot 2026-10-31 230250" src="https://github.com/user-attachments/assets/4b7097d3-8614-4c0c-9e5c-ed7e5f12c7da" />
<img width="1276" height="663" alt="Screenshot 2026-10-31 230305" src="https://github.com/user-attachments/assets/d02a228f-3bdd-4aa5-9489-29bf29541b7e" />


---

## Repository Structure
PicoScope-X
├── PCB/              # EasyEDA schematic files, PCB layout, and gerbers
├── firmware/         # C++/MicroPython source code for RP2350
├── docs/             # Datasheets, pinout diagrams, and testing logs
└── README.md         # Project documentation
