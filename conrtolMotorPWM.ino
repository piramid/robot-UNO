// Motor A
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 6; //   เพื่อให้ PWM สามารถควบคุมความเร็วมอเตอร์  
// Motor B
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 7; // เพื่อให้ PWM สามารถควบคุมความเร็วมอเตอร์
 
void setup()
{
  Serial.begin(9600);
   //กำหนด ขา เพื่อใช้ในการควบคุมการทำงานของ  Motor ผ่านทาง L298N
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
}
 
void loop()
{ 
// Motor A
 analogWrite(speedPinA, 255); //ตั้งค่าความเร็ว PWM ผ่านตัวแปร ค่าต่ำลง มอเตอร์จะหมุนช้าลง
 digitalWrite(dir1PinA, LOW);
 digitalWrite(dir2PinA, HIGH);
// Motor B
 analogWrite(speedPinB, 255); //ตั้งค่าความเร็ว PWM ผ่านตัวแปร ค่าต่ำลง มอเตอร์จะหมุนช้าลง
 digitalWrite(dir1PinB, LOW);
 digitalWrite(dir2PinB, HIGH);
}
