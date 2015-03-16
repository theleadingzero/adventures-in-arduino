/*Array of LEDs
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 6 LEDs
 * 6 220 Ohm resistors
 
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

// pins for leds
int[] ledList = {
  3, 4, 5, 6, 7, 8};
// number of pins
int numPins = 6;

void setup() {
  int i;
  for( i=0; i<numPins; i++ ){
    // set pins to OUTPUT
    pinMode(ledList[i], OUTPUT);
  }
}

void loop() {
  // blink the LEDs one by one
  int i;
  for(i=0; i<numPins; i++) {
    // turn on the led
    digitalWrite(ledList[i], HIGH);
    delay(500);

    // turn off the led
    digitalWrite(ledList[i], LOW);
    delay(500);
  }
}



