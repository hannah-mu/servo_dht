#include "DHT.h"
#include <Servo.h>
#define DHTPIN 2
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
Servo myServo;

void setup() {
  myServo.attach(6);
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  delay(2000);
  int potValue = analogRead(2);
  float f = dht.readTemperature(true);
  int servoPos = map(f, 72, 78, 0, 180);
  myServo.write(servoPos);

  Serial.print(" Temperature: ");
  Serial.print(f);
  Serial.println("°F");
}
