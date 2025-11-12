// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/MotorControllers/OverTalonFX/Config.h"
#include "OvertureLib/Sensors/OverCANCoder/OverCANCoder.h"
#include "OvertureLib/Sensors/OverCANCoder/Config.h"
#include <units/angular_velocity.h>
#include <units/angular_acceleration.h>
#include <units/angular_jerk.h>



namespace ArmConstants {

    constexpr static const double ArmRotorToSensorRatio = 77.841;
    constexpr static const double ArmCANCoderId = 27;

    constexpr static const units::turns_per_second_t ArmMMCruiseVelocity =  4.0_tps ;
    constexpr static const units::turns_per_second_squared_t ArmMMAcceleration = 42_tr_per_s_sq;
    constexpr static const units::turns_per_second_cubed_t ArmMMJerk = 0.0_tr_per_s_cu;
    
OverTalonFXConfig ArmConstants(){
    OverTalonFXConfig armConstants;
    
    armConstants.MotorId = 1; // Example motor ID, change as needed


    armConstants.NeutralMode = ControllerNeutralMode::Brake;
    armConstants.Inverted = false; // Set to true if the motor is inverted
    armConstants.useFOC = false; // Set to true if using Field Oriented Control


    armConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
    


    armConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
    armConstants.StatorCurrentLimit = 40_A; // Example stator current limit
    armConstants.TriggerThreshold = 50_A; // Example trigger threshold
    armConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
    armConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
    armConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

    return armConstants;
}

CanCoderConfig getCANCodeConfig(){

    CanCoderConfig armCANCoder;
    
    armCANCoder.CanCoderId = -1;
    armCANCoder.Offset = 0_deg;
    armCANCoder.SensorDirection = ctre::phoenix6::signals::SensorDirectionValue:: CounterClockwise_Positive;

    return armCANCoder;
}
}