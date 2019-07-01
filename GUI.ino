
uint8_t x = 40;
uint8_t y = 13; 
uint8_t width = 25;
uint8_t height = 10;
uint8_t eyeDistance = 30;
uint8_t radius = 2;

void eyes()
{   
  drawEyes();          
}

void drawEyes()
{
  display.fillRoundRect((int)x, (int)y, width, height, radius, WHITE);
  display.fillRoundRect((int)x + eyeDistance, (int)y, width, height, radius, WHITE); 
}
