#include "exercises/Exercise0.h"

namespace exercise_1 {

void TestLEDs(frc2::CommandXboxController &controller, LEDs &leds) {
  if (controller.LeftBumper().Get()) {
    leds.AllBlue();
  } else if (controller.RightBumper().Get()) {
    leds.AllRed();
  } else {
    leds.Off();
  }
  
  if (controller.Start().Get()) {
    const int index = 25 + 20*(controller.GetRightTriggerAxis() - controller.GetLeftTriggerAxis());
    leds.SetLED(index - 1, 255, 255, 255);
    leds.SetLED(index,     255, 255, 255);
    leds.SetLED(index + 1, 255, 255, 255);
  }
}

/* This function should set the LEDs to be all red when the robot is in
 * the Red Alliance's zone, and to blue when in the Blue Alliance's zone.
 *
 * To do this, read the coordinates of the robot from 'drive' and use some if statements
 * to determine if it is inside the relevant zone.
 */
void DetectZone(Drivebase &drive, LEDs &leds) {
  // Your implementation here
}


/* This function should light up a few LEDs in the strip based on where the robot is relative
 * to a trench.
 * If the robot is not in a trench, it should do nothing.
 * If the robot is in a trench, imagine the strip of LEDs is stretched out from back to front
 * of the robot. We want to illuminate the LEDs which are underneath the bar of the trench.
 * 
 * So for example, if the robot is 30% through the trench, then the 15th (30% of 50) LED should be lit
 * a different color.
 * If this example seems contrived, this type of thing actually comes in handy for letting the
 * people who are placing the robot down on the field to align it.
 */
void AlignTrench(Drivebase &drive, LEDs &leds) {
  // Your implementation here
}

}