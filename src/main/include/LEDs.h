#pragma once

#include <frc/AddressableLED.h>
#include <frc2/command/SubsystemBase.h>

#include <array>

class LEDs: public frc2::SubsystemBase {
public:
  LEDs();

public:
  void Periodic() override;

public:
  void SetLED(int index, uint8_t r, uint8_t g, uint8_t b);

public:  // presets/patterns
  void Off();
  void AllRed();
  void AllBlue();

private:
  frc::AddressableLED m_led;
  std::array<frc::AddressableLED::LEDData, 50> m_buffer;

public:
  void SimulationPeriodic() override;
};