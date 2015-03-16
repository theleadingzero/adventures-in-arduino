/*Crystal Ball
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 2 10M Ohm resistors
 * 1 RGB LED with a common cathode

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

#include <CapacitiveSensor.h>


// LED pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// capSense pins
int sensorPin = 2;
int outputPin = 4;

// touch threshold
int threshold = 1000;

CapacitiveSensor handSensor = CapacitiveSensor(outputPin, sensorPin);

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long sensorValue =  handSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  // if above the threshold
  if(sensorValue > threshold) {

    // calculate color value based on sensor reading
    int redValue = map(sensorValue, threshold, 90000, 0, 255);
    int greenValue = map(sensorValue, threshold, 20000, 0, 255);
    int blueValue = map(sensorValue, threshold, 30000, 0, 255);

    // turn on led
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
  } 
  else{
    // otherwise turn off led
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
