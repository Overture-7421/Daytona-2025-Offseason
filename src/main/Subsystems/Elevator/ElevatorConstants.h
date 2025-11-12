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



namespace ElevatorConstants {

    constexpr static const double RightRotorToSensorRatio = 77.841;
    constexpr static const double RightCANCoderId = 27;

    constexpr static const units::turns_per_second_t RightMMCruiseVelocity =  4.0_tps ;
    constexpr static const units::turns_per_second_squared_t RightMMAcceleration = 42_tr_per_s_sq;
    constexpr static const units::turns_per_second_cubed_t RightMMJerk = 0.0_tr_per_s_cu;
    
    OverTalonFXConfig RightConstants(){
        OverTalonFXConfig rightConstants;
        
        rightConstants.MotorId = 1; // Example motor ID, change as needed


        rightConstants.NeutralMode = ControllerNeutralMode::Brake;
        rightConstants.Inverted = false; // Set to true if the motor is inverted
        rightConstants.useFOC = false; // Set to true if using Field Oriented Control


        rightConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
        


        rightConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
        rightConstants.StatorCurrentLimit = 40_A; // Example stator current limit
        rightConstants.TriggerThreshold = 50_A; // Example trigger threshold
        rightConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
        rightConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
        rightConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

        return rightConstants;
}

     CanCoderConfig getRightCANCodeConfig(){

        CanCoderConfig rightCANCoder;
        
        rightCANCoder.CanCoderId = -1;
        rightCANCoder.Offset = 0_deg;
        rightCANCoder.SensorDirection = ctre::phoenix6::signals::SensorDirectionValue:: CounterClockwise_Positive;

        return rightCANCoder;
    }


    constexpr static const double LeftRotorToSensorRatio = 77.841;
    constexpr static const double LeftCANCoderId = 27;

    constexpr static const units::turns_per_second_t LeftMMCruiseVelocity =  4.0_tps ;
    constexpr static const units::turns_per_second_squared_t LeftMMAcceleration = 42_tr_per_s_sq;
    constexpr static const units::turns_per_second_cubed_t LeftMMJerk = 0.0_tr_per_s_cu;
    
    OverTalonFXConfig LeftConstants(){
        OverTalonFXConfig leftConstants;
        
        leftConstants.MotorId = 1; // Example motor ID, change as needed


        leftConstants.NeutralMode = ControllerNeutralMode::Brake;
        leftConstants.Inverted = false; // Set to true if the motor is inverted
        leftConstants.useFOC = false; // Set to true if using Field Oriented Control


        leftConstants.PIDConfigs.WithKP(0.0).WithKI(0.0).WithKI(0.0);
        


        leftConstants.CurrentLimit = 30_A; // Example current limit, adjust as needed
        leftConstants.StatorCurrentLimit = 40_A; // Example stator current limit
        leftConstants.TriggerThreshold = 50_A; // Example trigger threshold
        leftConstants.TriggerThresholdTime = 0.5_s; // Example trigger threshold time
        leftConstants.ClosedLoopRampRate = 0.1_s; // Example closed loop ramp rate
        leftConstants.OpenLoopRampRate = 0.1_s; // Example open loop ramp rate

        return leftConstants;
}

     CanCoderConfig getLeftCANCodeConfig(){

        CanCoderConfig leftCANCoder;
        
        leftCANCoder.CanCoderId = -1;
        leftCANCoder.Offset = 0_deg;
        leftCANCoder.SensorDirection = ctre::phoenix6::signals::SensorDirectionValue:: CounterClockwise_Positive;

        return leftCANCoder;
    }

    constexpr static const units::meter_t Diameter = 0.1_m;
}


