int x = 40;
int y = 13; 
int width = 25;
int height = 10;

void eyes()
{
  //microphone();    
  drawEyes();          
}

void drawEyes()
{
  display.fillRoundRect((int)x, (int)y, width, height, 2, WHITE);
  display.fillRoundRect((int)x + 30, (int)y, width, height, 2, WHITE); 
}

