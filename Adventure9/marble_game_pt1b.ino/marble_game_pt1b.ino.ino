/*Big Adventure Marble Maze Game Part 1, Second Section
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

int speakerPin = 9;

// number of piezos for points
int numPointsPins = 5;

// when points triggered
int piezoThreshold = 800; 

int currentScore = 0;

void setup() {
  // start serial communication
  Serial.begin(9600);
}

void loop() {
  int i;
  for( i=0; i<numPointsPins; i++ ) {
    int currPinValue = analogRead(pointsPins[i]);
    
    // if above the threshold
    if( currPinValue > piezoThreshold ){
      // add points
      int newPoints = (i+1)*10;
      currentScore += newPoints;
      
      // print points and new score
      Serial.print("   Score! ");
      Serial.print(newPoints);
      Serial.println(" points");
      Serial.print("   Current score: ");
      Serial.print(currentScore);
      Serial.println(" points");

      // play scoring music
      tone(speakerPin, 659, 300);
      delay(300);

      // pause so that same marble doesn't score twice
      delay(300);
    }
  }
}
