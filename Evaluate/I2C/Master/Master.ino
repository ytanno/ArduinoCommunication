//ref https://www.arduino.cc/en/Tutorial/MasterReader
//ref https://www.arduino.cc/en/Tutorial/MasterWriter

#include <Wire.h>
int SlaveDeviceID = 8;


void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);           // start serial for output
}

void loop()
{
   //Send
  SendAlphabet();
  delay(2000);
  
  //Receive
  Serial.println("Master receive to Slave");
  Wire.requestFrom(SlaveDeviceID, 26); //not null length
  while (Wire.available())
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }
  Serial.println();
  Serial.println();
}

void SendAlphabet()
{
  Serial.println("Master send to Slave");
  Wire.beginTransmission(SlaveDeviceID); // transmit to device #8
  char ss = 'A';
  char s[27]; // + 1 = null
  for (int i = 0; i < 26; i++)
  {
    s[i] = ss + i;
  }
  s[26] = NULL;
  Serial.println(s);
  Wire.write(s);
  Wire.endTransmission();
  Serial.println();
}

