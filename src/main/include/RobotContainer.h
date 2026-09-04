// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Drivebase.h"

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/smartdashboard/SendableChooser.h>

enum class DriveMethod {
  Tank,
  TurnInPlace,
  Arcade,
};

class RobotContainer {
  frc::SendableChooser<DriveMethod> m_driveChooser;

public:
  RobotContainer();

public:
  Drivebase m_drive;
  frc2::CommandXboxController m_pilot, m_operator;
  DriveMethod m_selectedDrive{DriveMethod::Tank};

private:
  void ConfigureBindings();
  void ConfigureDashboard();
};
