// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "ElevatorConstants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Subsystem.h>
#include <frc/MathUtil.h>
#include <units/voltage.h> // Include the proper header for units
#include <frc2/command/Commands.h>


class ElevatorSubsystem : public frc2::SubsystemBase {
 public:

  ElevatorSubsystem();
  

  void moveElevator(units::meter_t target);
  

  bool isElevatorFinished(units::meter_t target);


  units::meter_t elevatorGetPosition();


  frc2::CommandPtr SetPosition(units::meter_t target);
  


  private:
   
    MotionMagicVoltage rightPositionRequest{0_tr};
    MotionMagicVoltage leftPositionRequets{0_tr};

    OverTalonFX rightMotor {ElevatorConstants::RightConstants(), "rio"};
    OverTalonFX leftMotor {ElevatorConstants::LeftConstants(), "rio"};
    
};
