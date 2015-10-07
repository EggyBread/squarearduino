
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper StepperX(stepsPerRevolution, 4, 5, 6, 7);
Stepper StepperY(stepsPerRevolution, 8, 9, 10, 11);


void setMotorLow() /* turns off signal pins to stepper motors to avoid overheating H-bridges */
{
  int i = 4;
  for (i = 4; i < 12; i++)
  {
    digitalWrite (i, LOW);
//    Serial.println("set pin");
//    Serial.println(i);
//    Serial.println("low");
  };
};


void setup() {
  // set the speed at 60 rpm:
  StepperX.setSpeed(60);
  StepperY.setSpeed(60);
  // initialize the serial port:
  Serial.begin(115200);
}

void loop() {
  // step one revolution  in one direction:
  square1();
  square2();
  diamond1();
  diamond2();
  
  
}

void square1()
{
    path(50, 0);
  setMotorLow();
  delay(500);
  
  path(0, 50);
  setMotorLow();
  delay(500);
  

  path(-50, 0);
  setMotorLow();
  delay(500);
  
  path(0, -50);
  setMotorLow();
  delay(500);
}

void square2()
{
  path(0, 50);
  setMotorLow();
  delay(500);
  

  
  path(50, 0);
  setMotorLow();
  delay(500);
  
  
  path(0, -50);
  setMotorLow();
  delay(500);
  
  
  path(-50, 0);
  setMotorLow();
  delay(500);

}

void diamond1()
{
  path(50, 50);
  setMotorLow();
  delay(500);
  
  path(-50, 50);
  setMotorLow();
  delay(500);
  
  
  path(-50, -50);
  setMotorLow();
  delay(500);
  
  path(50, -50);
  setMotorLow();
  delay(500);
}

void diamond2()
{
   path(-50, -50);
  setMotorLow();
  delay(500);
  
  path(50, -50);
  setMotorLow();
  delay(500);
  
  
  path(50, 50);
  setMotorLow();
  delay(500);
  
  path(-50, 50);
  setMotorLow();
  delay(500);
}



void path(int xSteps, int ySteps)
{
    int xProgress = 0,
    yProgress = 0,
    xDifference = 0,
    yDifference = 0;

    int i;
    
    for (i = 0; i < 100; i++)
    {
        xDifference = (xSteps * i / 100) - xProgress;
        yDifference = (ySteps * i / 100) - yProgress;

        StepperX.step(xDifference);
        delay(3);
        StepperY.step(yDifference);
        delay(3);
        setMotorLow();

        xProgress += xDifference;
        yProgress += yDifference;
//        Serial.print("X Difference: ");
//        Serial.println(xDifference);
//        Serial.print("X Progress: ");
//        Serial.println(xProgress);
//        Serial.print("Y Difference: ");
//        Serial.println(yDifference);
//        Serial.print("Y Progress: ");
//        Serial.println(yProgress);
    }
}
