//ref https://www.arduino.cc/en/Tutorial/MasterReader
//ref https://www.arduino.cc/en/Tutorial/MasterWriter

#include <Wire.h>
int MyDeviceID = 8;

void setup()
{
  Wire.begin(MyDeviceID);
  Wire.onReceive(ReceiveEvent); // register event
  Wire.onRequest(RequestEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

void ReceiveEvent(int howMany)
{
  Serial.println("Slave receive to Master");
  while (Wire.available())
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  Serial.println();
  Serial.println();
}

void RequestEvent() {
  SendAlphabet();
}

void SendAlphabet()
{
  Serial.println("Slave Send to Master");
  char c = 'a';
  char s[27]; // + 1 = null
  for (int i = 0; i < 26; i++)
  {
    s[i] = c + i;
  }
  s[26] = NULL;
  Serial.println(s);
  Serial.println();

  Wire.write(s);
}


