/*LAB 4.4 4x4 */ 

//https://app.cirkitdesigner.com/project/42380c54-266a-4764-8f9b-bbe28b9f6a61

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ===== LCD =====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== PIN =====
#define ledPinB 13
#define sol_Pin 8

// ===== Keypad =====
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9};
byte colPins[COLS] = {7, 6, 5, 4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ===== PASSWORD =====
String input_password = "";
const String password_1 = "1234";
const byte PASSWORD_LEN = 4;

// ===== FUNCTION =====
void checkPassword() {
  lcd.clear();
  if (input_password == password_1) {
    lcd.print("Password OK");
    digitalWrite(ledPinB, HIGH);
    digitalWrite(sol_Pin, HIGH);
    delay(3000);
    digitalWrite(ledPinB, LOW);
    digitalWrite(sol_Pin, LOW);
  } else {
    lcd.print("Password FAIL");
    delay(2000);
  }
  input_password = "";
  lcd.clear();
  lcd.print("Enter Password");
}

// ===== SETUP =====
void setup() {
  pinMode(ledPinB, OUTPUT);
  pinMode(sol_Pin, OUTPUT);
  digitalWrite(ledPinB, LOW);
  digitalWrite(sol_Pin, LOW);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("4x4 Keypad Test");
  lcd.setCursor(0,1);
  lcd.print("Saharat");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Password");
}

// ===== LOOP =====
void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);

    // CLEAR
    if (key == '*') {
      input_password = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password");
    }

    // ENTER
    else if (key == '#') {
      checkPassword();
    }

    // INPUT NUMBER
    else {
      if (input_password.length() < PASSWORD_LEN) {
        input_password += key;
        lcd.setCursor(0,1);
        lcd.print("                "); // clear line
        lcd.setCursor(0,1);
        for (byte i = 0; i < input_password.length(); i++) {
          lcd.print("*");
        }
      }
    }
  }
}
