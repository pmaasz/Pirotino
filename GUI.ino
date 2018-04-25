int x = 45;
int y = 5; 
int width;
int height;

void eyes()
{
  //x = random();
  //y = random();     

     //x Grenze
     if(x > 88)
     {                                         
      x = 88;
     }
     if(x < 0) {
      x = 0;
     }
     
     //y Grenze    
     if(y > 10)
     {                                         
      y = 10;
     }
     if(y < 0)
     {
      y = 0;
     }

    //Augengrößen
    if(x < 3 || x > 85)
    {                             
       width = 35;
    } else {
       width = 40;
      }
    
    if(y > 9 || y < 3) {
       height = 17;
    } else {
       height = 20;
      }
   
   //Drawing     
   display.fillRoundRect((int)x, (int)y, width, height, 3, WHITE);   
   display.display();                                     
   display.clearDisplay();                                
}

