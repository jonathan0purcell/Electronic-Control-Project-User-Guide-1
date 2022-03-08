/*
  Digital Input

  Reads in the input from Pin 2 which is connected to a pushbutton
  and displays whether it is being pressed or not.
  
  When the pushbutton is pressed, a signal will be send to pin 2 
  which can then be read by the program. If the pin is not being 
  pushed then there will not be any signal sent to the pin.

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/3V39ptcAnx8 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// Define the pin number for the pushbutton
#define PB_PIN 2

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize the digital pushbutton pin as an input.
  pinMode(PB_PIN, INPUT); 

  // Begins the serial communication with the baud rate of 9600 b/s
  Serial.begin(9600);
}

// The loop function runs over and over again forever
void loop() {
  // Reads the input from PB_PIN (2) and shows if it's being pressed
  if (digitalRead(PB_PIN)){
    Serial.println("The pushbutton is being pressed!");
  } else {
    Serial.println("The pushbutton is not being pressed...");
  }

  delay(1000);
}
