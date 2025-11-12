// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "ArmConstants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Subsystem.h>
#include <frc/MathUtil.h>
#include <units/voltage.h> // Include the proper header for units
#include <frc2/command/Commands.h>


class ArmSubsystem : public frc2::SubsystemBase {
 public:

  ArmSubsystem();
  
  
  void moveArm(units::degree_t target);

  bool isArmFinished(units::degree_t target);

  units::degree_t armGetPosition();

  frc2::CommandPtr SetPosition(units::degree_t target);
  


  private:
    MotionMagicVoltage armPositionRequest{0_tr};

    OverTalonFX armMotor {ArmConstants::ArmConstants(), "rio"};
};
