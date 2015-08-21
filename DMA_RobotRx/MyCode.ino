// Motor driver H-Bridger direction controlled through shift register
// Moror speed controlled through pwm on digital pins

//motor power strength controlled through PWM on the following digital pins
int rightWheelPWMpin = 9;
int leftWheelPWMpin = 10;

int gCounter = 0;
int oldG;

void setup() {
  shiftSetup();
  ReceiverSetup(105);
}

void loop(){
  GetData();
  //PrintData();
  //Serial.println(g);

  //Reverse the left wheel direction because of how MY bot is soldered
  //if(a=1){a=2;}else if(a=2){a=1;}
  //reversal code moved down the stack to Shift_Reg code
  
  motorDirection(a, c);
  analogWrite(leftWheelPWMpin, b);
  analogWrite(rightWheelPWMpin, d);

  //anti janking technology follows
  timeOutG();
}

void timeOutG() {
  if (g =! oldG){
    oldG = g;
  } else {
    gCounter++;    
    if (gCounter > 10){
      ReceiverSetup(105);
      gCounter = 0;
    }
  }
}

