/*
Experiment No.   :   04
Statement        :   Fade and brighten 5 LEDs alternatively.
Date of Exp.     :   xx/xx/xxxx
Author           :   Tushar Rawte (A-06)
*/

const int led[5] = {2, 3, 4, 5, 6}; // Define the pins for LEDs

void setup() {
  for (int i = 0; i < 5; i++) { // Set all LED pins as outputs
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // Fade in
  for (int i = 0; i < 5; i++) {
    for (int brightness = 0; brightness <= 255; brightness+=5) { // Increase brightness gradually
      analogWrite(led[i], brightness);
      delay(10); // Delay between brightness changes
    }
  }

  // Fade out
  for (int i = 4; i >= 0; i--) {
    for (int brightness = 255; brightness >= 0; brightness-=5) { // Decrease brightness gradually
      analogWrite(led[i], brightness);
      delay(10); // Delay between brightness changes
    }
  }
}
