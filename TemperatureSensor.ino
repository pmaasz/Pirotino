const unsigned char One_Wire_Bus = 8;

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensoren(&oneWire);

void setupTemperature()
{ 
  sensoren.begin(); 

  uint8_t countSensor = sensoren.getDeviceCount();
  
  pinMode (4, OUTPUT);

  if(countSensor > 0){
    Serial.println("Temperature sensor connected.");
  }
}

void temperature()
{
  float temperature = measureTemperature();

  displayTemperature(temperature);
}

float measureTemperature()
{
  sensoren.requestTemperatures();
   
  return sensoren.getTempCByIndex(0);
}

void displayTemperature(float temperature)
{
  display.setCursor(0,0);
  display.println(temperature);
  display.setCursor(30,0);
  display.println("C"); 
}
