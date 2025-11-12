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



namespace IntakeConstants {

    constexpr static const double PivotRotorToSensorRatio = 77.841;
    constexpr static const double PivotCANCoderId = 27;

    constexpr static const units::turns_per_second_t PivotMMCruiseVelocity =  4.0_tps ;
    constexpr static const units::turns_per_second_squared_t PivotMMAcceleration = 42_tr_per_s_sq;
    constexpr static const units::turns_per_second_cubed_t PivotMMJerk = 0.0_tr_per_s_cu;
    
OverTalonFXConfig IntakeConstants(){
    OverTalonFXConfig intakeConstants;
    
    intakeConstants.MotorId = 1; // Example motor ID, change as needed


    intakeConstants.NeutralMode = ControllerNeutralMode::Brake;
    intakeConstants.Inverted = false; // Set to true if the motor is inverted
    intakeConstants.useFOC = false; // Set to true if using Field Oriented Control


    intakeConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
    


    intakeConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
    intakeConstants.StatorCurrentLimit = 40_A; // Example stator current limit
    intakeConstants.TriggerThreshold = 50_A; // Example trigger threshold
    intakeConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
    intakeConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
    intakeConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

    return intakeConstants;
}

CanCoderConfig getCANCodeConfig(){

    CanCoderConfig pivotCANCoder;
    
    pivotCANCoder.CanCoderId = -1;
    pivotCANCoder.Offset = 0_deg;
    pivotCANCoder.SensorDirection = ctre::phoenix6::signals::SensorDirectionValue:: CounterClockwise_Positive;

    return pivotCANCoder;
}

OverTalonFXConfig RollerConstants(){
    OverTalonFXConfig rollerConstants;
    
    rollerConstants.MotorId = 1; // Example motor ID, change as needed


    rollerConstants.NeutralMode = ControllerNeutralMode::Brake;
    rollerConstants.Inverted = false; // Set to true if the motor is inverted
    rollerConstants.useFOC = false; // Set to true if using Field Oriented Control


    rollerConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
    


    rollerConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
    rollerConstants.StatorCurrentLimit = 40_A; // Example stator current limit
    rollerConstants.TriggerThreshold = 50_A; // Example trigger threshold
    rollerConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
    rollerConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
    rollerConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

    return rollerConstants;
}



OverTalonFXConfig CentersConstants(){
    OverTalonFXConfig centersConstants;
    
    centersConstants.MotorId = 1; // Example motor ID, change as needed


    centersConstants.NeutralMode = ControllerNeutralMode::Brake;
    centersConstants.Inverted = false; // Set to true if the motor is inverted
    centersConstants.useFOC = false; // Set to true if using Field Oriented Control


    centersConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
    


    centersConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
    centersConstants.StatorCurrentLimit = 40_A; // Example stator current limit
    centersConstants.TriggerThreshold = 50_A; // Example trigger threshold
    centersConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
    centersConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
    centersConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

    return centersConstants;

    
}



units::angle::turn_t Stow = 0_deg;



}



