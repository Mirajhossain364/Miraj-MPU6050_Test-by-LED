#include <Wire.h>
#include <MPU6050_light.h>

#define UP_LED 2
#define RIGHT_LED 3
#define LEFT_LED 4
#define BACK_LED 5

MPU6050 mpu(Wire);

void setup() {
  Serial.begin(9600);

  mpu.begin();
  Serial.println("MPU6050 Initialized");

  pinMode(UP_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(LEFT_LED, OUTPUT);
  pinMode(BACK_LED, OUTPUT);

  digitalWrite(UP_LED, LOW);
  digitalWrite(RIGHT_LED, LOW);
  digitalWrite(LEFT_LED, LOW);
  digitalWrite(BACK_LED, LOW);
}

void loop() {
  mpu.update();

  float ax = mpu.getAccX();
  float ay = mpu.getAccY();
  float az = mpu.getAccZ();

  Serial.print("X: ");
  Serial.print(ax);
  Serial.print(" Y: ");
  Serial.print(ay);
  Serial.print(" Z: ");
  Serial.println(az);

  digitalWrite(UP_LED, LOW);
  digitalWrite(RIGHT_LED, LOW);
  digitalWrite(LEFT_LED, LOW);
  digitalWrite(BACK_LED, LOW);

  if (az > 0.8) {
    digitalWrite(UP_LED, HIGH);
  } else if (az < -0.8) {
    digitalWrite(BACK_LED, HIGH);
  } else if (ax > 0.8) {
    digitalWrite(RIGHT_LED, HIGH);
  } else if (ax < -0.8) {
    digitalWrite(LEFT_LED, HIGH);
  }

  delay(100);
}
