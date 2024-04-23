#include <Servo.h>

const int pirPin = 9; // PIR on D7
const int buttonPin = 4; // Button on D4
const int servoPin = 5; // Servo Motor on D5
const int LEDPin = 1; // LED on D2

Servo myservo;

int pirState = LOW;
int buttonState = LOW; // Current state of the button
int lastButtonState = LOW; // Previous state of the button
bool toggleState = false; // Toggle state for servo position
bool isPirActive = false; // Indicates if the PIR sensor has recently activated the servo

// Servo positions
int upPosition = 95; // Adjust to servo's up position
int downPosition = 10; // Adjust to servo's down position

unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50; // time for user to release button

unsigned long pirActivatedTimestamp = 0; // Timestamp of when the PIR sensor last activated the servo
const long pirActivationDuration = 9500; // Duration to keep the servo in the up position after PIR activation

// New variables for PIR debounce
unsigned long lastPirEvent = 0; // Last time a PIR event was recorded
unsigned long pirDebounceDelay = 4500; // Delay to debounce PIR sensor

unsigned long currentMillis;
unsigned long upTime;
bool up = false;

void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  myservo.attach(servoPin);
  myservo.write(downPosition);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDPin, LOW); // Initially, the LED is off
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        // Check if PIR had recently activated the servo
        if (isPirActive) {
          // Override PIR activation
          myservo.write(downPosition);
          digitalWrite(LEDPin, LOW); // Turn LED off
          up = false;
          isPirActive = false; // Reset PIR activation flag
        } else {
          // Toggle servo position normally
          toggleState = !toggleState;
          if (toggleState) {
            myservo.write(upPosition);
            digitalWrite(LEDPin, HIGH); // Turn LED on
            up = true;
            upTime = currentMillis;
          } else {
            myservo.write(downPosition);
            digitalWrite(LEDPin, LOW); // Turn LED off
            up = false;
          }
        }
      }
    }
  }

  // // Check if the switch is up and it's been 10 seconds
  // if (up && (currentMillis - upTime >= 11000)) {    
  //   myservo.write(downPosition); // Move the switch down
  //   digitalWrite(LEDPin, LOW); // Turn LED off
  //   up = false;
  // }

  lastButtonState = reading;

  // Handle PIR sensor activation with debounce
  pirState = digitalRead(pirPin);
  currentMillis = millis();

  Serial.print("PIR");
  Serial.println(pirState);

  Serial.print("Current");
  Serial.println(currentMillis);

  Serial.print("pirActivated");
  Serial.println(pirActivatedTimestamp);

  if (pirState == HIGH && currentMillis - lastPirEvent > pirDebounceDelay) {
    if (!toggleState) {
      myservo.write(upPosition);
      digitalWrite(LEDPin, HIGH); // Turn LED on
      pirActivatedTimestamp = currentMillis;
      isPirActive = true; // Set PIR activation flag
    }
    lastPirEvent = currentMillis;
  } else if (currentMillis - pirActivatedTimestamp > pirActivationDuration && !toggleState && isPirActive) {
    // Automatically return to down position after duration, if not manually overridden
    myservo.write(downPosition);
    digitalWrite(LEDPin, LOW); // Turn LED off
    isPirActive = false; // Reset PIR activation flag
  }
}
