//////////////////////////////////////////////////////////////////
/*
Galileo I2C example for TMP102 sensor. Based by Arduino code under the MIT License
2014 Nov 01 Konstantin Kostyuk

No Galileo specific. 

This example code is in the public domain. 	 
 */

 
#include <Wire.h>
int tmp102Address = 0x48;
 
void setup(){
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Start measure temperature");
}
 
void loop(){
 
  float celsius = getTemperature();
  Serial.print("Celsius: ");
  Serial.println(celsius);
 
  float fahrenheit = (1.8 * celsius) + 32;
  Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);
 
  delay(1000); //just here to slow down the output. You can remove this
}
 
float getTemperature(){
  Wire.requestFrom(tmp102Address,2); 
 
  byte MSB = Wire.read();
  byte LSB = Wire.read();
 
  //it's a 12bit int, using two's compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4; 
 
  float celsius = TemperatureSum*0.0625;
  return celsius;
}
