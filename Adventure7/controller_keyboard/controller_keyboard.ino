/*Game Controller
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 4 light dependent resistors
 * 4 10 kOhm resistors

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

int switchPin = 4;
int leftSensor = A0;
int rightSensor = A1;
int upSensor = A2;
int downSensor = A3;

// adjust these variables to values that 
// work for your controller
int rightThreshold = 400;
int leftThreshold = 400;
int upThreshold = 400;
int downThreshold = 400;

void setup() {
  // make the switchPin and input with an internal pull-up resistor
  pinMode(switchPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int switchState = digitalRead(switchPin);
  // if the switch is open (not connected to ground), 
  if (switchState == LOW) {
    // RIGHT ARROW
    int rightValue = analogRead(rightSensor);
    //Serial.println(rightValue);
    if(rightValue > rightThreshold) {
      Keyboard.press(KEY_RIGHT_ARROW);
    }
    
    // LEFT ARROW
    int leftValue = analogRead(leftSensor);
    //Serial.println(leftValue);
    if(leftValue > leftThreshold) {
      Keyboard.press(KEY_LEFT_ARROW);
    }
    
    // UP ARROW
    int upValue = analogRead(upSensor);
    //Serial.println(upValue);
    if(upValue > upThreshold) {
      Keyboard.press(KEY_UP_ARROW);
    }

    // DOWN ARROW
    int downValue = analogRead(downSensor);
    //Serial.println(downValue);
    if(downValue > downThreshold) {
      Keyboard.press(KEY_DOWN_ARROW);
    }
  }
  
  delay(50);
  Keyboard.releaseAll();
}



