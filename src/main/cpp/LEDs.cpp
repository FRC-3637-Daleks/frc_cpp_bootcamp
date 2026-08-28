#include "LEDs.h"

#include <frc/LEDPattern.h>

LEDs::LEDs()
  : m_led{1}
{
  m_led.SetLength(50);
  m_led.Start();
}

void LEDs::Periodic() {
  m_led.SetData(m_buffer);
}

void LEDs::SetLED(int index, uint8_t r, uint8_t g, uint8_t b) {
  if (index >= 0 && index < 50)
    m_buffer[index].SetRGB(r, g, b);
}

void LEDs::Off() {
  frc::LEDPattern::Off().ApplyTo(m_buffer);
}

void LEDs::AllRed() {
  frc::LEDPattern::Solid(frc::Color::kRed).ApplyTo(m_buffer);
}

void LEDs::AllBlue() {
  frc::LEDPattern::Solid(frc::Color::kBlue).ApplyTo(m_buffer);
}

void LEDs::SimulationPeriodic() {

}