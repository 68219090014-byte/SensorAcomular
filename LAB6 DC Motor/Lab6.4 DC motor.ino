/*6.4*/
//https://app.cirkitdesigner.com/project/d86a11a5-0d17-4ee6-b6ae-1831df18b2af

#define motorR1_Pin 2 
#define motorR2_Pin 3 

#define motorR3_Pin 8 
#define motorR4_Pin 9 

#define EN_B_Pin1  5  
#define EN_B_Pin2  10  

void setup() {
  Serial.begin(9600);
  pinMode(motorR1_Pin,OUTPUT);  
  pinMode(motorR2_Pin,OUTPUT);

  pinMode(motorR3_Pin,OUTPUT);  
  pinMode(motorR4_Pin,OUTPUT);  

  pinMode(EN_B_Pin1,OUTPUT);
  pinMode(EN_B_Pin2,OUTPUT);

  digitalWrite(motorR1_Pin,0); // logic0
  digitalWrite(motorR2_Pin,0); // logic0

}

void loop() {

 // turn off  
  analogWrite(EN_B_Pin1,0);
  analogWrite(EN_B_Pin2,0); 

  digitalWrite(motorR1_Pin,0); 
  digitalWrite(motorR2_Pin,0); 
  digitalWrite(motorR3_Pin,0);  
  digitalWrite(motorR4_Pin,0); 
  delay(3000);

 // เดินหน้า  F
 // L100%  R100%
  analogWrite(EN_B_Pin1,255);
  analogWrite(EN_B_Pin2,255);

  digitalWrite(motorR1_Pin,1);
  digitalWrite(motorR2_Pin,0);
  digitalWrite(motorR3_Pin,1);  
  digitalWrite(motorR4_Pin,0); 
  delay(3000);

 //ถอยหลัง R
 // L100%  R100%
  analogWrite(EN_B_Pin1,80);
  analogWrite(EN_B_Pin2,80);

  digitalWrite(motorR1_Pin,0); 
  digitalWrite(motorR2_Pin,1); 
  digitalWrite(motorR3_Pin,0);  
  digitalWrite(motorR4_Pin,1); 
  delay(3000);

 // เลี้ยวซ้าย  L
 // L50%  R100%
  analogWrite(EN_B_Pin1,128);
  analogWrite(EN_B_Pin2,255);

  digitalWrite(motorR1_Pin,1);
  digitalWrite(motorR2_Pin,0); 
  digitalWrite(motorR3_Pin,1);  
  digitalWrite(motorR4_Pin,0); 
  delay(3000);

 // เลี้ยวซ้าย  R
 // L100%  R50%
  analogWrite(EN_B_Pin1,255);
  analogWrite(EN_B_Pin2,128);

  digitalWrite(motorR1_Pin,0);
  digitalWrite(motorR2_Pin,1); 
  digitalWrite(motorR3_Pin,0);  
  digitalWrite(motorR4_Pin,1); 
  delay(3000);
}
