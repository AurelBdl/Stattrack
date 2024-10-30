# 📊 User Manual

This project is an **airsoft stats tracker** based on Arduino with a 64x128 OLED display, designed to be simple and intuitive. It tracks **kills**, **deaths**, and the **KDR** (Kill/Death Ratio) and includes a **stopwatch** and a **timer**. With only 3 buttons, this tracker is built for easy and seamless interaction.

## 🎮 Button Functions

The tracker has **three main pages** that you can cycle through in a continuous loop:

1. **Statistics (Kills/Deaths/KDR)**
2. **Stopwatch**
3. **Timer**

### 🕹️ Buttons and Actions

- **Button 1 (➡️ Navigation)**: Moves to the next page (continuous loop).
- **Button 2 (🎯 Action)**: Controls specific functions on each page (e.g., adding a kill, starting the stopwatch).
- **Button 3 (⚙️ Settings)**: Adjusts certain values like the number of deaths or timer duration.

---

### 📈 1. Statistics Page

- **Navigation (Button 1)** ➡️ Goes to the **Stopwatch** page.
- **Kills (Button 2)** 🎯:
  - Short press: Adds a kill ➕.
  - Long press (>1 second): Removes a kill ➖.
- **Deaths (Button 3)** ⚙️:
  - Short press: Adds a death ➕.
  - Long press (>1 second): Removes a death ➖.

---

### ⏱️ 2. Stopwatch Page

- **Navigation (Button 1)** ➡️ Goes to the **Timer** page.
- **Start/Stop (Button 2)** 🎯:
  - Short press: Starts or stops the stopwatch ▶️⏸️.
  - Long press (>1 second): Resets the stopwatch 🔄.

---

### ⏲️ 3. Timer Page

- **Navigation (Button 1)** ➡️ Returns to the **Statistics** page.
- **Start/Stop (Button 2)** 🎯:
  - Short press: Starts or stops the timer ▶️⏸️.
  - Long press (>1 second): Resets the timer to the default value (e.g., 5 minutes) 🔄.
- **Time Setting (Button 3)** ⚙️:
  - Short press: Increases timer duration in preset steps (e.g., +1 minute) ⏫.
  - Long press (>1 second): Decreases timer duration in preset steps (e.g., -1 minute) ⏬.

---

## 🚀 Recommendations

- **Visual Feedback**: A quick visual confirmation (like an animation or icon) for each action will ensure a smooth and user-friendly experience.
  
💡 **Enjoy your game!** Enhance your airsoft experience with this practical and customizable tracker.
