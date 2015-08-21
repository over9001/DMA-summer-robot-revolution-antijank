// Using Greg's reference controller
// Wireles module uses standard pinout as given in RobotTx tab (nano)
// Left stick A2-Xaxis A3-Yaxis A5-Switch
// Right stick A0-Xaxis A1-Yaxis A4-Switch
// Battery pack attached to Vin and Ground
// x and y axes are not necessarily as labelled, but instead as canonical to controller orientation

//Set up variables for joystick pins
int joystick_L_Xpin = A2;
int joystick_L_Ypin = A3;
int joystick_L_SWpin = A5;

int joystick_R_Xpin = A0;
int joystick_R_Ypin = A1;
int joystick_R_SWpin = A4;

//Set up variables for readings values
int joystick_L_Xval = 0;
int joystick_L_Yval = 0;
int joystick_L_SWval = 0;

int joystick_R_Xval = 0;
int joystick_R_Yval = 0;
int joystick_R_SWval = 0;


void setup() {
  Serial.begin(57600);
  TransmitterSetup(105);
}

void loop() {
  readJoysticks();
  prepareData();
  SendData();
  PrintData();
}

void readJoysticks() {
  // Read all pin states into corresponding values

  joystick_L_Xval = analogRead(joystick_L_Xpin);
  //delay(1);
  joystick_L_Yval = analogRead(joystick_L_Ypin);
  //delay(1);
  joystick_L_SWval = analogRead(joystick_L_SWpin);
  //delay(1);
  joystick_R_Xval = analogRead(joystick_R_Xpin);
  //delay(1);
  joystick_R_Yval = analogRead(joystick_R_Ypin);
  //delay(1);
  joystick_R_SWval = analogRead(joystick_R_SWpin);
  //delay(1);
}

void prepareData() {
  g = random(100000);
  
  if (joystick_L_Yval < 487){
    // Left motor state - 2 is forward
    a = 2;
    // Left motor power
    b = map(joystick_L_Yval,486,0,0,255);
  } else if (joystick_L_Yval > 560){
    // Left motor state - 1 is backward
    a = 1;
    // Left motor power
    b = map(joystick_L_Yval,561,1023,0,255);
  } else {
    //Left motor state - 0  is stop
    a = 0;
    // Left motor power
    b = 0;
  }

  if (joystick_R_Yval < 487){
    // Right motor state - 2 is forward
    c = 2;
    // Right motor power
    d = map(joystick_R_Yval,486,0,0,255);
  } else if (joystick_R_Yval > 560){
    // Right motor state - 1 is backward
    c = 1;
    // Right motor power
    d = map(joystick_R_Yval,561,1023,0,255);
  } else {
    //Right motor state - 0  is stop
    c = 0;
    // Right motor power
    d = 0;
  }

} 
