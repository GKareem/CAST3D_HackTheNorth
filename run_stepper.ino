
const int dirOne = 2;
const int pulseOne = 3;

const int dirTwo = 4;
const int pulseTwo = 5;

const int inputPinOne = 13;
const int outputPinOne = 10;

const int inputPinTwo = 12;

void setup() 
{
  //Input and output pinmodes
  pinMode(outputPinOne, OUTPUT);
  pinMode(inputPinOne, INPUT);
  
  //MotorOneSetup
  pinMode(dirOne, OUTPUT);
  pinMode(pulseOne, OUTPUT);
  
  
  //MotorTwoSetup
  pinMode(dirTwo, OUTPUT);
  pinMode(pulseTwo, OUTPUT);
  
}

void loop() 
{
  if(digitalRead(inputPinOne) == HIGH) // Counter Clockwise and Initial Position
  {
    digitalWrite(dirOne, LOW); //naturally low
    digitalWrite(dirTwo, HIGH); //naturally high
    digitalWrite(outputPinOne, HIGH);
  }
  else if(digitalRead(inputPinTwo) == HIGH) // Clockwise and Final Position
  {
    digitalWrite(dirOne, HIGH);
    digitalWrite(dirTwo, LOW);
    digitalWrite(outputPinOne, HIGH);
  }
  else if(digitalRead(inputPinOne) == LOW && digitalRead(inputPinTwo) == LOW )
  {
    digitalWrite(outputPinOne, LOW);
  }

  //MotorOneRun
  digitalWrite(pulseOne, LOW);
  digitalWrite(pulseOne, HIGH);
 
  //MotorTwoRun
  digitalWrite(pulseTwo, LOW);
  digitalWrite(pulseTwo, HIGH);
  delayMicroseconds(1024);
}
