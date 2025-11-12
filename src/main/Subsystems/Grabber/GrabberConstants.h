// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/MotorControllers/OverTalonFX/Config.h"
#include "OvertureLib/Sensors/OverCANCoder/OverCANCoder.h"
#include "OvertureLib/Sensors/OverCANCoder/Config.h"

namespace GrabberConstants {

OverTalonFXConfig getMotorConstants(){
    OverTalonFXConfig grabberConstants;
    
    grabberConstants.MotorId = 1; // Example motor ID, change as needed

    grabberConstants.NeutralMode = ControllerNeutralMode::Brake;
    grabberConstants.Inverted = false; // Set to true if the motor is inverted
    grabberConstants.useFOC = false; // Set to true if using Field Oriented Control

    grabberConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
    
    grabberConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
    grabberConstants.StatorCurrentLimit = 40_A; // Example stator current limit
    grabberConstants.TriggerThreshold = 50_A; // Example trigger threshold
    grabberConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
    grabberConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
    grabberConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

    return grabberConstants;
}

CanCoderConfig getCANCodeConfig(){

    CanCoderConfig grabberCANCoder;
    
    grabberCANCoder.CanCoderId = -1;
    grabberCANCoder.Offset = 0_deg;
    grabberCANCoder.SensorDirection = ctre::phoenix6::signals::SensorDirectionValue:: CounterClockwise_Positive;

    return grabberCANCoder;
}

namespace Coral{
    double CurrentLimit = 35;
}

namespace Algae{
    double CurrentLimit = 35;
}

}



