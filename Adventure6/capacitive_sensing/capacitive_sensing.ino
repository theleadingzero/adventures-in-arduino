/*Capactive Sensing
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 2 10M Ohm resistors

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

// capSense pins
int sensorPin = 2;
int outputPin = 4;

CapacitiveSensor handSensor = CapacitiveSensor(outputPin, sensorPin);

void setup() {
  // begin serial communication
  Serial.begin(9600);
}

void loop() {
  // read in the value from the sensor
  long sensorValue =  handSensor.capacitiveSensor(30);
  // print the value
  Serial.println(sensorValue);

  // wait for a short while before continuing
  delay(10);
}





