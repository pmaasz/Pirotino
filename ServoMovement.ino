void servosSetup()
{
   // Analog servos run at ~60 Hz updates
  pwm.begin();
  pwm.setPWMFreq(60);
  
  Serial.println("pwm1 connected.");

  for(int i = 0; i <= 7; i++)
  {
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
    {
      pwm.setPWM(i, 0, pulselen);
    }
  }
}

void moveForward()
{
  Serial.println(servonum);
  
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
  {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(500);

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--)
  {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(500);
   
  servonum++;
  
  if (servonum > 7) 
  {
    servonum = 0;
  }
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

