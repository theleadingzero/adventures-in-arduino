/* Printing Messages Example
   Written by Becky Stewart
   For Adventures in Arduino, Wiley (2015)
   
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

void setup() {
  // to start serial communication
  // the argument needs to match
  // the rate you choose in the 
  // Serial Monitor
  Serial.begin(9600);
  Serial.println("Hello, this is from setup");
  
  // a delay so that messages aren't too quick to read
  delay(3000);
}

void loop() {
  // printing a message and then waiting a second
  Serial.print("This is from loop, with a print. ");
  delay(1000);
  Serial.println("And this is from loop with a println.");
  delay(1000);
  
  int myVariable = 27;
  Serial.print("And this is printing a variable: ");
  Serial.println(myVariable);
  delay(1000);
}
   
