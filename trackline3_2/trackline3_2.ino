/*

    Line Following Robot 3 Sensors with Arduino UNO + L298P
    For more details visit:
    https://robotsiam.blogspot.com/2018/01/3-arduino-l298p.html

*/

/*-------definning Outputs------*/

int MA1 = 12;     // Motor A1
int MA2 =  3;     // Motor A2
int PWM_A =  10;   // Speed Motor A

int MB1 =  13;     // Motor B1
int MB2 =  8;     // Motor B2
int PWM_B =  11;  // Speed Motor B

int SPEED = 110;  // Speed PWM สามารถปรับความเร็วได้ถึง 0 - 255


/*-------definning Sensor------*/

int sensor[3] = {0, 0, 0};


void setup() {

  //Setup Channel A
  pinMode(12, OUTPUT); //Motor A1
  pinMode(3, OUTPUT); //Motor A2
  pinMode(10, OUTPUT); //Speed PWM Motor A

  //Setup Channel B
  pinMode(13, OUTPUT);  //Motor B1
  pinMode(8, OUTPUT);  //Motor B2
  pinMode(11, OUTPUT); //Speed PWM Motor B

}

void loop() {


  sensor[0] = digitalRead(A1);
  sensor[1] = digitalRead(A2);
  sensor[2] = digitalRead(A3);

  if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) )
    Forward(1);
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) )
    turnRight(10);
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) )
    turnRight(200);
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0)  )
    turnLeft(10);
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) )
    turnLeft(200);

  else
    Forward(1);

}

void Backward(int time)
{
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  analogWrite(PWM_A, SPEED);

  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
  analogWrite(PWM_B, SPEED);

  delay(time);
}

void Forward (int time)
{
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  analogWrite(PWM_A, SPEED);

  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
  analogWrite(PWM_B, SPEED);

  delay(time);
}

void turnLeft(int time)
{
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  analogWrite(PWM_A, SPEED);

  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  analogWrite(PWM_B, 0);

  delay(time);
}

void turnRight(int time)
{
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  analogWrite(PWM_A, 0);

  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
  analogWrite(PWM_B, SPEED);

  delay(time);
}

void Stop(int time)
{
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  analogWrite(PWM_A, 0);

  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  analogWrite(PWM_B, 0);

  delay(time);

}
