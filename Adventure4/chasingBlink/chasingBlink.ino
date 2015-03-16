/*Chasing Blink
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 3 74HC595 shift register attached to pins 8, 11, and 12 of the Arduino,
 as detailed below.
 * 24 LEDs attached to each of the outputs of the shift register
 * 24 220 Ohm resistors
 
 Adapted from
 Shift Register Examples
 for 74HC595 shift register
 
 by Tom Igoe and Carlyn Maw  
 
 
Copyright 2015 Becky Stewart

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

//Pin connected to latch pin (ST_CP) of 74HC595
int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
int clockPin = 12;
//Pin connected to Data in (DS) of 74HC595
int dataPin = 11;

// number of shift registers used
int numRegisters = 3;

// first pattern to be displayed
int pattern1 = 85;
// second pattern to be displayed
int pattern2 = 170;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  // start with all LEDs off
  setLEDs(0);
}

void loop() {
  // turn on LEDs in the pattern 01010101
  setLEDs(pattern1);
  // wait 1 sec
  delay(1000);
  // turn on LEDs in the pattern 10101010
  setLEDs(pattern2);
  // wait 1 sec
  delay(1000);
}

// sends pattern to shift register for
// which LEDs to turn on and off
void setLEDs(int lightPattern) {
  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);
  
  int i;
  for(i=0; i<numRegisters; i++) {
    // sends out the pattern once for each shift register
    shiftOut(dataPin, clockPin, LSBFIRST, lightPattern);
  }

  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);
  delay(300);
}
