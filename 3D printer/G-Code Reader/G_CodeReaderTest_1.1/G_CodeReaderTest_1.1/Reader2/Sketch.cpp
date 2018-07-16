﻿/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
/* #define BAUD (57600) // How fast is the Arduino talking?
#define MAX_BUF (64) // What is the longest message Arduino can store?

char buffer[MAX_BUF]; // where we store the message until we get a ';'
int sofar; // how much is in the buffer

/**
 * Uses Bresenham's line algorithm to move both motors
 * @input newx the destination x position
 * @input newy the destination y position
 **/
 /*
  * 
void line(float newx,float newy) {
  long dx=newx-px; // distance to move (delta)
  long dy=newy-py;
  int dirx=dx > 0?1:-1; // direction to move
  int diry=dy > 0?1:-1;
  dx=abs(dx); // absolute delta
  dy=abs(dy);

  long i;
  long over=0;

  if(dx > dy) {
    for(i=0;i < dx;++i) {
      m1.onestep(dirx);
      over+=dy;
      if(over>=dx) {
        over-=dx;
        m2.onestep(diry);
      }
      pause(step_delay); // step_delay is a global connected to feed rate.
      // test limits and/or e-stop here
    }
  } else {
    for(i=0;i < dy;++i) { m2.onestep(diry); over+=dx; if(over>=dy) { over-=dy; m1.onestep(dirx); } pause(step_delay); 
    // step_delay is a global connected to feed rate. 
    // test limits and/or e-stop here } } 
    // update the logical position. We don't just = newx because 
    // px + dx * dirx == newx could be false by a tiny margin and we don't want rounding errors. px+= dx*dirx; py+= dy*diry; } 
    /** * delay for the appropriate number of microseconds * @input ms how many milliseconds to wait  
    void pause(long ms) { delay(ms/1000); delayMicroseconds(ms%1000); // delayMicroseconds doesn't work for values > ~16k. }
    /** * Set the feedrate (speed motors will move) * @input nfr the new speed in steps/second 
    void set_feedrate(float nfr) { if(fr==nfr) return; 
    // same as last time? quit now. if(nfr > MAX_FEEDRATE || nfr < MIN_FEEDRATE) { // don't allow crazy feed rates
    Serial.print(F("New feedrate must be greater than "));
    Serial.print(MIN_FEEDRATE);
    Serial.print(F("steps/s and less than "));
    Serial.print(MAX_FEEDRATE);
    Serial.println(F("steps/s."));
    return;
  }
  step_delay = 1000000.0/nfr;
  auto fr=nfr;
}
/**
 * Read the input buffer and find any recognized commands. One G or M command per line.

void processCommand() {
  // look for commands that start with 'G'
  int cmd=Serial.parseInt('G',-1);
  switch(cmd) {
  case 0: // move in a line
  case 1: // move in a line
    set_feedrate(parsenumber('F',fr));
    line( parsenumber('X',(mode_abs?px:0)) + (mode_abs?0:px),
    parsenumber('Y',(mode_abs?py:0)) + (mode_abs?0:py) );
    break;
  // case 2: // clockwise arc
  // case 3: // counter-clockwise arc
  case 4: pause(parsenumber('P',0)*1000); break; // wait a while
  case 90: mode_abs=1; break; // absolute mode
  case 91: mode_abs=0; break; // relative mode
  case 92: // set logical position
    position( Serial.parseInt('X',0),
    Serial.parseInt('Y',0) );
    break;
  default: break;
  }

  // look for commands that start with 'M'
  cmd=parsenumber('M',-1);
  switch(cmd) {
  case 18: // turns off power to steppers (releases the grip)
    m1.release();
    m2.release();
    break;
  case 100: help(); break;
  case 114: where(); break; // prints px, py, fr, and mode.
  default: break;
  }

  // if the string has no G or M commands it will get here and the Arduino will silently ignore it
}
/**
 * First thing this machine does on startup. Runs only once.
 
void setup() {
  Serial.begin(BAUD); // open coms
  help(); // say hello
  set_feedrate(200); // set default speed
  ready();
}

/**
 * display helpful information

void help() {
  Serial.print(F("CNC Robot "));
  Serial.println(VERSION);
  Serial.println(F("Commands:"));
  Serial.println(F("G00 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move"));
  Serial.println(F("G01 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move"));
  Serial.println(F("G04 P[seconds]; - delay"));
  Serial.println(F("G90; - absolute mode"));
  Serial.println(F("G91; - relative mode"));
  Serial.println(F("G92 [X(steps)] [Y(steps)]; - change logical position"));
  Serial.println(F("M18; - disable motors"));
  Serial.println(F("M100; - this help message"));
  Serial.println(F("M114; - report position and feedrate"));
}

/**
 * prepares the input buffer to receive a new message and 
 * tells the serial connected device it is ready for more.

void ready() {
  sofar=0; // clear input buffer
  Serial.print(F("> ")); // signal ready to receive input
}
/**
 * After setup() this machine will repeat loop() forever.

void loop() {
  // listen for commands
  if( Serial.available() ) { // if something is available
    char c = Serial.read(); // get it
    Serial.print(c); // optional: repeat back what I got for debugging

    // store the byte as long as there's room in the buffer.
    // if the buffer is full some data might get lost
    if(sofar < MAX_BUF) buffer[sofar++]=c;
    // if we got a return character (\n) the message is done.
    if(c=='\n') {
      Serial.print(F("\r\n")); // optional: send back a return for debugging

      // strings must end with a \0.
      buffer[sofar]=0;
      processCommand(); // do something with the command
      ready();
    }
  }
}
*/


