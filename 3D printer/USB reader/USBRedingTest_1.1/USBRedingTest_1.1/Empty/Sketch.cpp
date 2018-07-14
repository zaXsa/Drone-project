/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/* ===============================================================
      Project: CH376S USB Read/Write Module testing ground
       Author: Scott C
      Created: 1st May 2015
  Arduino IDE: 1.6.2
      Website: http://arduinobasics.blogspot.com/p/arduino-basics-projects-page.html
  Description: This project will allow you to perform many of the functions available on the CH376S module.
               Checking connection to the module, putting the module into USB mode, resetting the module, 
               reading, writing, appending text to files on the USB stick. This is very useful alternative to
               SD card modules, plus it doesn't need any libraries.
================================================================== */

#include <SoftwareSerial.h>
#include "USBReader.h"

byte computerByte;										//used to store data coming from the computer
byte USB_Byte;											//used to store data coming from the USB stick
int LED = 13;											//the LED is connected to digital pin 13 
int timeOut = 2000;										//TimeOut is 2 seconds. This is the amount of time you wish to wait for a response from the CH376S module.
String wrData = "What is the meaning of life ?";		//We will write this data to a newly created file.
String wrData2 = "42";                                   //We will append this data to an already existing file.

SoftwareSerial USB(10, 11);								// Digital pin 10 on Arduino (RX) connects to TXD on the CH376S module
														// Digital pin 11 on Arduino (TX) connects to RXD on the CH376S module
														// GND on Arduino to GND on CH376S module
														// 5V on Arduino to 5V on CH376S module
//==============================================================================================================================================
void setup() {
  Serial.begin(9600);									// Setup serial communication with the computer (using a baud rate of 9600 on serial monitor)
  USB.begin(9600);										// Setup serial communication with the CH376S module (using the default baud rate of 9600)
  pinMode(LED,OUTPUT);									// Define digital pin 13 as an OUTPUT pin - so that we can use it with an LED
  digitalWrite(LED,LOW);								// Turn off the LED
}

//================================================================================================================================================
void loop() {
  if(Serial.available()){
    computerByte = Serial.read();						//read any incoming bytes from the Serial monitor, and store this byte in the variable called computerByte
    if(computerByte==49){               //1				//If you send the number 1 from the serial monitor, the arduino will read it as digital number 49. Google "ascii table" for more info.
	    printCommandHeader("COMMAND1: CHECK CONNECTION");
	    checkConnection(0x01);							// Check for successful connection and communication with the CH376S module.
    }
    if(computerByte==50){               //2
	    printCommandHeader("COMMAND2: set_USB_Mode");
	    set_USB_Mode(0x06);								// Code used to enable read/write communication and monitoring of the USB stick
    }
    if(computerByte==51){               //3
	    printCommandHeader("COMMAND3: resetALL");
	    resetALL();// Reset the USB device
    }
    if(computerByte==52){               //4
      printCommandHeader("COMMAND4: Create and Write to File : TEST4.TXT");
      writeFile("TEST4.TXT", wrData);					// Create a file called TEST4.TXT and then Write the contents of wrData to this file
    }
    if(computerByte==53){				//5
      printCommandHeader("COMMAND5: Read File: TEST4.TXT");
      readFile("TEST4.TXT");							// Read the contents of this file on the USB disk, and display contents in the Serial Monitor
    }
    if(computerByte==54){               //6
      printCommandHeader("COMMAND6: Append data to file: TEST4.TXT");
      appendFile("TEST4.TXT", wrData2);					// Append data to the end of the file.
    }
    if(computerByte==55){               //7
      printCommandHeader("COMMAND7: Delete File: TEST4.TXT");
      fileDelete("TEST4.TXT");							// Delete the file named TEST4.TXT
    }
    if(computerByte==56){               //8
      printCommandHeader("COMMAND8: Read File: TEST2.TXT");
      readFile("TEST2.TXT");							// Read the contents of the TEST2.TXT file on the USB disk, and display contents in the Serial Monitor
    }
    if(computerByte==57){               //9
      printCommandHeader("COMMAND9: Read File: TEST3.TXT");
      readFile("TEST3.TXT");							// Read the contents of the TEST3.TXT file on the USB disk, and display contents in the Serial Monitor
    }
  }
  
  if(USB.available()){									// This is here to capture any unexpected data transmitted by the CH376S module
    Serial.print("CH376S has just sent this code:");
    Serial.println(USB.read(), HEX);
  }
}

//END OF LOOP FUNCTION ========================================================================================================================================

