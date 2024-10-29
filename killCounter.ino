#include <ezButton.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono18pt7b.h>
#include "SymbolMono18pt7b.h"
#include <TimeOut.h>
#include <string.h>

const int SHORT_PRESS_TIME = 500;
const int LONG_PRESS_TIME = 500;
const int BOTH_LONG_PRESS_TIME = 2000;
const int RESET_LONG_PRESS_TIME = 4000;


//Define pins
#define I2C_A_SDA 17 // GPIO8
#define I2C_A_SCL 18 // GPIO9


// OLED parameters
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RESET 21        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // Change if required

// Define display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Interval interval0;

ezButton DEATH_BUTTON(3);
ezButton KILL_BUTTON(0);

uint8_t total_kill = 0, total_death = 0, player_kill = 0, player_death = 0, battery_purcentage = 16, num_both_click = 0;

unsigned long bothPressedTime = 0;
unsigned long killPressedTime = 0;
unsigned long deathPressedTime = 0;
bool isDeathPressing = false;
bool isKillPressing = false;
bool isBothPressing = false;
bool isLongDetected = false;
bool isBothLongDetected = false;
bool isBothResetDetected = false;

void initGame(bool reset = false);

void setup() {
  Wire.begin(I2C_A_SDA, I2C_A_SCL);
  DEATH_BUTTON.setDebounceTime(15);
  KILL_BUTTON.setDebounceTime(15);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  initGame();
  display.display();
  interval0.interval(2000, decrementBatteryPurcentage);
}

void loop() {
  Interval::handler();
  DEATH_BUTTON.loop();
  KILL_BUTTON.loop();
  bool update_needed = false;

  if (DEATH_BUTTON.isPressed() && !isDeathPressing) {
    deathPressedTime = millis();
    isDeathPressing = true;
    isLongDetected = false;
  }

  if (KILL_BUTTON.isPressed() && !isKillPressing) {
    killPressedTime = millis();
    isKillPressing = true;
    isLongDetected = false;
  }

  if (DEATH_BUTTON.isPressed() && KILL_BUTTON.isPressed() && !isBothPressing) {
    bothPressedTime = millis();
    isBothPressing = true;
    isBothLongDetected = false;
    isBothResetDetected = false;
  }

  if (DEATH_BUTTON.isReleased() || KILL_BUTTON.isReleased()) {
    if (isBothPressing) {
      isBothPressing = false;
      isBothLongDetected = false;
      isBothResetDetected = false;
    }

    if (isDeathPressing) {
      long deathPressDuration = millis() - deathPressedTime;
      if (deathPressDuration < SHORT_PRESS_TIME && player_death < 99 && total_death < 255) {
        player_death++;
        total_death++;
        update_needed = true;
      }
      isDeathPressing = false;
    }

    if (isKillPressing) {
      long killPressDuration = millis() - killPressedTime;
      if (killPressDuration < SHORT_PRESS_TIME && player_kill < 99 && total_kill < 255) {
        player_kill++;
        total_kill++;
        update_needed = true;
      }
      isKillPressing = false;
    }
  }

  if (isDeathPressing && !isKillPressing && !isLongDetected) {
    long deathPressDuration = millis() - deathPressedTime;
    if (deathPressDuration > LONG_PRESS_TIME) {
      if (player_death > 0) {
        player_death--;
        total_death--;
        update_needed = true;
        isLongDetected = true;
      }
    }
  }

  if (isKillPressing && !isDeathPressing && !isLongDetected) {
    long killPressDuration = millis() - killPressedTime;
    if (killPressDuration > LONG_PRESS_TIME) {
      if (player_kill > 0) {
        player_kill--;
        total_kill--;
        update_needed = true;
        isLongDetected = true;
      }
    }
  }

  if (isBothPressing) {
    long bothPressDuration = millis() - bothPressedTime;
    if (bothPressDuration > BOTH_LONG_PRESS_TIME && !isBothLongDetected) {
      initGame();
      isBothLongDetected = true;
    }
    if (bothPressDuration > RESET_LONG_PRESS_TIME && !isBothResetDetected) {
      initGame(true);
      isBothResetDetected = true;
    }
  }

  if (num_both_click >= 3) {
    display.fillScreen(BLACK);
  }

  if (update_needed) {
    num_both_click = 0;
    display.fillRect(36, 0, 70, 64, BLACK);
    display.setTextColor(WHITE, BLACK);
    display.setCursor(38, 4);
    display.setTextSize(3);
    display.print(player_kill);
    display.setCursor(38, 38);
    display.print(player_death);
    display.setTextSize(1);
    display.setCursor(75, 0);
    float res = (float)player_kill / (player_death > 0 ? (float)player_death : 1.0);
    display.fillRect(75, 0, 60, 8, BLACK);
    display.print("KDR:" + String(res, 2));
    display.setCursor(player_kill < 10 ? 57 : 77, 20);
    display.print(String(total_kill));
    display.setCursor(player_death < 10 ? 57 : 77, 54);
    display.print(String(total_death));
    display.display();
  }
}

void initGame(bool reset) {
  num_both_click = 0;
  if (reset) {
    total_kill = 0;
    total_death = 0;
  }
  player_kill = 0;
  player_death = 0;
  battery_purcentage = 16;
  display.setTextWrap(false);
  display.fillRect(36, 0, 70, 64, BLACK);
  display.drawRect(108, 52, 20, 12, WHITE);
  display.drawRect(109, 53, 18, 10, WHITE);
  display.fillRect(110, 54, battery_purcentage, 10, WHITE);
  display.fillRect(106, 55, 2, 6, WHITE);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(38, 4);
  display.setTextSize(3);
  display.print("0");
  display.setCursor(38, 38);
  display.print("0");
  display.setTextSize(1);
  display.setCursor(75, 0);
  display.print("KDR:0.00");
  display.setCursor(57, 20);
  display.print(total_kill < 255 ? String(total_kill) : "MAX!");
  display.setCursor(57, 54);
  display.print(total_death < 255 ? String(total_death) : "MAX!");
  drawSymbol(0, 40, 137, WHITE, BLACK, 2);
  drawSymbol(0, 72, 135, WHITE, BLACK, 2);
  display.display();
}

void decrementBatteryPurcentage() {
  if (battery_purcentage > 0) {
    battery_purcentage -= 2;
    display.fillRect(110, 54, 16 - battery_purcentage, 9, BLACK);
    display.display();
  }
}

void drawSymbol(uint16_t x, uint16_t y, uint8_t c, uint16_t color, uint16_t bg, uint8_t Size) {
  if ((c >= 32) && (c <= 126)) {
    display.setFont(&FreeMono18pt7b);
  } else {
    display.setFont(&SymbolMono18pt7b);
    if (c > 126) {
      c -= (127 - 32);
    }
  }
  display.drawChar(x, y, c, color, bg, Size);
  display.setFont(NULL);
}
