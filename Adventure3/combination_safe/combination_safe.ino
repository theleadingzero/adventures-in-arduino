/* Combination Safe
 Written by Becky Stewart
 For Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 3 10 kOhm potentiometers
 * pushbutton
 * servo
 
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

#include <Servo.h>

// Pins
int potPin1 = A0;
int potPin2 = A1;
int potPin3 = A2;
int buttonPin = 7;
int servoPin = 9;

// other variables
int open1 = 0;
int open2 = 1023;
int open3 = 0;
int range = 10;
int boxOpen = 0;
Servo servo;

void setup() {
  // set button pin to be an input with 
  // with pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // attach servo to pin
  servo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  servo.write(90); // start with the box closed
  Serial.begin(9600); //start serial communication
}

void loop() {
  // check if button is pressed
  int buttonValue = digitalRead(buttonPin);

  // if button is pressed and box is closed
  if(buttonValue == 0 && boxOpen == 0) {
    // button is pressed
    int potValue1 = analogRead(potPin1);
    int potValue2 = analogRead(potPin2);
    int potValue3 = analogRead(potPin3);

    Serial.print("pot 1: ");
    Serial.print(potValue1);
    Serial.print(" pot 2: ");
    Serial.print(potValue2);
    Serial.print(" pot 3: ");
    Serial.println(potValue3);

    // if all values are within correct range
    if(potValue1 < (open1+range)  && 
      potValue1 > (open1-range) &&
      potValue2 < (open2+range)  && 
      potValue2 > (open2-range) &&
      potValue3 < (open3+range)  && 
      potValue3 > (open3-range)
      ) {

      // open the box
      Serial.println("opening");
      for(int pos = 90; pos > 0; pos -= 1)
      {  
        servo.write(pos); 
        delay(15);   
      }
      boxOpen = 1; 
    }
  } 
  // if button is pressed and box is open
  if(buttonValue==1 && boxOpen==1) {
    Serial.println("closing ");

    // close the box
    for(int pos = 0; pos < 90; pos+=1)
    {                                
      servo.write(pos);      
      delay(15);                       
    } 
    boxOpen = 0;
  }
}





