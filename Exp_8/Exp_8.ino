/*
Experiment No.   :   08
Statement        :   Turn ON/OFF five LEDs individually via serial monitor window.
Date of Exp.     :   xx/xx/xxxx
Author           :   Tushar Rawte (A-06)
*/

const int ledPins[5] = {2, 3, 4, 5, 6};  // Pins connected to the LEDs

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set LED pins as outputs
    digitalWrite(ledPins[i], LOW); // Initially turn off all LEDs
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  char key;
  if(Serial.available()>0)
  key = Serial.read();
  int index = key -'1';  // Convert the character command to LED index
  switch(key){
    case '1':
      digitalWrite(ledPins[index], !digitalRead(ledPins[index])); // Toggle the LED state
      break;
      
    case '2':
      digitalWrite(ledPins[index], !digitalRead(ledPins[index])); // Toggle the LED state
      break;

    case '3':
      digitalWrite(ledPins[index], !digitalRead(ledPins[index])); // Toggle the LED state
      break;
      
    case '4':
      digitalWrite(ledPins[index], !digitalRead(ledPins[index])); // Toggle the LED state
      break;

    case '5':
      digitalWrite(ledPins[index], !digitalRead(ledPins[index])); // Toggle the LED state
      break;
  }
  delay(10);
}

