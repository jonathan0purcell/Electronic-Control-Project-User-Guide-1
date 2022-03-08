/*
  LED Potentiometer Fade

  Fades in and out an LED based on the potentiometer value

  The wiring for this project can be found at:
  https://www.tinkercad.com/things/0UXshZXg26V

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

// The minimum (OFF) and maximum (255) values of the PWM duty cycle
#define PWM_MIN 0
#define PWM_MAX 255

// The minimum and maximum values for the potentiometer reading
#define ANALOG_MIN 0
#define ANALOG_MAX 1023

// Define the digital (PWM) pin number for the LED
#define LED_PIN 3

// Define the potentiometer analog pin
#define A_POT_PIN A0

// Variables for the serial and mapped readings of the analog pin
int serial_pot_val;
int mapped_pot_val;

// The setup function runs once when you press reset or power the board
void setup() {
  // Set the pinMode of LED_PIN as OUTPUT
  pinMode(LED_PIN, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
  // Read the serial analog value of the potentiomer pin (0-1023)
  serial_pot_val = analogRead(A_POT_PIN);

  // Map the serial reading (0-1023) to the PWM limits (0-255)
  mapped_pot_val = map(serial_pot_val, ANALOG_MIN, ANALOG_MAX, PWM_MIN, PWM_MAX);

  // Set the PWM duty cycle ("brightness") of the LED to the mapped pot. value
  analogWrite(LED_PIN, mapped_pot_val);
  
  // Wait 100ms before restarting the loop
  delay(100);
}
