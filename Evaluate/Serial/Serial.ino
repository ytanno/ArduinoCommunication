//ref http://www.instructables.com/id/Simple-Chat-Program-with-Arduino-Uno/?ALLSTEPS

#include <SoftwareSerial.h>

SoftwareSerial chat(10, 11); // RX, TX

int text;

void setup()  
{
  // open hardware serial, TX = 1, RX = 0
  Serial.begin(9600);
  Serial.println("Starting Chat Program...");
  // set the data rate for the SoftwareSerial port
  chat.begin(9600);
  delay(1000); // delay 1s to stabilize serial ports
  chat.write("Hello World");
}

void loop() 
{
 
  if (chat.available()) 
    Serial.write(chat.read());
    
  if (Serial.available()) 
  {
    Serial.print("Me:\t");
    while (Serial.available()) 
    {
      text = Serial.read();
      chat.write(text);
      Serial.write(text);
    }
    chat.println();
    Serial.println();
  }
}
