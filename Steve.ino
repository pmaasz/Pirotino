#include <SPI.h>                                          //SPI Library for OLED
#include <Wire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>                                 //Graphics library for OLED
#include <Adafruit_SSD1306.h>                             //OLED Driver
#include "Adafruit_VL53L0X.h"
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
//Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);


//Create instance of OLED called display
Adafruit_SSD1306 display = Adafruit_SSD1306();
//create an instance of the Time of Flight Sensor
Adafruit_VL53L0X tof = Adafruit_VL53L0X();

void setup() 
{                
  Serial.begin(9600);
  Wire.begin();

  setupDisplay();
  setupTemperature();
  liDarSetup();  
  //microphoneSetup();
  servosSetup();

  Serial.println("Setup complete.");
  delay(1000);
}

void loop()
{
  draw();
  moveForward();
}
