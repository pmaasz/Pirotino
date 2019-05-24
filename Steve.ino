#include <SPI.h>                                          //SPI Library for OLED
#include <Wire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>                                 //Graphics library for OLED
#include <Adafruit_SSD1306.h>                             //OLED Driver
#include "Adafruit_VL53L0X.h"
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
//Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

//Left Front Knee Pin: 1 num 0 positiv
//Left Back Knee Pin: 2 num 1 negativ
//Right Front Knee Pin: 3 num 2  negativ
//Right Back Knee Pin: 4 num 3  negativ

//Right Front Hip Pin:
//Left Front Hip Pin:
//Right Back Hip Pin:
//Left Back Hip Pin:

// our servo # counter
uint8_t servonum = 0;
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
  microphoneSetup();
  servosSetup();

  Serial.println("Setup complete.");
  delay(1000);
}

void loop()
{
  draw();
  moveForward();
}
