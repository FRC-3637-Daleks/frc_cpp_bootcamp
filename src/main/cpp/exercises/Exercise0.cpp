#include "exercises/Exercise0.h"

namespace exercise_0 {

/* "Tank Drive" is a control scheme where 2 separate joysticks independently
 * control the speed of the wheels on both sides of a vehicle.
 * To drive forward, the pilot must push both sticks forward.
 * To turn in place, the pilot must drive one side forward and the other backward.
 */
void TankDrive(Drivebase &drive, frc2::CommandXboxController &controller) {
  float left = -controller.GetLeftY();  // Down is positive for some reason, so we invert the value
  float right = -controller.GetRightY();

  drive.SetSpeeds(left, right);
}

/* "Arcade Drive" is a more intuitive control scheme where the Y-axis on a joystick
 * controls the forward and backward motion of the vehcile, and the X-axis on a joystick
 * (possibly the same one) controls the turning motion of the vehicle.
 * 
 * Your task is to implement this control scheme. You will need to get the current 
 * joystick values from the controller (which range from -1 to 1), and perform some simple math 
 * on them to produce a left and right speed (which range from -1 to 1).
 * 
 * Hint: think about what the output should be with only 1 stick moving at a time
 */
void ArcadeDrive(Drivebase &drive, frc2::CommandXboxController &controller) {
  // YOUR CODE HERE
  fmt::println("Unimplemented! To drive, you'll have to switch the joystick back to gamepad[1]");
}

}