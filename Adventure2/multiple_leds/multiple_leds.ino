/* Multiple LEDs
 Written by Becky Stewart
 For Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 3 LEDs (green, yellow, red)
 * 3 220 Ohm resistors
 
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

// Pins
int greenLED = 5;
int yellowLED = 6;
int redLED = 7;

void setup() {
  // set to output to LED pins
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // turn on all LEDs
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, HIGH);

  // wait 1 second
  delay(1000);
  
  // turn off all LEDs
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW); 
  
  //wait 1 second
  delay(1000);
}




