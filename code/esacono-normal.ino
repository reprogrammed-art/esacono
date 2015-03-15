/* 
 This is a sketch for controlling the motors of Esacono. It is based on the test DC motor sketch of Motor Shield for Arduino v2
 It won't work with v1.x motor shields! Only for the v2's with built in PWM control.
 For more information about Esacono: www.reprogrammed-art.cc
 
 For use with the Adafruit Motor Shield v2 
 ---->	http://www.adafruit.com/products/1438
 */

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMSbot = Adafruit_MotorShield(0x60); 
// Or, create it with a different I2C address (say for stacking)
Adafruit_MotorShield AFMStop = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor5 = AFMSbot.getMotor(1);
Adafruit_DCMotor *myMotor6 = AFMSbot.getMotor(2);
// You can also make another motor on port M2
Adafruit_DCMotor *myMotor1 = AFMStop.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMStop.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMStop.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMStop.getMotor(4);

//int buttonPin = 7;
//int buttonState = LOW;   

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  //pinMode(buttonPin, INPUT);       

 AFMSbot.begin(); // Start the bottom shield
  AFMStop.begin(); // Start the top shield


}

void loop() {
  uint8_t i;
  //Serial.println(buttonState);  

  Serial.print("tick");
 // buttonState = digitalRead(buttonPin);

  //if (buttonState == HIGH) {     


    // Forward motor1
    myMotor1->run(FORWARD);
    for (i=0; i<40; i++) {
      myMotor1->setSpeed(i);  
    }


    // Forward motor2
    myMotor2->run(FORWARD);
    for (i=0; i<35; i++) {
      myMotor2->setSpeed(i);  
      delay(10);
    }
 
    // Forward motor3
    myMotor3->run(FORWARD);
    for (i=0; i<35; i++) {
      myMotor3->setSpeed(i);  
      delay(10);
    }


    // Forward motor4
    myMotor4->run(FORWARD);
    for (i=0; i<35; i++) {
      myMotor4->setSpeed(i);  
      delay(10);
    }
    
        // Forward motor5
    myMotor5     ->run(FORWARD);
    for (i=0; i<35; i++) {
      myMotor5->setSpeed(i);  
      delay(10);
    }
            // Forward motor6
    myMotor6     ->run(FORWARD);
    for (i=0; i<35; i++) {
      myMotor6->setSpeed(i);  
      delay(10);
    }


  } 


