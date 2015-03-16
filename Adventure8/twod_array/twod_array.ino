/*LEDs in 2D Array
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 5 LEDs
 * 5 220 Ohm resistors

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

// const means the value won't change
const int numLEDs = 5;
const int numFrames = 9;

// pins that have LEDs
int ledPins[] = {
  2, 3, 9, 10, 11};

// frames of the animation
int frames[numFrames][numLEDs] = 
{
  {1, 0, 0, 0, 0}, 
  {0, 1, 0, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 0, 1, 0},
  {0, 0, 0, 0, 1},
  {0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0}};

void setup()
{
  // set pin modes to OUTPUT
  int i;
  for(int i=0; i<numLEDs; i++) {
    pinMode( ledPins[i], OUTPUT); 
  }
}

void loop()
{
  // variables to keep track of current frame and LED
  int frame;
  int led;
  for( frame=0; frame<numFrames; frame++ ) {
    // iterate through each frame stored in a row
    for( led=0; led<numLEDs; led++ ) {
      // turn on or off the each LED in the frame
      digitalWrite( ledPins[led], frames[frame][led] );
    } 
    delay(300); // pause between each frame
  }
}



