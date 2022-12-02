#pragma once

#include <ControlTask.hpp>
#include <IMUTask.hpp>

class MainControlLoop : ControlTask {
  public:
  IMUTask imu_task;
  MainControlLoop();
  void setup();
  void execute();
};