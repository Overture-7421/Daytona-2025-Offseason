// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/FunctionalCommand.h>
#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "ElevatorConstants.h"
#include <ctre/phoenix6/controls/MotionMagicVoltage.hpp>

class Elevator : public frc2::SubsystemBase {
 public:
  Elevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void moveElevator(units::meter_t target);
  
  units::meter_t getElevatorPosition();

  bool reached(units::meter_t position);

  frc2::CommandPtr moveElevatorCmd(units::meter_t targetPos);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  OverTalonFX elevatorMotor {ElevatorConstants::elevatorMotorConfig(), "rio"};
  OverTalonFX secondElevatorMotor {ElevatorConstants::secondElevatorMotorConfig(), "rio"};
  MotionMagicVoltage controlRequest{0_tr};
};
