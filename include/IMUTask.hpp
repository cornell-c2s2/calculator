#pragma once

#include <ControlTask.hpp>

class IMUTask : ControlTask {
  public:
  IMUTask(SFR& sfr);
  void setup();
  void execute();
};