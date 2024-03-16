#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Define the pins for the components
const int rainSensorPin = 8;  // Pin connected to the rain sensor output
const int ledPin = 13;         // Pin connected to the LED
const int servoPin = 9;        // Pin connected to the servo motor

// Create a Servo object to control the servo motor
Servo servoMotor;

// Set the LCD address and dimensions
const int lcdColumns = 16;
const int lcdRows = 2;
const int lcdAddress = 0x27; // Change this to your module's address

// Create an instance of the LiquidCrystal_I2C class
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

void setup() {
  // Initialize the LCD
  lcd.begin();
  lcd.backlight();

  pinMode(rainSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach the servo to its pin
  servoMotor.attach(servoPin);
}

void loop() {
  // Read the state of the rain sensor
  int rainState = digitalRead(rainSensorPin);

  if (rainState == HIGH) {
    // If rain is detected, move the servo motor, turn on the LED, and display message on LCD
    servoMotor.write(180);  // Adjust the angle as per your requirement
    digitalWrite(ledPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Rain");
  } else {
    // If no rain is detected, move the servo motor to another position, turn off the LED, and display message on LCD
    servoMotor.write(0);  // Adjust the angle as per your requirement
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rain Detected");
  }

  // Add a small delay to avoid reading the rain sensor too frequently
  delay(100);
}
