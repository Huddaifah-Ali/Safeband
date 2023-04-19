const int xPin = A0; // X axis of accelerometer connected to A0
const int yPin = A1; // Y axis of accelerometer connected to A1
const int zPin = A2; // Z axis of accelerometer connected to A2

const int ledPin = 13; // LED connected to pin 13
const int buzzerPin = 9; // Buzzer connected to pin 9
const int buttonPin = 2; // Button connected to pin 2

int xZero, yZero, zZero; // Calibrated zero values for X, Y, and Z axes
int xAcc, yAcc, zAcc; // Acceleration values for X, Y, and Z axes

void setup() {
  pinMode(ledPin, OUTPUT); // set LED pin as output
  pinMode(buzzerPin, OUTPUT); // set buzzer pin as output
  pinMode(xPin, INPUT); // set X axis pin as input
  pinMode(yPin, INPUT); // set Y axis pin as input
  pinMode(zPin, INPUT); // set Z axis pin as input
  pinMode(buttonPin, INPUT_PULLUP); // set button pin as input with internal pull-up resistor
  Serial.begin(9600); // initialize serial communication

  // Calibrated zero values (use the code in the previous answer to calibrate the accelerometer)
  xZero = 1.21;
  yZero = 1.20;
  zZero = 1.46;
}

void loop() {
  // Read acceleration values
  xAcc = analogRead(xPin) - xZero;
  yAcc = analogRead(yPin) - yZero;
  zAcc = analogRead(zPin) - zZero;

  // Check if the accelerometer detects sudden movement or button is pressed
  if (abs(xAcc) > 100 || abs(yAcc) > 100 || abs(zAcc) > 100 || digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin, HIGH); // turn on the LED
    tone(buzzerPin, 1000); // play a tone on the buzzer
    delay(5000); // wait for 5 seconds
    digitalWrite(ledPin, LOW); // turn off the LED
    noTone(buzzerPin); // stop
  } else {
    digitalWrite(ledPin, LOW); // turn off the LED
    noTone(buzzerPin); // stop the buzzer
  }
}
