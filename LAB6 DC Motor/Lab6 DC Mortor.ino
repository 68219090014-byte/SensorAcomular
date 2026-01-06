/* 6.1 */
//https://app.cirkitdesigner.com/project/6508e905-b560-4115-a38f-2756a06624bb
#define motorPin 9

void setup() {
  // put your setup code here, to run once:
 pinMode(motorPin,OUTPUT);



}

void loop() {
  digitalWrite(motorPin,1);
  delay(2000);
  digitalWrite(motorPin,0);
  delay(2000);
}
