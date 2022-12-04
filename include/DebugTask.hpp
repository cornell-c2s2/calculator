#pragma once

#include <Adafruit_BNO055.h>
#include <ControlTask.hpp>

class DebugTask : ControlTask {
  public:

  DebugTask(SFR& sfr);
  void setup();
  void execute();
};
