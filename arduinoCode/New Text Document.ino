// C++ code
//
#include<IRremote.h>
#include <Servo.h>
//Global Varibles
static int inputPin = 2; // IR input pin

static int leftServoPin = 3; // Servo Control Pins
static int rightServoPin = 4;

int symmetricSpeed = 90;
int leftSpeedModifier = 0;
int rightSpeedModifier = 0;

Servo leftServo;
Servo rightServo;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(inputPin);
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);

}


void loop() {
  if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    IrReceiver.resume();
    
    switch (command) {
      
      case 6:
       symmetricSpeed += 9;
        break;
      
      case 4:
        symmetricSpeed -= 9;
        break;

      default:
        break;
    }
  }
  updateSpeeds();
}

void updateSpeeds() {
  leftServo.write(symmetricSpeed + leftSpeedModifier);
  rightServo.write(symmetricSpeed + rightSpeedModifier);
  Serial.println(symmetricSpeed);
}