#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP32Servo.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define SERVOMIN 100
#define SERVOMAX 500
#define SERVO_MIN 0
#define SERVO_MAX 2400
#define SERVO_FREQ 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Servo
  servo_1,
  servo_2,
  servo_3,
  servo_4,
  servo_5,
  servo_6;

float totalTime = 1.0;
float timeStep[2] = { 0.1, 0.095 };
int8_t offset_g[1] = { 2 };
float totalStep[2] = {
  totalTime / timeStep[0],
  totalTime / timeStep[1],
};

int8_t tinggi[2] = { 0 };

struct Posisi {
  float x0;
  float x1;
  float x2;
  float x3;
  float x4;
  float x5;

  float y0;
  float y1;
  float y2;
  float y3;
  float y4;
  float y5;
};

Posisi posisi;

const uint8_t
  pin_servo[6] = { 14, 12, 13, 4, 2, 15 },
  pin_command[5] = { 27, 26, 25, 33, 32 },
  pin_num_pca[2][6] = {
    { 0, 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10, 11 },
  };

int8_t kalibrasi[3][6] = {
  { 94, 89, 96, 84, 84, 78 },
  { 89, 89, 89, 96, 94, 95 },
  { 96, 97, 85, 94, 93, 95 },
};

float offset_body[2][6] = {
  { -35, -40, -35, 35, 40, 35 },
  { 70, 0, -70, 70, 0, -70 },
};

uint8_t kalibrasi_gripper[2][2] = {
  { 0, 180 },
  { 125, 0 },
};

uint8_t kalibrasi_offset[2][2] = { 0 };
float i_sudut[3] = { 0, 0, 0 };
float data_k[4] = { 10, 0, 10, 5 };

void setup() {
  Serial.begin(115200);
  init_kontrol();
  pwm.begin();
  pwm.setOscillatorFrequency(25000000);
  pwm.setPWMFreq(SERVO_FREQ);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  servo_1.setPeriodHertz(SERVO_FREQ);
  servo_2.setPeriodHertz(SERVO_FREQ);
  servo_3.setPeriodHertz(SERVO_FREQ);
  servo_4.setPeriodHertz(SERVO_FREQ);
  servo_5.setPeriodHertz(SERVO_FREQ);
  servo_6.setPeriodHertz(SERVO_FREQ);

  servo_1.attach(pin_servo[0], SERVO_MIN, SERVO_MAX);
  servo_2.attach(pin_servo[1], SERVO_MIN, SERVO_MAX);
  servo_3.attach(pin_servo[2], SERVO_MIN, SERVO_MAX);
  servo_4.attach(pin_servo[3], SERVO_MIN, SERVO_MAX);
  servo_5.attach(pin_servo[4], SERVO_MIN, SERVO_MAX);
  servo_6.attach(pin_servo[5], SERVO_MIN, SERVO_MAX);

  for (int i = 0; i < 5; i++) {
    pinMode(pin_command[i], INPUT_PULLUP);
  }
  delay(2000);
  main_robot();
  xTaskCreate(task_1, "task_1", 2048, NULL, 1, NULL);
}

void task_1(void* pvParameters) {
  while (1) {
    gerak_tripod(data_k[0], data_k[1], data_k[2], data_k[3], i_sudut[0], i_sudut[1], i_sudut[2]);
    capit(kalibrasi_gripper[0][0] + kalibrasi_offset[0][0], kalibrasi_gripper[1][0] - kalibrasi_offset[1][0]);
    //pembersih(kalibrasi_gripper[0][1] - kalibrasi_offset[0][1], kalibrasi_gripper[1][1] + kalibrasi_offset[1][1]);
  }
}

void loop() {
  //capit_turun_sebagian();
  main_robot();
  //main_kontrol();
  //kalibrasi_servo();
}

uint16_t sudut(uint16_t pos) {
  uint16_t sudut_p = map(pos, 0, 180, SERVOMIN, SERVOMAX);
  return sudut_p;
}

void capit(int u_d, int o_c) {
  pwm.setPWM(14, 0, sudut(u_d));
  pwm.setPWM(15, 0, sudut(o_c));
}

void pembersih(int u_d, int o_c) {
  pwm.setPWM(13, 0, sudut(u_d));
  pwm.setPWM(12, 0, sudut(o_c));
}
void setServoAngle(uint8_t num, uint16_t angle) {
  // Mengubah sudut menjadi lebar pulsa PWM
  uint16_t pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(num, 0, pulse);
}
