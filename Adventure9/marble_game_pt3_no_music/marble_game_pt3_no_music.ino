/*Big Adventure Marble Maze Game, Part 3 with no music
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 3 LEDs (red, yellow, green)
 * 3 220 Ohm resistors
 * 6 piezos
 * 6 10 MOhm resistors
 * push button

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
int buttonPin = 7;
int greenLED = 4;
int yellowLED = 5;
int redLED = 6;
int speakerPin = 9;

// number of piezos for points
int numPointsPins = 5;

// when points triggered
int piezoThreshold = 800; 

//game timer variables
int maximumTime = 10000; 
long gameStartTime;
boolean playingGame = false;

// high score variables
boolean newHighScore = false;
int currentScore;
int highScore = 0;

//---setup---------------------------
// runs once when board first powered
// or reset
void setup() {
  // set up pin mode for button
  pinMode(buttonPin, INPUT_PULLUP);

  // set up pin modes for LEDs
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);


  // start serial communication
  Serial.begin(9600);

  // start countdown to start
  startGame();
}

//---loop----------------------------
// runs continuously after setup()
void loop() {
  // if playing a game and still within time
  if( (millis() - gameStartTime) < maximumTime ){
    // read in each points pin
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
        
        // pause so that same marble doesn't score twice
        delay(300);
      }
    }
  } 
  else{
    // else if playing a game but time has run out
    if( playingGame ){
      // end the game
      endGame();
    }
    // else if not playing a game
    else{
      // check if button has been pressed to start new game
      int buttonValue = digitalRead( buttonPin );
      if( buttonValue == 0) {
        // button is pressed, start new game
        startGame();
      }
    }
  }
}

//---startGame---------------------------
// sets up variables for a new game and starts
// countdown
void startGame() {
  // make sure all LEDs start off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.println("****NEW GAME****");
  Serial.print("Starting game in...");
  // turn on red LED
  digitalWrite(redLED, HIGH);
  Serial.print("ready...");
  delay(1000);
  // turn off red LED
  digitalWrite(redLED, LOW);

  // turn on yellow LED
  digitalWrite(yellowLED, HIGH);
  Serial.print("set...");
  delay(1000);
  // turn off yellow LED
  digitalWrite(yellowLED, LOW);

  Serial.println("go!");
  // turn on green LED
  digitalWrite(greenLED, HIGH);

  // start game timer
  gameStartTime = millis();
  // set flag that currently playing a game
  playingGame = true;
  // reset score
  currentScore = 0;
}


//---endGame---------------------------
// sets up variables for a new game and starts
// countdown
void endGame() {
  Serial.println("Game Over!");
  Serial.print("Score: ");
  Serial.println(currentScore);

  // turn off green LED
  digitalWrite(greenLED, LOW);

  // calculate high score
  if( currentScore > highScore ) {
    // if a new high score
    highScore = currentScore;
    Serial.println("New High Score!");
    newHighScore = true;
  } 
  else{
    // else new no high score
    newHighScore = false;
  }

  Serial.print("High Score is: ");
  Serial.println( highScore );
  Serial.println();

  // set flag that not currently playing a game
  playingGame = false;
}
