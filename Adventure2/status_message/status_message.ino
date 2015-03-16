/* Status Message
 Written by Becky Stewart
 For Adventures in Arduino, Wiley (2015)

 Hardware:
 * 10kOhm potentiometer
 * 3 LEDs (green, yellow, red)
 * 3 220 Ohm resistors


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

// Pins
int potPin = A0;
int greenLED = 5;
int yellowLED = 6;
int redLED = 7;

void setup() {
  // set to output to LED pins
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // start serial
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);

  // print what the pot value is
  Serial.print("Potentiometer is: ");
  Serial.println(potValue);

  // if pot is less than 341
  if(potValue < 341) {
     Serial.println("Turn on green, turn off yellow and red");
    // turn on green LED
    digitalWrite(greenLED, HIGH);

    //turn off yellow and red LEDs
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }

  // if pot more than or equal to 341 and 
  // less than 682
  if(potValue >= 341 && potValue < 682) {
    Serial.println("Turn on yellow, turn off green and red");
    // turn on yellow LED
    digitalWrite(yellowLED, HIGH);

    // turn off green and red LEDs
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
  }

  // if pot more than or equal to 682
  if(potValue >= 682) {
     Serial.println("Turn on red, turn off green and yellow.");
    // turn on red LED
    digitalWrite(redLED, HIGH);

    // turn off green and yellow LEDs 
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
  }
}

