/* 4.4 4x4 */
//https://app.cirkitdesigner.com/project/42f8af6f-8b2d-4cd2-aa5d-b57e9d16edd7


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define ledPinB 13
#define sol_Pin 8 //solenoid

const byte ROWS = 4; // Number of rows
const byte COLS = 4; // Number of columns

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9};   // Connect to R1, R2, R3, R4
byte colPins[COLS] = {7, 6, 5, 4};   // Connect to C1, C2, C3, C4

// Create a Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String input_password = "";


const String password_1 = "1234";

void setup() {

pinMode(ledPinB,OUTPUT);
digitalWrite(ledPinB,0);
delay(100);

pinMode(sol_Pin,OUTPUT);
digitalWrite(sol_Pin,0);
delay(100);

  Serial.begin(9600); // Initialize serial communication
  Serial.println("4x4 Keypad Test");
  
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("4x4 Keypad Test");
  lcd.setCursor(0, 1);
  lcd.print("Saharat");
  delay(2000);
  lcd.clear();
}


void loop() {
  // put your setup code here, to run once:
 
   char key = keypad.getKey(); // Get the key pressed

  if (key) { // If a key is pressed
    lcd.setCursor(0,0);
    lcd.print("Key Pressed");
    Serial.println (key);

    if (key == '*') {
      input_password = "";
     lcd.clear();
     lcd.setCursor(1,0);
     lcd.print("CLEAR PASSWORD");
    delay(1000);
    lcd.clear();
    }
    else if(key == '#'){
        if (input_password==password_1){
            lcd.clear();
            lcd.print("Password OK");
            Serial.print("Password OK");
            digitalWrite(ledPinB,1);
            digitalWrite(sol_Pin,1);
            delay(3000);
            digitalWrite(ledPinB,0);
            digitalWrite(sol_Pin,0);
        }
        else {
          lcd.clear(); 
          lcd.print("Password FAIL"); 
          delay(3000);
        }     
         input_password = "";      
         lcd.clear();
    }
else{
    input_password += key;
    lcd.setCursor(0, 1);
    lcd.print(input_password);
     }
}

    Serial.print("Key Pressed: ");
    Serial.println(key); // Print the key to the serial monitor
    
  }
