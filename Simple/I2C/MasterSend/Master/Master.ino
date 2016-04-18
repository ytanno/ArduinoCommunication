//ref https://www.arduino.cc/en/Tutorial/MasterWriter

#include <Wire.h>
int SlaveDeviceID = 8;

void setup()
{
  Wire.begin(); 
}

void loop()
{
  Wire.beginTransmission(SlaveDeviceID); // transmit to device #8
  Wire.write('a');
  Wire.endTransmission();
}


