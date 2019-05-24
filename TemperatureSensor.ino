#define OLED_RESET 4  

const unsigned char One_Wire_Bus = 8;
int countSensor = 0;

OneWire oneWire(One_Wire_Bus);
DallasTemperature sensoren(&oneWire);

void setupTemperature()
{ 
  sensoren.begin(); 

  countSensor = sensoren.getDeviceCount();

  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);

  Serial.println("Temperature sensor connected.");
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



