/*
  RGB Potentiometer

  Changes the red green blue (RGB) LED based on the potentiometer value
  as seen below:

   ON     OFF    OFF
    _      _      _
  ( R )  ( G )  ( B )   If the potentiometer is between 0 and 0.33 of max value
   | \    | \    | \

   OFF    ON     OFF
    _      _      _
  ( R )  ( G )  ( B )   If the potentiometer is between 0.33 and 0.66 of max value
   | \    | \    | \

   OFF    OFF    ON
    _      _      _
  ( R )  ( G )  ( B )   If the potentiometer is between 0.66 and it's max value
   | \    | \    | \

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/7IyNhV3EAhh 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// The minimum (OFF) and maximum (ON) values of the PWM duty cycle
#define PWM_MIN 0
#define PWM_MAX 255

// The minimum and maximum values for the potentiometer reading
#define ANALOG_MIN 0
#define ANALOG_MAX 1023

// Define the R, G and B digital PWM pins for the LED
#define LED_PIN_R 6
#define LED_PIN_G 5
#define LED_PIN_B 3

// Define the potentiometer analog pin
#define A_POT_PIN A0

// Variable for the serial readings of the analog pin
int serial_pot_val;

// Variable that decides the current color to show
int RGB_selection;

// The setup function runs once when you press reset or power the board
void setup() {
  // Set the pinMode of R,G and B pins as OUTPUT
  pinMode(LED_PIN_R, OUTPUT);
  pinMode(LED_PIN_G, OUTPUT);
  pinMode(LED_PIN_B, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
  // Read the serial analog value of the potentiomer pin (0-1023)
  serial_pot_val = analogRead(A_POT_PIN);

  // Depending on the mapped value, the RGB LED will either show R, G or B
  RGB_selection = map(serial_pot_val, ANALOG_MIN, ANALOG_MAX, 0, 2);

  switch (RGB_selection) {
    // Potentiometer is less than 0.33*ANALOG_MAX, so display 'Red'
    case 0:
      analogWrite(LED_PIN_R, ANALOG_MAX);
      break;
    // Potentiometer is greater than 0.33*ANALOG_MAX and is 
    // less than 0.66*ANALOG_MAX, so display 'Green' 
    case 1:
      analogWrite(LED_PIN_G, ANALOG_MAX);
      break;
    // Potentiometer is greater than 0.66*ANALOG_MAX, so display 'Blue'  
    case 2:
      analogWrite(LED_PIN_B, ANALOG_MAX);
      break;
  }

  // Wait 100ms before restarting the loop
  delay(100);
}
