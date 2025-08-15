// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/Sensors/OverCANCoder/OverCANCoder.h"

namespace ArmConstants {

  constexpr const OverTalonFXConfig getArmMotorConfig() {
    OverTalonFXConfig armMotorConfig;

    armMotorConfig.MotorId = 1;
    armMotorConfig.NeutralMode = ControllerNeutralMode::Brake;
    armMotorConfig.Inverted = false;
    armMotorConfig.useFOC = false;

    armMotorConfig.PIDConfigs.WithKP(2);
    armMotorConfig.PIDConfigs.WithKI(1);
    armMotorConfig.PIDConfigs.WithKD(0);

    armMotorConfig.CurrentLimit = 0_A;
    armMotorConfig.StatorCurrentLimit = 0_A;
    armMotorConfig.TriggerThreshold = 0_A;
    armMotorConfig.TriggerThresholdTime = 0_s;
    armMotorConfig.ClosedLoopRampRate = 0_s;
    armMotorConfig.OpenLoopRampRate = 0_s;

    return armMotorConfig;
  };

  constexpr const CanCoderConfig getEncoderConfig() {
    CanCoderConfig armEncoder;

    armEncoder.CanCoderId = 1;
    
    armEncoder.SensorDirection.Clockwise_Positive;

    armEncoder.Offset = 0_deg;
    
    return armEncoder;
  }
};
