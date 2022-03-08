/*
  Ohmmeter

  The Arduino will acts as a handheld Ohmmeter which can calculate
  the resistance of any given resistor using a voltage divider
  and the known resistance of another resistor.

                             +5V
                              ||
                              R1
                              ||
                              |+--- Analog Pin (Arduino)
                              ||
                              R2
                              ||
                              0V

  Ohm's Law states that the resistance of a resistor is equal to
  the voltage across that resistor over the current through the 
  resistor. 

  We are able to get the voltage reading of the second resistor
  through the analog pin of the arduino. As for the current, since
  we have the resistance of the first resistor and the voltage from
  the analog pin to ground (0V), we can calculate the voltage across
  the first resistor (+5V minus the analog pin voltage reading) and 
  get the current by dividing voltage across resistor one by the resistance
  of resistor 1.
 
  The wiring for this project can be found at:
  https://www.tinkercad.com/things/czjNNsYVvI5 

  Created 7 May 2022
  by Jonathan Purcell

  This code, among others, can be found in my GitHub repository:
  https://github.com/jonathan0purcell/Electronic-Control-Project-User-Guide-1.git
*/

#include <LiquidCrystal.h>  // To use the LCD need to include the library

// Defines the maximum and minimum values for serial analog reading
#define ANALOG_MIN 0
#define ANALOG_MAX 1023

// Defines the maximum and minimum values for arduino voltage
#define GROUND 0
#define SOURCE_VOLTAGE 5

// Define the pin number for the LED that we will be turning on and off
#define V2_PIN A0

// Variables of the circuit
const float R1 = 220;  // Resistor 1 is equal to 220 Ohms
float R2;              // Unknown, this is what we're trying to find
float v2Serial;        // Will store the serial analog reading
float V2;              // Will store the (mapped) voltage reading
float V1;              // The voltage across resistor one
float current;         // The current in the circuit

/* LCD pins and their connections
 * VSS to GND
 * VDD to +5V
 * V0 to ground (connect to potentiometer or resistor to dim the whiteness on the squares)
 * RS to pin 12
 * RW to GND
 * E to pin 11
 * D3 to pin 5
 * D4 to pin 4
 * D5 to pin 3
 * D6 to pin 2
 * A to +5V (Anode)
 * K to GND (Kathode) */

const int LCD_RS = 12;  // Reset pin
const int LCD_E = 11;   // Enable Pin
const int LCD_D4 = 5;
const int LCD_D5 = 4;
const int LCD_D6 = 3;
const int LCD_D7 = 2;
LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Custom OHM symbol for the LCD (https://maxpromer.github.io/LCD-Character-Creator/)
byte customChar[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000,
  B00000
};

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize the serial communication with a baud rate of 9600 bps
  Serial.begin(9600);

  // LCD Configurations
  lcd.createChar(0, customChar);  // Creating the character for Ohm
  lcd.begin(16, 2);               // Set up the LCD's number of columns and rows
  lcd.print("Resistance (R2): "); // First row display
}

// Avoids cluttering in loop function and makes printing neater
void cleanPrint(const String pinTitle, const float pinValue, const String nl) {
  Serial.print(pinTitle);
  Serial.print(pinValue, 3);
  Serial.print(nl);
}

void calculateUnknownResistance(){
  // Get the serial voltage reading of the analog pin
  v2Serial = analogRead(V2_PIN);

  // Map the serial voltage reading (0-1023) to the arduino voltage (0-5)
  // Where 5/1023 is the mapping function which gives 0.00488758553
  V2 = (float) v2Serial * 0.00488758553;

  // Calculate the current across resistor one
  V1 = (float)(SOURCE_VOLTAGE-V2); // Voltage is equal to the source voltage minus V2
  current = (float) V1 / R1;       // Current is the voltage divided by the resistance

  // Calculate the resistor of the unknown resistor (R2)
  R2 = (float) V2 / current;
}

// The loop function runs over and over again forever
void loop() {
  // Printing the values on LCD
  lcd.print("                ");  // 'Clearing' the line
  lcd.setCursor(0, 1);            // Sets the cursor to the second row, first character
  lcd.print(R2);                  // Prints the resistance in the second row
  lcd.write(byte(0));             // Prints the ohm resistance
  
  // Printing the values on serial
  cleanPrint("Analog Serial:  ", v2Serial, "\n");
  cleanPrint("Analog Voltage: ", V2, "V\n");
  cleanPrint("Current: ", current*1000, "mA\n");        // Printing the current in mA
  cleanPrint("Unknown Resistance: ", R2, "Ω\n\n");

  // Pause the program for 500 milliseoncds before continue
  delay(500);
}
