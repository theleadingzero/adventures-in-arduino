/*Big Adventure Marble Maze Game Part 1, First Section
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 6 piezos
 * 6 10 MOhm resistors

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

// variables for pins
int pointsPins[] = {
  A0, A1, A2, A3, A4};

// number of piezos for points
int numPointsPins = 5;

//---setup---------------------------
// runs once when board first powered
// or reset
void setup() {
  // start serial communication
  Serial.begin(9600);
}

//---loop----------------------------
// runs continuously after setup()
void loop() {
  int i;
  for( i=0; i<numPointsPins; i++ ) {
    int currPinValue = analogRead(pointsPins[i]);

    // if above the threshold
    if( currPinValue > piezoThreshold ){
      // print points and new score
      Serial.print("Piezo: ");
      Serial.print(i);
      Serial.println(" Value:");
      Serial.print(currPinValue);

      // pause so that same marble doesn't score twice
      delay(300);
    }
  }
}

