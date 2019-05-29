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
uint8_t servonumber = 0;
uint8_t switcher = 1;

void servosSetup()
{
   // Analog servos run at ~60 Hz updates
  pwm.begin();
  pwm.setPWMFreq(60);
  
  Serial.println("pwm1 connected.");

  for(uint8_t i = 0; i <= 7; i++){
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
      pwm.setPWM(i, 0, pulselen);
    }
  }
}

void moveForward()
{
  servoFeedback(servonumber);

  if(switcher == 1){
    servoMinToMax(servonumber);
  }
  
  if(switcher == 0){
    servoMaxToMin(servonumber);
  }
  
  delay(100);
   
  servonumber++;
  
  checkServoNumber(servonumber);
}

void moveBackward()
{
  
}

void turnRight()
{
  
}

void turnLeft()
{
   
}

void checkServoNumber(servonumber)
{
  if (servonumber > 7){
    servonumber = 0;

    setSwitcher();
  }
}

void setSwitcher()
{
  if(switcher == 1){
    switcher == 0;
  }

  if(switcher == 0){
    switcher == 1;
  }
}

void servoMinToMax(servonumber)
{
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    pwm.setPWM(servonum, 0, pulselen);
  } 
}

void servoMaxToMin(servonumber)
{
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    pwm.setPWM(servonumber, 0, pulselen);
  }
}

void servoFeedback()
{
  Serial.print("Servonumber: ");
  Serial.println(servonumber);
  Serial.print("State: ");
  Serial.println(switcher);
}

