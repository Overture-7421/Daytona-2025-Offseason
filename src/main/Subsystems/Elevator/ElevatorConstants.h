// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/Sensors/OverCANCoder/OverCANCoder.h"

namespace ElevatorConstants {
  constexpr const OverTalonFXConfig elevatorMotorConfig() {
    OverTalonFXConfig elevatorMotorConfig;

    elevatorMotorConfig.MotorId = 1;
    elevatorMotorConfig.NeutralMode = ControllerNeutralMode::Brake;
    elevatorMotorConfig.Inverted = false;
    elevatorMotorConfig.useFOC = true;

    elevatorMotorConfig.PIDConfigs.WithKS(2).WithKV(2).WithKA(3).WithKP(2).WithKI(1).WithKD(2).WithKS(2);

    elevatorMotorConfig.CurrentLimit = 0_A;
    elevatorMotorConfig.StatorCurrentLimit = 0_A;
    elevatorMotorConfig.TriggerThreshold = 0_A;
    elevatorMotorConfig.TriggerThresholdTime = 0_s;
    elevatorMotorConfig.ClosedLoopRampRate = 0_s;
    elevatorMotorConfig.OpenLoopRampRate = 0_s;

    

    return elevatorMotorConfig;
  };

  constexpr const OverTalonFXConfig secondElevatorMotorConfig() {
    OverTalonFXConfig secondElevatorMotorConfig;

    secondElevatorMotorConfig.MotorId = 2;
    secondElevatorMotorConfig.NeutralMode = ControllerNeutralMode::Brake;
    secondElevatorMotorConfig.Inverted = true;
    secondElevatorMotorConfig.useFOC = true;

    secondElevatorMotorConfig.PIDConfigs.WithKS(2).WithKV(2).WithKA(3).WithKP(2).WithKI(1).WithKD(2).WithKS(2);

    secondElevatorMotorConfig.CurrentLimit = 0_A;
    secondElevatorMotorConfig.StatorCurrentLimit = 0_A;
    secondElevatorMotorConfig.TriggerThreshold = 0_A;
    secondElevatorMotorConfig.TriggerThresholdTime = 0_s;
    secondElevatorMotorConfig.ClosedLoopRampRate = 0_s;
    secondElevatorMotorConfig.OpenLoopRampRate = 0_s;

    return secondElevatorMotorConfig;
  };

  constexpr const units::meter_t diameter = 0.07366_m;
};
