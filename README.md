# 📈 Stattrack - Airsoft Statistics Tracker 🔫


## Overview

Stattrack is an Arduino-based project designed to track and display gameplay statistics for airsoft players. Using the Heltec Wifi LoRa 32 V3, this tracker captures critical data such as kills and deaths during gameplay, and presents it on a clear OLED display.

## Features

- **Real-Time Statistics**: Track your kills and deaths live during games.
- **Kill-Death Ratio (KDR)**: Automatically calculates and displays your KDR.
- **Battery Percentage Monitoring**: Keeps track of the battery life in real-time.
- **User-Friendly Interface**: Simple interface to increment and reset stats using buttons.
- **Customizable Gameplay Settings**: Easily reset your stats or start a new game session.

## Hardware Required

- Heltec Wifi LoRa 32 V3
- Two buttons connected to GPIO pins (for `DEATH_BUTTON` and `KILL_BUTTON`)
- OLED display (compatible with Adafruit SSD1306)
- Power source (battery or USB)
- Jumper wires and breadboard for prototyping

## Software Required

- Arduino IDE
- Required libraries:
  - `ezButton`
  - `Wire`
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`
  - `TimeOut`

## Installation

1. **Clone the Repository**: 
   ```bash
   git clone https://github.com/yourusername/stattrack.git
   cd stattrack
