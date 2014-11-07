/*
Galileo SD card example. Based by Arduino code by David A. Mellis and Tom Igoe 
2014 Nov 01 Konstantin Kostyuk

Press RESET button for sketch restart

This example code is in the public domain. 	 
 */

/* 
Galileo specific Not Need SPI for SD! 
#include <SPI.h>
*/

#include <SD.h>

File myFile;

void setup()
{

  Serial.begin(9600);

  Serial.print("Initializing SD card...");

// Galileo specific NO any SS pin configure for SD. 
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  Serial.println("Append data to example.txt by SD.file");
  myFile.println("Galileo SD.file test");
  myFile.close();

// Access and update file by function system()  
  Serial.println("Append data to example.txt by system()");
  system("echo Galileo SD out test >> /media/realroot/example.txt");

  Serial.println();
  Serial.println("Print example.txt data");
  system("cat /media/realroot/example.txt &> /dev/ttyGS0");

  // Check to see if the file exists: 
  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }

  // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove("example.txt");

  if (SD.exists("example.txt")){ 
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }
}

void loop()
{
  // Print stars after setup()
  Serial.println("*");
  delay(1000);
}



