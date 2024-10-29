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

## Roadmap

🚀 **Future Enhancements**

We have exciting plans for Stattrack! Here are some upcoming features that we aim to implement:

1. ⏱️ **Chronometer**: Add a stopwatch functionality to time gameplay sessions. This will help players track the duration of their matches and improve strategy over time.

2. ⏲️ **Timer**: Introduce a countdown timer for specific game scenarios or training sessions. Players can set a timer for drills or match intervals, enhancing their overall performance and preparedness.

3. 📱 **Mobile App Integration**: Develop a companion mobile app that syncs with the tracker to provide detailed statistics and insights. Users could analyze their gameplay on their phones and receive real-time updates, share stats or achievements on social media platforms.

We believe these features will enhance the user experience and provide more comprehensive tools for airsoft enthusiasts. Stay tuned for updates as we continue to develop Stattrack!
