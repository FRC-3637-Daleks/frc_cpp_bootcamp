#pragma once

#include "RobotContainer.h"

namespace exercise_1 {

void TestLEDs(frc2::CommandXboxController &controller, LEDs &leds);
void DetectZone(Drivebase &drive, LEDs &leds);
void AlignTrench(Drivebase &drive, LEDs &leds);

}