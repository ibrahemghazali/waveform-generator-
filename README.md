# 🎛️ PIC18F4620 Waveform Generator using AD9833

This project is an embedded waveform generator built using the **PIC18F4620 microcontroller** and the **AD9833 programmable waveform generator IC**.  
It demonstrates a complete embedded system that combines **signal generation, user interface, ADC control, EEPROM persistence, and interrupt-driven input**.

---

# 📌 Project Overview

The system allows the user to:
- Generate different waveforms:
  - Sine wave
  - Square wave
  - Triangle wave
- Control output frequency using ADC input
- Switch modes using buttons
- Display system state on a 4-bit LCD
- Save selected waveform mode in EEPROM

---

# 🧠 System Architecture

The project is divided into three main layers:

## 1️⃣ ECU Layer (External Components)
- LCD (4-bit mode) for UI
- AD9833 waveform generator module

## 2️⃣ MCAL Layer (Microcontroller Abstraction)
- ADC driver (frequency control input)
- EEPROM driver (mode persistence)
- External interrupts (buttons)
- Timer1 (if needed for system timing)
- SPI (used by AD9833 driver)

## 3️⃣ Application Layer
- Main state machine
- UI logic
- Mode selection
- Screen handling

---

# ⚙️ AD9833 Driver Working Flow

The AD9833 driver is a **stateful SPI-based peripheral driver** responsible for waveform generation.

## 🔹 Initialization Flow
- Configure FSYNC GPIO pin
- Initialize SPI in master mode
- Calculate frequency register:
  
  \[
  FREQ = \frac{2^{28} \cdot f_{out} \cdot 2}{MCLK}
  \]

- Send initialization sequence:
  1. Control register (reset + waveform config)
  2. Frequency LSB
  3. Frequency MSB
  4. Start output command

- Store:
  - Current waveform state
  - Frequency register value

---

## 🔹 Waveform Selection
The driver supports:

- Sine wave
- Square wave
- Square wave ÷2
- Sine wave ÷2
- Triangle wave

Each function:
- Sends control word via SPI
- Updates internal waveform state
- Reconfigures output mode

---

## 🔹 Frequency Update Flow
When frequency changes:
- ADC reads new value
- Driver recalculates frequency register
- Re-sends:
  - Control word
  - Frequency LSB
  - Frequency MSB
  - Restart output

The waveform mode remains unchanged.

---

## 🔹 SPI Communication Flow
Each transmission follows:

1. FSYNC LOW  
2. Send 16-bit command via SPI  
3. FSYNC HIGH  
4. Small delay for stabilization  

---

# 🖥️ Application Flow (Main System Logic)

## 🔹 System Initialization
At startup:
- Read last waveform mode from EEPROM
- Initialize LCD
- Initialize ADC
- Initialize AD9833 driver
- Initialize external interrupts

Then display:
- Current waveform
- Current frequency

---

## 🔹 Main Loop Behavior

The system runs in a continuous loop:

### 📊 1. Frequency Monitoring
- ADC reads potentiometer (channel 3)
- Updates displayed frequency
- Updates AD9833 frequency if needed

---

### 📺 2. Screen 1 (Main Display)
Shows:
- Current waveform mode
- Current frequency

---

### 📺 3. Screen 2 (Menu Mode)
Activated via OK button:

User can select:
- Square wave
- Triangle wave
- Sine wave

Cursor button moves selection arrow.

---

## 🔘 Button Control (Interrupt Driven)

### OK Button
- Switch between:
  - Screen 1 (display mode)
  - Screen 2 (selection mode)
- On confirm:
  - Apply selected waveform
  - Save mode to EEPROM
  - Update AD9833 output

---

### Cursor Button
- Moves selection arrow between:
  - Square
  - Triangle
  - Sine
- Cycles through menu items

---

## 💾 EEPROM Behavior
- Stores last selected waveform mode
- On power-up:
  - System restores last state automatically

---

# 🧩 Key Features

- Real-time frequency control via ADC
- Persistent waveform selection using EEPROM
- Interrupt-driven UI system
- Modular HAL/ECU architecture
- SPI-based waveform generation
- LCD-based user interface

---

# ⚠️ Important Notes

- Interrupts are used for testing purposes in this version
- FSYNC timing is software-controlled (blocking SPI)
- System is designed for PIC18F4620 architecture

---

# 🛠️ Required Development Environment

This project is designed to run on:

## 🔧 :contentReference[oaicite:0]{index=0}

### Requirements:
- MPLAB X IDE installed
- XC8 Compiler
- PIC18F4620 device support
- Proper configuration bits setup
- External hardware:
  - AD9833 module
  - 4-bit LCD
  - ADC input (potentiometer)
  - Push buttons

---

# 📚 Future Documentation / Resources

I will be adding supporting resources to help understand and develop this driver, including:

- AD9833 datasheet breakdown
- SPI timing explanation
- Frequency register derivation (28-bit formula)
- LCD driver architecture
- Interrupt system design
- Full embedded system block diagram
- Driver-level API documentation

These resources will help in understanding:
> how each layer interacts and how the waveform generator system is built from scratch.

---

# 🚀 Summary

This project represents a full embedded system implementation combining:
- Analog input (ADC)
- Digital control (buttons + interrupts)
- Communication protocol (SPI)
- Persistent storage (EEPROM)
- User interface (LCD)
- Signal generation (AD9833)

It is a complete learning step toward real-world embedded system design.