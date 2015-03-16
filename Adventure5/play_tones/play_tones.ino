/* Play Tones 
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 1 piezo

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

int piezoPin = 8;

void setup() {
  // play 3 tones when the board first starts
  tone(piezoPin, 523, 200);
  // delay is slightly longer than tone 
  // so that there is silence in between the sounds
  delay(210);
  
  tone(piezoPin, 784, 200);
  delay(210);
  
  tone(piezoPin, 1047, 250);
  delay(260);
}

void loop() {
  // play 5 more tones
  tone(piezoPin, 523, 200);
  delay(210);
  
  tone(piezoPin, 587, 200);
  delay(210);
  
  tone(piezoPin, 659, 200);
  delay(210);
  
  tone(piezoPin, 698, 200);
  delay(210);
  
  tone(piezoPin, 784, 200);
  
  // wait 5 seconds before starting the loop over
  delay(5000);
}


