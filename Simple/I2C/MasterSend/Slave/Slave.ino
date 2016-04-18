//ref https://www.arduino.cc/en/Tutorial/MasterWriter

#include <Wire.h>
int MyDeviceID = 8;

void setup()
{
  Wire.begin(MyDeviceID);
  Wire.onReceive(ReceiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {}

void ReceiveEvent(int howMany)
{
  while (Wire.available())
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  Serial.println();
}

