void setup() {
Serial.begin(9600);
system("ifconfig eth0 192.168.1.110 netmask 255.255.255.0 up &> /dev/ttyGS0"); //Manual setup of eth0 interface
}
void loop() {
system("ifconfig &> /dev/ttyGS0"); // print result to Galileo console
//system("ps | grep ssh &> /dev/ttyGS0");
system("ls -l /root &> /dev/ttyGS0");
//system("date >> /root/date.txt &> /dev/ttyGS0");

delay(3000);
}
