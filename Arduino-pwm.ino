#define HG7881_A_1A 6
#define HG7881_A_1B 9
#define HG7881_B_1A 10
#define HG7881_B_1B 11

#define LEFT_DRIVE_DIR HG7881_A_1A
#define LEFT_DRIVE_SPEED HG7881_A_1B
#define RIGHT_DRIVE_DIR HG7881_B_1A
#define RIGHT_DRIVE_SPEED HG7881_B_1B

#define FORWARD 1
#define BACKWARD 0

#define PWM_SLOW 0
#define PWM_FAST 255

#define DELAY 3000

void setLeftDriveSpeed(byte dir, byte speed) {
  if(dir == FORWARD)
  {
    digitalWrite(LEFT_DRIVE_DIR, HIGH);
    analogWrite( LEFT_DRIVE_SPEED, PWM_FAST - speed);
  }
  if(dir == BACKWARD)
  {
    digitalWrite(LEFT_DRIVE_SPEED, HIGH);
    analogWrite( LEFT_DRIVE_DIR, PWM_FAST - speed);
  }
}


void setRightDriveSpeed(byte dir, byte speed) {
  if(dir == FORWARD)
  {
    digitalWrite(RIGHT_DRIVE_DIR, HIGH);
    analogWrite( RIGHT_DRIVE_SPEED, PWM_FAST - speed);
  }
  if(dir == BACKWARD)
  {
    digitalWrite(RIGHT_DRIVE_SPEED, HIGH);
    analogWrite(RIGHT_DRIVE_DIR , PWM_FAST - speed);
  }
}

void initDrives() {
   pinMode(LEFT_DRIVE_SPEED, OUTPUT);
   pinMode(LEFT_DRIVE_DIR, OUTPUT);
   pinMode(RIGHT_DRIVE_SPEED, OUTPUT);
   pinMode(RIGHT_DRIVE_DIR, OUTPUT);
   setLeftDriveSpeed(FORWARD, 0);
   setRightDriveSpeed(FORWARD, 0);
}

void setup() {
   initDrives();
   Serial.begin(9600);
   setLeftDriveSpeed(1,255);
}

void loop() {
byte dir1;
byte speed1;
byte dir2;
byte speed2;
  if (Serial.available() >= 4) {
    dir1 = Serial.read();
    speed1 = Serial.read();
    dir2 = Serial.read();
    speed2 = Serial.read();
    setLeftDriveSpeed(dir1,speed1);
    setRightDriveSpeed(dir2,speed2);
  }
}
