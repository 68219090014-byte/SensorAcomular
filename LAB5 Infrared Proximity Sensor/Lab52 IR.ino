/*  5.2  */
//https://app.cirkitdesigner.com/project/d94b862a-8dab-47e2-a166-ed1e521fa950

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


const int sensorPin = 8;  // Pin connected to the sensor's OUT pin

const int ledPin = 13;    // Pin connected to the onboard LED

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("LAB52 IR ");
  lcd.setCursor(0, 1);
  lcd.print("Saharat");
  delay(2000);
  
  lcd.clear();

  pinMode(sensorPin, INPUT);  // Set the sensor pin as input
  pinMode(ledPin, OUTPUT);    // Set the LED pin as output
  Serial.begin(9600);         // Initialize serial communication for debugging
}

void loop() {

  int sensorValue = digitalRead(sensorPin);  // Read the sensor's output

  if (sensorValue == HIGH) {
    // Object detected
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    Serial.println("Object detected!");
    lcd.setCursor(0, 1);
    lcd.print("Object detected!");
    delay(2000);

  } else {
    // No object detected
    digitalWrite(ledPin, LOW);   // Turn off the LED
    Serial.println("No object detected.");
    lcd.setCursor(0, 1);
    lcd.print("No object detected.");
    delay(2000);

  }

  delay(100);  // Small delay for stability
}
