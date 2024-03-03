/*
Experiment No.	:	02
Statement		    :	Make experiment 1 work with two switches. One switch press would result running of
LEDs in one direction, while the second switch press would result running of LEDs in
opposite direction.
Date of Exp.	  :	xx/xx/xxxx
Author		      :	Tushar Rawte (A-06)
*/

const int led[5] = {2 , 3 , 4, 5, 6}; // Define the pins for LEDs using array
const int switch1Pin = 8; // Pin for the first switch
const int switch2Pin = 9; // Pin for the second switch

void setup() {
  for (int i = 0; i < 5; i++) { // Set all LED pins as outputs
    pinMode(led[i], OUTPUT);
  }
  pinMode(switch1Pin, INPUT_PULLUP); // Set switch1Pin as input with internal pull-up resistor
  pinMode(switch2Pin, INPUT_PULLUP); // Set switch2Pin as input with internal pull-up resistor
}

void loop() {

  if (digitalRead(switch1Pin) == LOW) {
    for (int i = 0; i < 5; i++) { // Run the lights from left to right
      digitalWrite(led[i], HIGH); // Turn the led ON
      delay(150); // Delay for led
      digitalWrite(led[i], LOW); // Turn the led OFF
    }
  }

  if (digitalRead(switch2Pin) == LOW) {
      for (int i = 4; i >= 0; i--) { // Run the lights from right to left
      digitalWrite(led[i], HIGH); // Turn the led ON
      delay(150); // Delay for led
      digitalWrite(led[i], LOW);  // Turn the led OFF
    }
  }
}

