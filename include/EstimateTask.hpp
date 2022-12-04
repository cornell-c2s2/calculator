#pragma once

#include <Adafruit_BNO055.h>
#include <ControlTask.hpp>

class EstimateTask : ControlTask {
  public:
  Adafruit_BNO055 bno;

  EstimateTask(SFR& sfr);
  void setup();
  void execute();
};
