#pragma once

class SFR {
  public:
  float imu_orientation[3] = {};
  float imu_acceleration[3] = {};
  float imu_velocity[3] = {};
  float imu_position[3] = {};
  SFR();
};