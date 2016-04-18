//ref https://www.arduino.cc/en/Tutorial/MasterReader

#include <Wire.h>
int MyDeviceID = 8;

void setup()
{
  Wire.begin(MyDeviceID);
  Wire.onRequest(RequestEvent);
}

void loop() {}

void RequestEvent() 
{
  Wire.write('a');
}

