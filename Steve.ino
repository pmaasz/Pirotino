#include <SPI.h>                                          //SPI Library for OLED
#include <Wire.h>
#include <Adafruit_GFX.h>                                 //Graphics library for OLED
#include <Adafruit_SSD1306.h>                             //OLED Driver
#include "Adafruit_VL53L0X.h"
#include <Adafruit_PWMServoDriver.h>

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

//Right Front Hip Pin:
//Left Front Hip Pin:
//Right Back Hip Pin:
//Left Back Hip Pin:

// our servo # counter
uint8_t servonum = 0;

Adafruit_SSD1306 display = Adafruit_SSD1306();//Create instance of OLED called display
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
 
void setup() {                
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();

  if (!lox.begin())
  {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  Serial.begin(9600);
  Serial.println("16 channel Servoboard connected.");
  
  // Analog servos run at ~60 Hz updates
  pwm.begin();
  pwm.setPWMFreq(60);
  Serial.println("pwm1 connected and initialised.");
  delay(100);
  Serial.println("Setup complete.");
  
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
    //liDar();
    //eyes();
    moveForward();
}
