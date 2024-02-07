int LEFT_MOTOR = 3;
int RIGHT_MOTOR = 5;

int LEFT_SWITCH = 2;
int RIGHT_SWITCH = 4;

int LEFT_POTENTIO = A0;
int RIGHT_POTENTIO = A1;

bool LEFT_MOTOR_ON = false;
bool RIGHT_MOTOR_ON = false;

void setup()
{
  Serial.begin(9600);
  
  pinMode(LEFT_SWITCH, INPUT);
  pinMode(RIGHT_SWITCH, INPUT);
}

void loop()
{
  if (Serial.available()) {
  	char USER_INPUT = Serial.read();
    
    if (USER_INPUT == 'L') {
    	LEFT_MOTOR_ON = true;
    } else if (USER_INPUT == 'R') {
    	RIGHT_MOTOR_ON = true;
    } else if (USER_INPUT == 'S') {
    	LEFT_MOTOR_ON = false;
      	RIGHT_MOTOR_ON = false;
    }
  }
  
  if (digitalRead(LEFT_SWITCH) == HIGH || LEFT_MOTOR_ON) {
  	int POTENTIO_VALUE = map(analogRead(LEFT_POTENTIO), 0, 1023, 0, 255);
    
    analogWrite(LEFT_MOTOR, 255 - POTENTIO_VALUE);
  } else {
  	analogWrite(LEFT_MOTOR, LOW);
  }
  
  if (digitalRead(RIGHT_SWITCH) == HIGH || RIGHT_MOTOR_ON) {
  	int POTENTIO_VALUE = map(analogRead(RIGHT_POTENTIO), 0, 1023, 0, 255);
    
    analogWrite(RIGHT_MOTOR, 255 - POTENTIO_VALUE);
  } else {
  	analogWrite(RIGHT_MOTOR, LOW);
  }
}