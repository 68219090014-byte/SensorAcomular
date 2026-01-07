/* 6.2 */
//https://app.cirkitdesigner.com/project/24d43e01-3511-4f19-9623-bf348aee1b0d

#define motorR1_Pin 2 // in4 to d2
#define motorR2_Pin 3 // in4 to d3
#define EN_B_Pin    4 // ENB D5 <== PWM

void setup() {
  Serial.begin(9600);
  pinMode(motorR1_Pin,OUTPUT);  
  pinMode(motorR2_Pin,OUTPUT); 
  pinMode(EN_B_Pin,OUTPUT);

  digitalWrite(motorR1_Pin,0); // logic0
  digitalWrite(motorR2_Pin,0); // logic0

}

void loop() {
 // motor R , turn  , 
 /*  IN3      IN4      ENB
      1        0        1  */
  digitalWrite(motorR1_Pin,1); // IN4 to 1
  digitalWrite(motorR2_Pin,0); // In3 to 0
  delay(2000);
 // motor R , turn B
 /*  IN3      IN4
      0        1 */
  digitalWrite(motorR1_Pin,0); // IN4 to 0
  digitalWrite(motorR2_Pin,1); // In3 to 1
  delay(2000);

  // motor R , turn off
 /*  IN3      IN4
      0        0 */
  digitalWrite(motorR1_Pin,0); // IN4 to 0
  digitalWrite(motorR2_Pin,0); // In3 to 0
  delay(200);         
}
