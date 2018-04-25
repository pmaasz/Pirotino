#include <SPI.h>                                          //SPI Library for OLED
#include <Wire.h>
#include <Adafruit_GFX.h>                                 //Graphics library for OLED
#include <Adafruit_SSD1306.h>                             //OLED Driver
#include "Adafruit_VL53L0X.h"

 Adafruit_SSD1306 display = Adafruit_SSD1306();//Create instance of OLED called display
 Adafruit_VL53L0X lox = Adafruit_VL53L0X();
 
void setup() {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();

    if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(30,10);
  display.println("Hello World");
  display.setCursor(36,20);
  display.println("Computing");
  display.display();
  delay(2000);
  display.clearDisplay();
}


void loop() {
    liDar();
    //eyes();
}
