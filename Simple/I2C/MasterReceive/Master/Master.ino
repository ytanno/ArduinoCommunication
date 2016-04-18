//ref https://www.arduino.cc/en/Tutorial/MasterReader

#include <Wire.h>
int SlaveDeviceID = 8;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  int receiveLength = 1; 
  Wire.requestFrom(SlaveDeviceID, receiveLength); 
  while (Wire.available())
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);      // print the character
  }
  Serial.println();
}


