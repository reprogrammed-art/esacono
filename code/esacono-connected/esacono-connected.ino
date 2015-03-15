#include <Bridge.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

#include <Adafruit_MotorShield.h>
#include <Wire.h>

#include <Process.h>
#include <MQTTclient.h>


#define MQTT_HOST "test.mosquitto.org" // test.mosquitto.org


Adafruit_MotorShield AFMSbot(0x70); // Leftmost jumper closed
Adafruit_MotorShield AFMStop(0x60); // Default address, no jumpers

Adafruit_DCMotor *myMotor1 = AFMSbot.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMSbot.getMotor(2);

Adafruit_DCMotor *myMotor3 = AFMStop.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMStop.getMotor(4);
Adafruit_DCMotor *myMotor5 = AFMStop.getMotor(3);
Adafruit_DCMotor *myMotor6 = AFMStop.getMotor(4);

void setup() {

  Serial.begin(9600);
  while(!Serial);

  Serial.print("bridge starting");
  Bridge.begin();
  Serial.println("bridge started");

  // begin the client library (initialize host)
  mqtt.begin(MQTT_HOST, 1883);

  delay(500);

  //mqtt.subscribe("/test/#",debug);
  mqtt.subscribe("test/esacono/#", esacono);
  //  mqtt.subscribe("test/esacono2/", esacono2);
  //  mqtt.subscribe("test/esacono3/", esacono3);
  //  mqtt.subscribe("test/esacono4/", esacono4);
  //  mqtt.subscribe("test/esacono5/", esacono5);
  // mqtt.subscribe("test/esacono6/", esacono6);


  AFMSbot.begin(); // Start the bottom shield
  AFMStop.begin(); // Start the top shield


  myMotor1->setSpeed(1);
  myMotor1->run(FORWARD);

  myMotor2->setSpeed(1);
  myMotor2->run(BACKWARD);

  Serial.println("everything started");
}

void loop() {
  mqtt.monitor();
   Process wifiCheck;

  wifiCheck.runShellCommand("/usr/bin/pretty-wifi-info.lua");

  while (wifiCheck.available() > 0) {
    char c = wifiCheck.read();
    Serial.print(c);
  }

  Serial.println();

  delay(5000);
}

void esacono(const String& topic, const String& subtopic, const String& message) {
  int receivedValue = message.toInt();
  int motorNumber = subtopic.toInt();

  Serial.print("starting motor ");
  Serial.print(motorNumber);
  Serial.print(" at speed ");
  Serial.println(receivedValue);

  switch (motorNumber) {
    case 1:
      myMotor1->setSpeed(receivedValue);
      myMotor1->run(FORWARD);
      break;

    case 2:
      myMotor2->setSpeed(receivedValue);
      myMotor2->run(FORWARD);
      break;

    case 3:
      myMotor3->setSpeed(receivedValue);
      myMotor3->run(FORWARD);
      break;

    case 4:
      myMotor4->setSpeed(receivedValue);
      myMotor4->run(FORWARD);
      break;

    case 5:
      myMotor5->setSpeed(receivedValue);
      myMotor5->run(FORWARD);
      break;

    case 6:
      myMotor6->setSpeed(receivedValue);
      myMotor6->run(FORWARD);
      break;
  }
}
