int range;

void liDarSetup()
{
  if (!tof.begin()){
    Serial.println("Failed to boot VL53L0X");
  }

  Serial.println("VL53L0X booted. Lidar ready!");
}

void liDar()
{
  VL53L0X_RangingMeasurementData_t measure;
  tof.rangingTest(&measure, false);
 
  if(measure.RangeStatus != 4){
    display.setCursor(85,0);
    range = measure.RangeMilliMeter;
    display.print(range);
    display.print("mm");
  } else{
    display.setCursor(85,0);
    display.print(range);
    display.print("mm");
  }
}
