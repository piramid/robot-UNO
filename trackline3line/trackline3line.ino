// connect the sensors to digital pins
#define LEFT_SENSORPIN 2
#define CENTER_SENSORPIN 10
#define RIGHT_SENSORPIN 4

// do you have black line on white ground or white line on black ground?
#define LINE LOW
#define NOLINE HIGH

// define some symbolic constants for our driving directions
enum {GO_AHEAD, GO_LEFT, GO_RIGHT, STOP, GO_POWERLEFT, GO_POWERRIGHT, GO_BACK};

// Motor A pins (enableA = enable motor, pinA1 = forward, pinA2 = backward)
int enableA = 3;
int pinA1 = 6;
int pinA2 = 7;

//Motor B pins (enabledB = enable motor, pinB2 = forward, pinB2 = backward)
int enableB = 5;
int pinB1 = 8;
int pinB2 = 9;

void setup()
{
  Serial.begin(9600);
  Serial.println("*** LINE FOLLOWER ***");
  pinMode(LEFT_SENSORPIN,INPUT);
  pinMode(CENTER_SENSORPIN,INPUT);
  pinMode(RIGHT_SENSORPIN,INPUT);

 pinMode(enableA, OUTPUT);
 pinMode(pinA1, OUTPUT);
 pinMode(pinA2, OUTPUT);

 pinMode(enableB, OUTPUT);
 pinMode(pinB1, OUTPUT);
 pinMode(pinB2, OUTPUT);

}

void loop()
{

//Run the motors at slightly less than full power

enableMotors();
analogWrite(enableA, 90);  // ปรับความเร็วหุ่นยนต์
analogWrite(enableB, 90); // ปรับความเร็วหุ่นยนต์

// read input from sensors
  byte leftSensor=digitalRead(LEFT_SENSORPIN);
  byte centerSensor=digitalRead(CENTER_SENSORPIN);
  byte rightSensor=digitalRead(RIGHT_SENSORPIN);

  // calculate direction
  byte goDirection;
  // if only center sensor detects line, go straight ahead
  if (leftSensor==NOLINE && centerSensor==LINE && rightSensor==NOLINE)
      goDirection= GO_AHEAD;
  // if only left sensor detects line, turn left
  else if (leftSensor==LINE && centerSensor==NOLINE && rightSensor==NOLINE)
      goDirection= GO_LEFT;
  // if only right sensor detects line, turn right  
  else if (leftSensor==NOLINE && centerSensor==NOLINE  && rightSensor==LINE)
      goDirection= GO_RIGHT;
  // if no sensor detects any line: we are either finished or out of control and will stop  
  else if (leftSensor==LINE && centerSensor==LINE && rightSensor==LINE)
      goDirection= STOP;
  else if (leftSensor==NOLINE && centerSensor==NOLINE && rightSensor==NOLINE)
      goDirection= GO_BACK;
  // if left and center sensor detect line, must be 90° turn to the left
  else if (leftSensor==LINE && centerSensor==LINE && rightSensor==NOLINE)
      goDirection= GO_POWERLEFT;
  // if right and center sensor detect line, must be 90° turn to the right
  else if (leftSensor==NOLINE && centerSensor==LINE && rightSensor==LINE)
      goDirection= GO_POWERRIGHT;


  // Now we have found the direction,
  // show it on Serial and control motors accordingly
  switch (goDirection)
  {
    case GO_AHEAD:
      Serial.println("Go ahead");
      forward(1);
   
      break;
    case GO_RIGHT:
      Serial.println("Turn right");
      turnRight(10);
   
      break;
    case GO_LEFT:
      Serial.println("Turn left");
       turnLeft(10);
   
      break;
    case STOP:
      Serial.println("No line detected - STOP!");
        coast(600);
       disableMotors();
      break;
    case GO_BACK:
      Serial.println("No line detected - BACK!");
     
     backward(1);
      break;
    case GO_POWERLEFT:
      Serial.println("Power-turn 90 degrees left");
      coast(10);
      turnLeft(600);
 
      break;
    case GO_POWERRIGHT:
      Serial.println("Power-turn 90 degrees right");
       coast(10);
       turnRight(600);
   
      break;

  }
}


//Define high-level H-bridge commands

void enableMotors()
{
 motorAOn();
 motorBOn();
}

void disableMotors()
{
 motorAOff();
 motorBOff();
}

void forward(int time)
{
 motorAForward();
 motorBForward();
 delay(time);
}

void backward(int time)
{
 motorABackward();
 motorBBackward();
 delay(time);
}

void turnLeft(int time)
{
 motorABackward();
 motorBForward();
 delay(time);
}

void turnRight(int time)
{
 motorAForward();
 motorBBackward();
 delay(time);
}

void coast(int time)
{
 motorACoast();
 motorBCoast();
 delay(time);
}

void brake(int time)
{
 motorABrake();
 motorBBrake();
 delay(time);
}
//Define low-level H-bridge commands

//enable motors
void motorAOn()
{
 digitalWrite(enableA, HIGH);
}

void motorBOn()
{
 digitalWrite(enableB, HIGH);
}

 //disable motors
void motorAOff()
{
 digitalWrite(enableB, LOW);
}

void motorBOff()
{
 digitalWrite(enableA, LOW);
}

 //motor A controls
void motorAForward()
{
 digitalWrite(pinA1, HIGH);
 digitalWrite(pinA2, LOW);
}

void motorABackward()
{
 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, HIGH);
}

//motor B controls
void motorBForward()
{
 digitalWrite(pinB1, HIGH);
 digitalWrite(pinB2, LOW);
}

void motorBBackward()
{
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, HIGH);
}

//coasting and braking
void motorACoast()
{
 digitalWrite(pinA1, LOW);
 digitalWrite(pinA2, LOW);
}

void motorABrake()
{
 digitalWrite(pinA1, HIGH);
 digitalWrite(pinA2, HIGH);
}

void motorBCoast()
{
 digitalWrite(pinB1, LOW);
 digitalWrite(pinB2, LOW);
}

void motorBBrake()
{
 digitalWrite(pinB1, HIGH);
 digitalWrite(pinB2, HIGH);
}
