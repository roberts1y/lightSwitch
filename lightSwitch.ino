#include <Servo.h>

const int pirPin = 7; // PIR on D7
const int buttonPin = 6; // Button on D6
const int servoPin = 12; // Servo Motor on D12

Servo myservo; 

int pirState = LOW; 
int buttonState = LOW; // Current state of the button
int lastButtonState = LOW; // Previous state of the button
bool toggleState = false; // Toggle state for servo position

// Servo positions
int upPosition = 180; // Adjust to  servo's up position
int downPosition = 0; // Adjust to servo's down position

unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50; // time for user to release button

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(downPosition);
}

void loop() {
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        toggleState = !toggleState; // Toggle the state
        if (toggleState) {
          myservo.write(upPosition);
        } else {
          myservo.write(downPosition);
        }
      }
    }
  }

  lastButtonState = reading;

  // PIR sensor
  pirState = digitalRead(pirPin);
  if (pirState == HIGH) {
    myservo.write(upPosition); // Move servo to up position
    delay(5000); 
    if (!toggleState) { // If not manually overridden
      myservo.write(downPosition); // Move servo back to down position
    }
  }
}
