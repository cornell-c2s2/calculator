#include <Arduino.h>
#include <MainControlLoop.hpp>

void setup()
{
  // put your setup code here, to run once:
  MainControlLoop mcl = MainControlLoop();
  mcl.setup();
  mcl.execute();
}

void loop()
{
  // do nothing
}