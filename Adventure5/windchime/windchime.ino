/* Wind Chimes 
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 1 piezo
 * 5 momentary switches

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

int chimes[] = {
  3, 4, 5, 6, 7}; // array of pins for chimes
int numChimes = 5; // total number of chimes
int piezoPin = 8; // pin for piezo

void setup(){
  int i;
  // set pinMode on all the chimes pins
  for(i=0; i<numChimes; i++) {
    pinMode(chimes[i], INPUT_PULLUP);
  }
}

void loop(){
  int i;
  for(i=0; i<numChimes; i++) {
    // read in value on pin
    int value = digitalRead(chimes[i]);
    // if LOW (meaning it has connected to ground
    if(value == LOW) {

      // play the sound
      tone(piezoPin, (100*i)+200, 30);
      delay(1);
    }
  }
}

