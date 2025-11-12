// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>
#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/Sensors/OverCANCoder/OverCANCoder.h"
#include "ArmConstants.h"
#include <ctre/phoenix6/controls/MotionMagicVoltage.hpp>

class Arm : public frc2::SubsystemBase {
 public:
  Arm();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void moveArm(units::degree_t target);

  bool reached(units::degree_t position);

  frc2::CommandPtr moveArmCmd(units::degree_t targetPos);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
  OverTalonFX armMotor {ArmConstants::armMotorConfig(), "rio"};
  OverCANCoder armEncoder {ArmConstants::armEncoderConfig(), "rio"};
  MotionMagicVoltage controlRequest{0_tr};
};
