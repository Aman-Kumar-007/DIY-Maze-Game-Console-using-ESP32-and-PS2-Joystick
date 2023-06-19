#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>


#define JOYSTICK_VRX 32
#define JOYSTICK_VRY 33
#define JOYSTICK_SW 34
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_SDA 21
#define OLED_SCL 22
Adafruit_SH1106 display(21, 22);

int playerX = SCREEN_WIDTH / 2;     // Player X-coordinate
int playerY = SCREEN_HEIGHT / 2;    // Player Y-coordinate

void setup() {
  Serial.begin(9600);
  Wire.begin();
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Maze Game");
  display.println("Ready to Play!");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  int xValue = analogRead(JOYSTICK_VRX);
  int yValue = analogRead(JOYSTICK_VRY);

  // Update player position based on joystick inputs
  if (xValue < 300) {
    playerX--;
    if (playerX < 0) {
      playerX = 0;
    }
  } else if (xValue > 700) {
    playerX++;
    if (playerX >= SCREEN_WIDTH) {
      playerX = SCREEN_WIDTH - 1;
    }
  }

  if (yValue < 300) {
    playerY--;
    if (playerY < 0) {
      playerY = 0;
    }
  } else if (yValue > 700) {
    playerY++;
    if (playerY >= SCREEN_HEIGHT) {
      playerY = SCREEN_HEIGHT - 1;
    }
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(playerX, playerY);
  display.println("P");
  display.display();
  delay(100);
}