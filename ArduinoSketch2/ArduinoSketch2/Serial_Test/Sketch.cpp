/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

/*
 * Hello World!
 *
 * This is the Hello World! for Arduino. 
 * It shows how to send data to the computer
 */


void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  Serial.println("Hello world!");  // prints hello with ending line break 
}

void loop()                       // run over and over again
{
  if (Serial.available()) {
    Serial.write(Serial.read());
  }
}
