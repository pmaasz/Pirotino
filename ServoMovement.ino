//Left Front Knee Pin: 1 num 0 positiv
//Left Back Knee Pin: 2 num 1 negativ
//Right Front Knee Pin: 3 num 2  negativ
//Right Back Knee Pin: 4 num 3  negativ

//Right Front Hip Pin:
//Left Front Hip Pin:
//Right Back Hip Pin:
//Left Back Hip Pin:

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
//uint8_t servonumber = 0;
/*
int pinMatrix[4][1];
pinMatrix[0][0] = 5;
pinMatrix[1][0] = 6;
pinMatrix[2][0] = 7;
pinMatrix[3][0] = 8;
*/

void servosSetup()
{
   // Analog servos run at ~60 Hz updates
  pwm.begin();
  pwm.setPWMFreq(60);
  
  Serial.println("pwm1 connected.");

  for(uint8_t i = 0; i < 8; i++){
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
      pwm.setPWM(i, 0, pulselen);
    }
  }
}

void moveForward()
{
  for(uint8_t i = 0; i < 5; i++)
  {
      servoMinToMax(i + 4);
      servoMinToMax(i);      
      servoMaxToMin(i + 4);
      servoMaxToMin(i);
  }
}

void servoMinToMax(uint8_t pin)
{
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    pwm.setPWM(pin, 0, pulselen);
  } 
}

void servoMaxToMin(uint8_t pin)
{
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    pwm.setPWM(pin, 0, pulselen);
  }
}
