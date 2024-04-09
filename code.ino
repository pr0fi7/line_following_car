#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor3(3);

AF_DCMotor motor2(2);
AF_DCMotor motor4(4);

int left_sensor = 9; // Change this to the pin number of your left sensor
int left_value;
int right_sensor = 10; // Change this to the pin number of your right sensor
int right_value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  left_value = digitalRead(left_sensor);
  right_value = digitalRead(right_sensor);
  Serial.print("right: "); // Print label for right sensor value
  Serial.println(right_value); // Print value of right sensor
  Serial.print("left: "); // Print label for left sensor value
  Serial.println(left_value); // Print value of left sensor
  
  // Determine the action based on sensor readings
  if (left_value == 0 && right_value == 1) {
    // Line is to the left, turn left
    turn_left();
  } else if (left_value == 1 && right_value == 0) {
    // Line is to the right, turn right
    turn_right();
  } else if (left_value == 0 && right_value == 0) {
    // On the line, move forward
    move_forward();
  } else {
    // Lost the line, stop motors
    stop_motors();
  }
}

void turn_left() {
  // Motor control code to turn left
  motor1.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.setSpeed(0);
  motor2.run(FORWARD);
  motor3.setSpeed(200);
  motor3.run(FORWARD);
  motor4.setSpeed(0);
  motor4.run(FORWARD);
}

void turn_right() {
  // Motor control code to turn right
  motor1.setSpeed(0);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(0);
  motor3.run(FORWARD);
  motor4.setSpeed(200);
  motor4.run(FORWARD);
}

void move_forward() {
  // Motor control code to move forward
  motor1.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
  motor3.setSpeed(200);
  motor3.run(BACKWARD);
  motor4.setSpeed(200);
  motor4.run(BACKWARD);
}

void stop_motors() {
  // Motor control code to stop all motors
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
