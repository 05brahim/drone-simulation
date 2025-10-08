#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <iostream>

#define TIME_STEP 8

using namespace webots;

int main() {
  Robot *robot = new Robot();

  // جلب المحركات الأربعة
  Motor *motors[4];
  char motorNames[4][10] = {"m1_motor", "m2_motor", "m3_motor", "m4_motor"};

  for (int i = 0; i < 4; i++) {
    motors[i] = robot->getMotor(motorNames[i]);
    motors[i]->setPosition(INFINITY);  // وضع السرعة الحرة
    motors[i]->setVelocity(0.0);
  }

  while (robot->step(TIME_STEP) != -1) {
    // تشغيل المحركات بسرعة بسيطة
    for (int i = 0; i < 4; i++) {
      motors[i]->setVelocity(1000.0);
    }
  }

  delete robot;
  return 0;
}
