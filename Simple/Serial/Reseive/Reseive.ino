//ref http://www.instructables.com/id/Simple-Chat-Program-with-Arduino-Uno/?ALLSTEPS

#include <SoftwareSerial.h>

SoftwareSerial ss(10, 11); // RX, TX
void setup()  
{
  Serial.begin(9600);
  ss.begin(9600);
  delay(1000);  // delay 1s to stabilize serial ports
}

void loop() 
{
   if (ss.available()) 
   {
      char c = ss.read();
      Serial.println(c);
   }
}
