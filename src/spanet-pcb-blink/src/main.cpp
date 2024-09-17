#include <Arduino.h>

// Define the GPIO pin for the LED
const int ledPin = 14;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);
  // Add a small delay to ensure serial communication is initialized
  delay(1000);
  // Print a test message
  Serial.println("Serial communication initialized");
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  // Print message to serial monitor
  Serial.println("LED is ON");
  // Wait for 1000 milliseconds
  delay(1000);
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  // Print message to serial monitor
  Serial.println("LED is OFF");
  // Wait for 1000 milliseconds
  delay(1000);
}