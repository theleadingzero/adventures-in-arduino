/*Leonardo Acting as a Keyboard
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)

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

int switchPin = 4;          // input pin for switch

void setup() {
  // make the switchPin and input with a internal pullup resistor
  pinMode(switchPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int switchState = digitalRead(switchPin);

  // if the switch is open (not connected to ground), 
  if (switchState == LOW) {
    Keyboard.println("This is your Leonardo acting like a keyboard.");    
  }
  delay(500);
}




