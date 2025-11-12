// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "IntakeConstants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Subsystem.h>
#include <frc/MathUtil.h>
#include <units/voltage.h> // Include the proper header for units
#include <frc2/command/Commands.h>


class IntakeSubsystem : public frc2::SubsystemBase {
 public:

  IntakeSubsystem();
  
  void moveCenters(units::volt_t target);
  void movePivot(units::degree_t target);
  void moveRollers(units::volt_t target);

  bool isCentersFinished(units::volt_t target);
  bool isPivotFinished(units::degree_t target);
  bool isRollersFinished(units::volt_t target);

  units::degree_t pivotGetPosition();

  frc2::CommandPtr rollersSetVoltage(units::volt_t target);
  frc2::CommandPtr pivotSetPosition(units::degree_t target);
  frc2::CommandPtr centersSetVoltage(units::volt_t target);


  private:
    VoltageOut rollersMotorRequest{ 0_V };
    VoltageOut centersMotorRequest{ 0_V};
    MotionMagicVoltage pivotPositionRequest{0_tr};

    OverTalonFX pivotMotor {IntakeConstants::IntakeConstants(), "rio"};
    OverTalonFX centersMotor {IntakeConstants::RollerConstants(), "rio"};
    OverTalonFX rollersMotor {IntakeConstants::CentersConstants(), "rio"};  
};
