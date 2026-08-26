#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/simulation/DifferentialDrivetrainSim.h>
#include <frc/smartdashboard/Field2d.h>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/sim/TalonFXSimState.hpp>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <ctre/phoenix6/sim/Pigeon2SimState.hpp>

class Drivebase: public frc2::SubsystemBase {
public:
  Drivebase();

public:
  void Periodic() override;

public:
  void SetSpeeds(float left_throttle, float right_throttle);
  float GetX();
  float GetY();
  float GetHeading();

private:
  ctre::phoenix6::hardware::TalonFX m_leftMotor, m_rightMotor, m_leftFollower, m_rightFollower;
  ctre::phoenix6::hardware::Pigeon2 m_imu;
  frc::DifferentialDriveOdometry m_odom;

private:
  frc::Field2d m_fieldWidget;

private:
  frc::sim::DifferentialDrivetrainSim m_simState;
  ctre::phoenix6::sim::TalonFXSimState m_leftSim, m_rightSim;
  ctre::phoenix6::sim::Pigeon2SimState m_imuSim;

public:
  void SimulationPeriodic() override;
};