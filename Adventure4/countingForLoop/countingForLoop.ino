/* Counting for Loop
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
  Serial.begin(9600);
}

void loop() {
  int i;
  for(i=0; i<10; i++){ // for loop that counts from 0 to 9
    Serial.println(i); // print the current value of i
    delay(1000); // wait for 1 second
  } 
  delay(3000); // wait for 3 seconds
}

