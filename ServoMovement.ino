void moveForward()
{
  Serial.println(servonum);
  
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
  {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(1000);

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--)
  {
    pwm.setPWM(servonum, 0, pulselen);
  }

  delay(1000);
   
  servonum++;
  
  if (servonum > 7) 
  {
    servonum = 0;
  }
}


 

