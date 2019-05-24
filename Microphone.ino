const uint8_t sampleWindow = 5;                              // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
unsigned int sample2;
unsigned int sample3;
unsigned int sample4;

void microphoneSetup()
{
  Serial.println("Microphones connected"); 
}

void microphone()
{
   unsigned long startMillis= millis();                   // Start of sample window                                 
   unsigned int signalMax1 = 0;                            //minimum value
   unsigned int signalMin1 = 1024;                         //maximum value
   unsigned int signalMax2 = 0;
   unsigned int signalMin2 = 1024;
                                                          
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);                            
      sample2 = analogRead(1);
      sample3 = analogRead(2);
      sample4 = analogRead(3);

      //left-right
      if (sample < 1024)
      {                                // toss out spurious readings 
         if (sample > signalMax1)
         {
            signalMax1 = sample;                           // save just the max levels
         }
         else if (sample < signalMin1)
         {
            signalMin1 = sample;                           // save just the min levels
         }
      }
       
      if (sample2 < 1024)
      {                                // toss out spurious readings 
         if (sample2 > signalMax1)
         {
            signalMax1 = sample2;                           // save just the max levels
         }
         else if (sample2 < signalMin1)
         {
            signalMin1 = sample2;                           // save just the min levels
         }
      }

      //up-down    
      if (sample3 < 1024) {                                // toss out spurious readings 
         if (sample3 > signalMax2)
         {
            signalMax2 = sample3;                           // save just the max levels
         }
         else if (sample3 < signalMin2)
         {
            signalMin2 = sample3;                           // save just the min levels
         }
      }
       
      if (sample4 < 1024) {                                // toss out spurious readings 
         if (sample4 > signalMax2)
         {
            signalMax2 = sample4;                           // save just the max levels
         }
         else if (sample4 < signalMin2)
         {
            signalMin2 = sample4;                           // save just the min levels
         }
      }      
   }
  
   int peakToPeak1 = signalMax1 - signalMin1;               // max - min = peak-to-peak amplitude
   int peakToPeak2 = signalMax2 - signalMin2;

   if(peakToPeak1 > 50)
   {
      if(sample > sample2)
      {                            //left-right
          x=x+5;
      } 
      if(sample2 > sample)
      {
          x=x-5;
      }
   }
   
   if(x > 88){                                         //x Grenze
      x = 88;
   }
   
   if(x < 0){
    x = 0;
   }

   if(peakToPeak2 > 50)
   {
      if(sample3 > sample4)
      {                            //up-down
          y=y+5;
      } 
      if(sample4 > sample3)
      {
          y=y-5;
      }
   }
}

