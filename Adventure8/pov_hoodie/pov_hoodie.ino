/*Persisiene of Vision Hoodies
 by Becky Stewart
 for Adventures in Arduino, Wiley (2015)
 
 Hardware:
 * 7 Lilypad LEDs

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


#include "alphabet.h"


int letterSpace = 9; // time LEDs off between letters
int dotTime = 3; // time LEDs are on

int ledPins[] = {
  2, 3, 9, 10, 11, A2, A3};


//---------------------------------------------
// setup
// runs once when first powered or reset
//---------------------------------------------
void setup()
{
  // set pin modes to OUTPUT
  int i;
  for(int i=0; i<numLEDs; i++) {
    pinMode( ledPins[i], OUTPUT); 
  }

  Serial.begin(9600);
}

//---------------------------------------------
// loop
// runs continuously after set up
//---------------------------------------------
void loop()
{
  String message = "HELLO    "; // put message in all caps here
  printText(message);
}

//---------------------------------------------
// printLetter
// displays letter on LEDs
//---------------------------------------------
void printLetter(int letter[numFrames][numLEDs])
{
  int frame;
  int led;

  // print letter
  for( frame=0; frame<numFrames; frame++ ) {
    for( led=0; led<numLEDs; led++ ) {
      digitalWrite( ledPins[led], letter[frame][led] );
      Serial.print(letter[frame][led]);
    } 
    Serial.println();
    // delay between each column displayed
    delay(dotTime);
  }
  Serial.println("-------");

  // print space after letter
  for( led=0; led<numLEDs; led++ ) {
    digitalWrite( ledPins[led], 0 );
  } 
  // delay for space between letters
  delay(letterSpace);
}

//---------------------------------------------
// printText
// takes String message and breaks it up 
// into letters
//---------------------------------------------
void printText(String text)
{
  // go through message, letter by letter
  for (int i=0; i<text.length(); i++)
  {
    switch(text[i])
    {
    case 'A':
      printLetter(A);
      break;
    case 'B':
      printLetter(B);
      break;
    case 'C':
      printLetter(C);
      break;
    case 'D':
      printLetter(D);
      break;
    case 'E':
      printLetter(E);
      break;
    case 'F':
      printLetter(F);
      break;
    case 'G':
      printLetter(G);
      break;
    case 'H':
      printLetter(H);
      break;
    case 'I':
      printLetter(I);
      break;
    case 'J':
      printLetter(J);
      break;
    case 'K':
      printLetter(K);
      break;
    case 'L':
      printLetter(L);
      break;
    case 'M':
      printLetter(M);
      break;
    case 'N':
      printLetter(N);
      break;
    case 'O':
      printLetter(O);
      break;
    case 'P':
      printLetter(P);
      break;
    case 'Q':
      printLetter(Q);
      break;
    case 'R':
      printLetter(R);
      break;
    case 'S':
      printLetter(S);
      break;
    case 'T':
      printLetter(T);
      break;
    case 'U':
      printLetter(U);
      break;
    case 'V':
      printLetter(V);
      break;
    case 'W':
      printLetter(W);
      break;
    case 'X':
      printLetter(X);
      break;
    case 'Y':
      printLetter(Y);
      break;
    case 'Z':
      printLetter(Z);
      break;
    case ' ':
      printLetter(_);
      break;
    default:
      break;
    }
  }
}







