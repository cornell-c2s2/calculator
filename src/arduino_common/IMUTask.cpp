#include <IMUTask.hpp>
#include <Arduino.h>

IMUTask::IMUTask() {

};

void IMUTask::setup() {
  // this code runs once
  Serial.println("IMU Task Setup");
  
};

void IMUTask::execute() {
  // this code runs repeatedly
  Serial.println("IMU Task Execute");
};