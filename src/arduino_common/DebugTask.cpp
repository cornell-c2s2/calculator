#include <DebugTask.hpp>
#include <Arduino.h>
#include <StateFieldRegistry.hpp>

DebugTask::DebugTask(SFR& sfr) : ControlTask(sfr) {
};

void DebugTask::setup() {
  // this code runs once
  Serial.begin(9600);
};

void DebugTask::execute() {
  // this code runs repeatedly
  Serial.print("Got IMU orientation: ");
  for(int i = 0; i < 3; i++) {
    Serial.print(sfr_.imu_orientation[i]);
    Serial.print(", ");
  }
  Serial.print("\n");
};