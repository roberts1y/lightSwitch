int ledPin = 13;  // LED connected to digital pin 13
int pirPin = 2;   // PIR sensor connected to pin 2
int pirState = LOW;  // Initializing the PIR state
unsigned long lastMotionTime = 0;  // Time when the last motion was detected

void setup() {
  pinMode(ledPin, OUTPUT);  // Initialize the LED pin as an output
  pinMode(pirPin, INPUT);   // Initialize the PIR sensor pin as an input
  Serial.begin(9600);       // Start serial communication
}

void loop() {
  int sensorValue = digitalRead(pirPin); // Read the value from the PIR sensor

  if (sensorValue == HIGH) {
    lastMotionTime = millis();  // Update the last motion time
    if (pirState == LOW) {
      // PIR state is changed to HIGH
      Serial.println("Motion detected!");
      pirState = HIGH;
      digitalWrite(ledPin, HIGH);  // Turn the LED on
    }
  } 

  if (millis() - lastMotionTime > 1000) {  // Check if it has been 1 second since last motion
    if (pirState == HIGH){
      // PIR state is changed to LOW
      Serial.println("Motion ended!");
      pirState = LOW;
      digitalWrite(ledPin, LOW);  // Turn the LED off
    }
  }
}