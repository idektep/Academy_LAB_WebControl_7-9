#define MR_IN1 12 //backright motor
#define MR_IN2 13 //backright motor
#define MR_IN3 33 //frontright motor
#define MR_IN4 32 //frontright motor
#define ML_IN3 25 //backleft motor
#define ML_IN4 26 //backleft motor
#define ML_IN1 14 //frontleft motor
#define ML_IN2 27 //frontleft motor

#define BR_ENA 15  //Pin speed backright motor
#define FR_ENB 2   //Pin speed frontright motor
#define BL_ENB 4   //Pin speed backleft motor
#define FL_ENA 19  //Pin speed frontleft motor

uint8_t BR_Speed = 220;  //Adjust speed //backright motor
uint8_t FR_Speed = 220;  //Adjust speed //frontright motor
uint8_t BL_Speed = 220;  //Adjust speed //backleft motor
uint8_t FL_Speed = 220;  //Adjust speed //frontleft motor

void motorsetup() {
  pinMode(MR_IN1, OUTPUT);
  pinMode(MR_IN2, OUTPUT);
  pinMode(MR_IN3, OUTPUT);
  pinMode(MR_IN4, OUTPUT);
  pinMode(ML_IN1, OUTPUT);
  pinMode(ML_IN2, OUTPUT);
  pinMode(ML_IN3, OUTPUT);
  pinMode(ML_IN4, OUTPUT);
  pinMode(FL_ENA, OUTPUT);
  pinMode(BL_ENB, OUTPUT);
  pinMode(BR_ENA, OUTPUT);
  pinMode(FR_ENB, OUTPUT);
  stop(100);
}
void forward(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, HIGH);  //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, HIGH);  //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, HIGH);  //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, HIGH);  //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void backward(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, LOW);   //backright motor
  digitalWrite(MR_IN2, HIGH);  //backright motor
  digitalWrite(MR_IN3, LOW);   //frontright motor
  digitalWrite(MR_IN4, HIGH);  //frontright motor
  digitalWrite(ML_IN1, LOW);   //frontleft motor
  digitalWrite(ML_IN2, HIGH);  //frontleft motor
  digitalWrite(ML_IN3, LOW);   //backleft motor
  digitalWrite(ML_IN4, HIGH);  //backleft motor
  delay(d);
}

void turn_right(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, LOW);   //backright motor
  digitalWrite(MR_IN2, HIGH);  //backright motor
  digitalWrite(MR_IN3, LOW);   //frontright motor
  digitalWrite(MR_IN4, HIGH);  //frontright motor
  digitalWrite(ML_IN1, HIGH);  //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, HIGH);  //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void turn_left(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, HIGH);  //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, HIGH);  //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, LOW);   //frontleft motor
  digitalWrite(ML_IN2, HIGH);  //frontleft motor
  digitalWrite(ML_IN3, LOW);   //backleft motor
  digitalWrite(ML_IN4, HIGH);  //backleft motor
  delay(d);
}

void slide_left(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, LOW);   //backright motor
  digitalWrite(MR_IN2, HIGH);  //backright motor
  digitalWrite(MR_IN3, HIGH);  //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, LOW);   //frontleft motor
  digitalWrite(ML_IN2, HIGH);  //frontleft motor
  digitalWrite(ML_IN3, HIGH);  //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void slide_right(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, HIGH);  //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, LOW);   //frontright motor
  digitalWrite(MR_IN4, HIGH);  //frontright motor
  digitalWrite(ML_IN1, HIGH);  //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, LOW);   //backleft motor
  digitalWrite(ML_IN4, HIGH);  //backleft motor
  delay(d);
}

void slide_left_forward(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, LOW);   //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, HIGH);  //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, LOW);   //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, HIGH);  //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void slide_right_forward(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, HIGH);  //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, LOW);   //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, HIGH);  //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, LOW);   //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void slide_left_backward(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, LOW);   //backright motor
  digitalWrite(MR_IN2, HIGH);  //backright motor
  digitalWrite(MR_IN3, LOW);   //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, LOW);   //frontleft motor
  digitalWrite(ML_IN2, HIGH);  //frontleft motor
  digitalWrite(ML_IN3, LOW);   //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void slide_right_backward(int d) {
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, LOW);   //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, LOW);   //frontright motor
  digitalWrite(MR_IN4, HIGH);  //frontright motor
  digitalWrite(ML_IN1, LOW);   //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, LOW);   //backleft motor
  digitalWrite(ML_IN4, HIGH);  //backleft motor
  delay(d);
}

void stop(int d) {
  digitalWrite(MR_IN1, LOW);  //backright motor
  digitalWrite(MR_IN2, LOW);  //backright motor
  digitalWrite(MR_IN3, LOW);  //frontright motor
  digitalWrite(MR_IN4, LOW);  //frontright motor
  digitalWrite(ML_IN1, LOW);  //frontleft motor
  digitalWrite(ML_IN2, LOW);  //frontleft motor
  digitalWrite(ML_IN3, LOW);  //backleft motor
  digitalWrite(ML_IN4, LOW);  //backleft motor
  delay(d);
}
