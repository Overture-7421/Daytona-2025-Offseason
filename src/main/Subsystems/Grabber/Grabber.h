// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "GrabberConstants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Subsystem.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <units/voltage.h> // Include the proper header for units
#include <frc2/command/Subsystem.h>
#include <frc2/command/Commands.h>


class GrabberSubsystem : public frc2::SubsystemBase {
 public:          
  GrabberSubsystem();

  void moveGrabber(units::volt_t target);

  bool isAlgaeIn();


  

  frc2::CommandPtr grabberSetVoltage(units::volt_t target);


  private:
  VoltageOut grabberMotorRequest{ 0_V };
  OverTalonFX grabberMotor {GrabberConstants::getMotorConstants(), "rio"};
};





