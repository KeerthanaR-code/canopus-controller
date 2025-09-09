/*****  Pro-Range NEMA17 stepper motor control  *****/
/*****  NEMA17 motor steps: 0 - 200  *****/

#include <AccelStepper.h>

// Pin connections
const uint8_t dirPin = 9;
const uint8_t stepPin = 8;
const uint8_t EN = 6;
int16_t maxspeed = 400;  // maximum allowed speed(no.of.steps/second)
int16_t targetPos = 0;   // target position of motor(in steps)

// Stepper object creation
AccelStepper stepper1(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
    Serial.begin(9600);
    stepper1.setCurrentPosition(0);     // set initial motor position to 
    stepper1.setMaxSpeed(400);     // set maximum allowed speed for motor
    stepper1.setSpeed(400);             // set speed at which motor runs
    //stepper1.disableOutputs();
    delay(500);
}

void loop() {
    // Get required motor position from user - Positive value moves motor CW from 0 position. Negative is CCW from 0 position.
    Serial.print("Enter target position in steps:");
    while(!Serial.available()>0) {
        delay(10);
    }
    targetPos = Serial.parseInt();
    Serial.print("Data received: "); Serial.println(targetPos);
    /* // Enable motor output pins
    stepper1.enableOutputs(); */

    // Move stepper motor to desired position
    stepper1.runToNewPosition(targetPos);
    delay(100);
    Serial.println("Motor moved to position: "); Serial.println(targetPos);
    delay(100);
}