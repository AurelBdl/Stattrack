# 📊 User Manual

This project is an **airsoft stats tracker** based on Arduino with a 64x128 OLED display, designed to be simple and intuitive. It tracks **kills**, **deaths**, and the **KDR** (Kill/Death Ratio) and includes a **stopwatch** and a **timer**. With only 3 buttons, this tracker is built for easy and seamless interaction.

## 🎮 Button Functions

The tracker has **three main pages** that you can cycle through in a continuous loop:

1. **Statistics (Kills/Deaths/KDR)**
2. **Stopwatch**
3. **Timer**

![Pages example](https://i.ytimg.com/vi/dk-01OpKYuQ/hq720.jpg?sqp=-oaymwEhCK4FEIIDSFryq4qpAxMIARUAAAAAGAElAADIQj0AgKJD&rs=AOn4CLCKh1FXLM-NTzz4vSwquX2k6hsTWQ)

### 🕹️ Buttons and Actions

- **Button 1 (➡️ Navigation)**: Moves to the next page (continuous loop).
- **Button 2**: Controls specific functions on each page (e.g., adding a kill, starting the stopwatch).
- **Button 3**: Adjusts certain values like the number of deaths or timer duration.

---

### 📈 1. KDR Page

- **Navigation (Button 1)** ➡️ Goes to the **Stopwatch** page.
- **Kills (Button 2)** 🎯:
  - Short press: Adds a kill ➕.
  - Long press (>2 second): Removes a kill ➖.
- **Deaths (Button 3)** 🎯:
  - Short press: Adds a death ➕.
  - Long press (>2 second): Removes a death ➖.

---

### ⏱️ 2. Stopwatch Page

- **Navigation (Button 1)** ➡️ Goes to the **Timer** page.
- **Start/Stop (Button 2)** 🎯:
  - Short press: Starts or stops the stopwatch ▶️⏸️.
  - Long press (>2 second): Resets the stopwatch 🔄.
- **Save time (Button 3)** 🎯:
  - Short press: Save the current time of the stopwatch (you can save up to 3 different times) 💾.
  - Long press (>2 second): Resets the saved times 🔄.

---

### ⏲️ 3. Timer Page

- **Navigation (Button 1)** ➡️ Returns to the **Statistics** page.
- **Start/Stop (Button 2)** 🎯:
  - Short press: Starts or stops the timer ▶️⏸️.
  - Long press (>2 second): Resets the timer to the default value (e.g., 5 minutes) 🔄.
- **Time Setting (Button 3)** 🎯:
  - Short press: Increases timer duration in preset steps (e.g., +1 minute) ⏫.
  - Long press (>2 second): Decreases timer duration in preset steps (e.g., -1 minute) ⏬.

---

### 🔌 Powering On/Off the Module

To turn the module **on** or **off**, press and hold the **Navigation Button (Button 1)** ➡️ for a few seconds. This feature helps to conserve battery when the tracker is not in use and makes powering on/off simple and intuitive.

- **Long press (Button 1)**: Toggles the power state.
  - If the module is off, a long press will power it on ⏻.
  - If the module is on, a long press will power it off ⏻.
    
---

💡 **Enjoy your game!** Enhance your airsoft experience with this practical and customizable tracker.
