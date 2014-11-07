/*
Galileo Ethernet connection example. Use staticIP for configure Ethernet connection
2014 Nov 01 Konstantin Kostyuk

Galileo specific - not need SPI library.

This example code is in the public domain. 	 
*/

//#include <SPI.h>
#include <Ethernet.h>

// the MAC (ethernet hardware) address for the Galileo:
byte mac[] = { 0x98, 0x4F, 0xEE, 0x01, 0x76, 0xE8 };  
//the IP address for the Galileo:
IPAddress ip(192,168,1,110);   

void setup()
{
  Serial.begin(9600);
  Serial.println("Try to configure Ethernet connection");
//  if (Ethernet.begin(mac) == 0) {
//        Serial.println("Failed to configure Ethernet using DHCP");
//    };
        Serial.println("Attempting to configure Ethernet using Static IP");
        Ethernet.begin(mac, ip);    
}

void loop () 
{
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
  delay(2000);
}
