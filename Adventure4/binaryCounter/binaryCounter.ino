/*Binary Counter
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 74HC595 shift register attached to pins 2, 3, and 4 of the Arduino,
 as detailed below.
 * 8 LEDs attached to each of the outputs of the shift register
 * 8 220 Ohm resistors
 
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

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // loop through 0 to 8
  //  turning on one LED
  int i;
  for(i=0; i<256; i++) {
    // turn off the output so the pins don't light up
    // while you're shifting bits:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, i);

    // turn on the output so the LEDs can light up:
    digitalWrite(latchPin, HIGH);
    delay(300);
  }
}


