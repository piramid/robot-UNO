int MotorPin2 = 2;
int MotorPin3 = 3;
 
void setup() {
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(MotorPin2, HIGH); //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT3
  digitalWrite(MotorPin3, LOW); //สั่งงานให้ขา OUT4  เป็นขารับไฟจากขา OUT3
  Serial.println("Motor Right");
  delay(2000);
  digitalWrite(MotorPin2, LOW); //สั่งงานให้ขา OUT3 หยุดจ่ายไฟ
  digitalWrite(MotorPin3, LOW); //สั่งงานให้ขา OUT4 หยุดจ่ายไฟ
  Serial.println("Motor STOP");
  delay(2000);
  digitalWrite(MotorPin2, LOW); //สั่งงานให้ขา OUT3  เป็นขารับไฟจากขา OUT4
  digitalWrite(MotorPin3, HIGH); //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT4
  Serial.println("Motor Left");
  delay(2000);
}
