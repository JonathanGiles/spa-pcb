#include <Arduino.h>

#ifdef KNIGHT_RIDER_MODE
  const int pinCount = 4;
  const int ledPins[] = {14, 41, 42, 43};
#else
  const int pinCount = 1;
  const int ledPins[] = {14};
#endif

// check the boot button is on GPIO0
const int bootButton = 0;

void setup() {
  // Initialize the LED pins as an output
  for (int i = 0; i < pinCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize the boot button as an input
  pinMode(bootButton, INPUT_PULLUP);
  
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);

  // Add a small delay to ensure serial communication is initialized
  delay(1000);

  // Print a test message
  Serial.println("Serial communication initialized");
}

void loop() {
  #ifdef KNIGHT_RIDER_MODE
    // Knight Rider mode
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(100);
      digitalWrite(ledPins[i], LOW);
    }
    for (int i = pinCount - 1; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(100);
      digitalWrite(ledPins[i], LOW);
    }
  #else
    // Blink mode
    digitalWrite(ledPins[0], HIGH);
    delay(1000);
    digitalWrite(ledPins[0], LOW);
    delay(1000);
  #endif
  
  // Print message to serial monitor
  // Serial.println("LED is ON");
  
  // Wait for 1000 milliseconds
  // delay(1000);
  
  // Turn the LED off
  // digitalWrite(ledPin, LOW);
  
  // Print message to serial monitor
  // Serial.println("LED is OFF");

  // Check if the boot button is pressed
  if (digitalRead(bootButton) == LOW) {
    // Print message to serial monitor
    Serial.println("Boot button is pressed");
  }

  // // Wait for 1000 milliseconds
  // delay(1000);
}