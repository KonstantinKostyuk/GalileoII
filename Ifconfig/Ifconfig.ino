/*
Galileo Net Interface example.
2014 Nov 01 Konstantin Kostyuk

Galileo specific function system() 

This example code is in the public domain. 	 
 */

void setup() {
Serial.begin(9600);
system("ifconfig eth0 192.168.1.110 netmask 255.255.255.0 up &> /dev/ttyGS0"); //Manual setup of eth0 interface
}
void loop() {
system("ifconfig &> /dev/ttyGS0"); // print result to Galileo console
delay(5000);
}
