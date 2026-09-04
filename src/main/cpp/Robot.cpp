// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>

#include "Exercises.h"

Robot::Robot() {}

void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::DisabledExit() {}

void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {}

void Robot::AutonomousExit() {}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
  switch (m_container.m_selectedDrive) {
    case DriveMethod::Tank:
      exercise_0::TankDrive(m_container.m_drive, m_container.m_pilot);
      break;
    case DriveMethod::TurnInPlace:
      exercise_0::TurnInPlaceDrive(m_container.m_drive, m_container.m_pilot);
      break;
    case DriveMethod::Arcade:
      exercise_0::ArcadeDrive(m_container.m_drive, m_container.m_pilot);
      break;
    default:
      fmt::println("Unsupported Drive Method Selected!");
  }
}

void Robot::TeleopExit() {}

void Robot::TestInit() {
}

void Robot::TestPeriodic() {}

void Robot::TestExit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
