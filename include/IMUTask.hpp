#pragma once

#include <ControlTask.hpp>

class IMUTask : ControlTask {
  public:
  IMUTask();
  void setup();
  void execute();
};