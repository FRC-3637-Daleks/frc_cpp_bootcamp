// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>

RobotContainer::RobotContainer()
  : m_pilot{0}
  , m_operator{1}
 {
  ConfigureBindings();
  ConfigureDashboard();
}

void RobotContainer::ConfigureBindings() {}

void RobotContainer::ConfigureDashboard() {
  m_driveChooser.SetDefaultOption("1) Tank Drive", DriveMethod::Tank);
  m_driveChooser.AddOption("2) Turn In Place Drive", DriveMethod::TurnInPlace);
  m_driveChooser.AddOption("3) Arcade Drive", DriveMethod::Arcade);
  m_driveChooser.OnChange([this] (DriveMethod driveMethod) {this->m_selectedDrive = driveMethod;});
  frc::SmartDashboard::PutData("Drive", &m_driveChooser);
}