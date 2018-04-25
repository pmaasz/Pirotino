void liDar()
{
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
      display.clearDisplay();
      display.setCursor(10,0);
      display.print("Distance: ");
      display.print(measure.RangeMilliMeter);
      display.print("mm");
      display.display();
      Serial.println();
      delay(100);
  } else {
    display.display();
    display.clearDisplay();
    return;
  }
}
