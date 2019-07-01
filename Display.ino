void setupDisplay()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  Serial.println("Display ready.");
  
  logo();
}

void logo()
{
  display.setCursor(30,10);
  display.println("Hello World");
  display.setCursor(36,20);
  display.println("Computing");
  display.display();
}

void draw()
{
  display.clearDisplay();
  
  eyes();
  liDar();
  temperature();
  
  display.display();
}
