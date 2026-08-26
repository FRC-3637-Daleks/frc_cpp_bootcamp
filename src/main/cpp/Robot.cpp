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
  if (m_container.m_pilot.IsConnected())
    exercise_0::ArcadeDrive(m_container.m_drive, m_container.m_pilot);
  else if (m_container.m_operator.IsConnected())
    exercise_0::TankDrive(m_container.m_drive, m_container.m_operator);
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
