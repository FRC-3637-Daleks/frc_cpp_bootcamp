#include "Drivebase.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include <units/length.h>
#include <units/angle.h>
#include <units/mass.h>

#include <ctre/phoenix6/CANBus.hpp>

using namespace ctre::phoenix6;

namespace {

CANBus kBus = CANBus::RoboRIO();

constexpr auto kGearing = 14.0;
constexpr auto kFeedbackConfigs = configs::FeedbackConfigs{}
  .WithSensorToMechanismRatio(kGearing);

constexpr auto kMotorConfig = configs::TalonFXConfiguration{}
  .WithFeedback(configs::FeedbackConfigs{}
    .WithSensorToMechanismRatio(kGearing))
  .WithCurrentLimits(configs::CurrentLimitsConfigs{}
    .WithSupplyCurrentLimit(40_A));

constexpr auto kWheelDiam = 8_in;
constexpr auto kWheelCircum = std::numbers::pi*kWheelDiam;
constexpr auto kDistancePerRotation = kWheelCircum/1_tr;

constexpr auto kMass = 60_lb;
constexpr auto kTrackWidth = 2.5_ft;
constexpr auto kMOI = kMass*kTrackWidth*kTrackWidth/4/2;
}


Drivebase::Drivebase()
  : m_leftMotor(1, kBus)
  , m_rightMotor(3, kBus)
  , m_leftFollower(2, kBus)
  , m_rightFollower(4, kBus)
  , m_imu(1, kBus)
  , m_odom(0_rad, 0_m, 0_m)

  // sim
  , m_simState{
    frc::DCMotor::KrakenX60(2)
    , kGearing
    , kMOI
    , kMass
    , kWheelDiam/2
    , kTrackWidth
  }
  , m_leftSim{m_leftMotor}
  , m_rightSim{m_rightMotor}
  , m_imuSim{m_imu}
{
  m_leftMotor.GetConfigurator().Apply(kMotorConfig);
  m_rightMotor.GetConfigurator().Apply(kMotorConfig);

  m_leftFollower.SetControl(
    controls::Follower{
      m_leftMotor.GetDeviceID(),
      signals::MotorAlignmentValue::Aligned
    }
  );
  m_rightFollower.SetControl(
    controls::Follower{
      m_rightMotor.GetDeviceID(),
      signals::MotorAlignmentValue::Aligned
    }
  );

  frc::SmartDashboard::PutData(&m_fieldWidget);
}

void Drivebase::Periodic() {
  m_odom.Update(
    m_imu.GetYaw().GetValue(),
    m_leftMotor.GetPosition().GetValue()*kDistancePerRotation,
    m_rightMotor.GetPosition().GetValue()*kDistancePerRotation
  );

  m_fieldWidget.SetRobotPose(m_odom.GetPose());
}

void Drivebase::SetSpeeds(float left_throttle, float right_throttle) {
  m_leftMotor.SetControl(controls::DutyCycleOut(left_throttle));
  m_rightMotor.SetControl(controls::DutyCycleOut(right_throttle));
}

float Drivebase::GetX() {
  return m_odom.GetPose().X().value();
}

float Drivebase::GetY() {
  return m_odom.GetPose().Y().value();
}

float Drivebase::GetHeading() {
  return m_odom.GetPose().Rotation().Degrees().value();
}

void Drivebase::SimulationPeriodic() {
  m_leftSim.SetSupplyVoltage(12_V);
  m_rightSim.SetSupplyVoltage(12_V);
  m_imuSim.SetSupplyVoltage(12_V);
  m_simState.SetInputs(m_leftSim.GetMotorVoltage(), m_rightSim.GetMotorVoltage());

  m_simState.Update(20_ms);

  m_leftSim.SetRawRotorPosition(m_simState.GetLeftPosition()/kDistancePerRotation*kGearing);
  m_rightSim.SetRawRotorPosition(m_simState.GetRightPosition()/kDistancePerRotation*kGearing);
  m_leftSim.SetRotorVelocity(m_simState.GetLeftVelocity()/kDistancePerRotation*kGearing);
  m_rightSim.SetRotorVelocity(m_simState.GetRightVelocity()/kDistancePerRotation*kGearing);
  m_imuSim.SetRawYaw(m_simState.GetHeading().Degrees());
}