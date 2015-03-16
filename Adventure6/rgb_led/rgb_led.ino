/*RGB LED
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 3 220 Ohm resistors
 * 1 Common cathode RGB LED

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

// LED Pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  // set pins to OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // red
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(redPin, fadeValue);            
    delay(30);                            
  } 

  for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5) {
    analogWrite(redPin, fadeValue);          
    delay(30);                            
  } 

  // green
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(greenPin, fadeValue);           
    delay(30);                            
  } 

  for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(greenPin, fadeValue);          
    delay(30);                            
  } 

  // blue
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(bluePin, fadeValue);          
    delay(30);                            
  } 

  for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(bluePin, fadeValue);          
    delay(30);                            
  } 

  // blue + increasing red
  digitalWrite(bluePin, HIGH);
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(redPin, fadeValue);          
    delay(30);                            
  } 
  // turn blue off again
  digitalWrite(bluePin, LOW);

  // green + increasing red
  digitalWrite(greenPin, HIGH);
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(redPin, fadeValue);          
    delay(30);                            
  } 
  // turn green off again
  digitalWrite(greenPin, LOW); 
  // turn off red
  digitalWrite(redPin, LOW); 

  // blue + increasing green
  digitalWrite(bluePin, HIGH);
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(greenPin, fadeValue);          
    delay(30);                            
  } 
  // turn blue off again
  digitalWrite(bluePin, LOW); 
  // turn off green
  digitalWrite(greenPin, LOW); 


  // turn all on to make white
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);

  delay(2000);

  // turn all off
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}
