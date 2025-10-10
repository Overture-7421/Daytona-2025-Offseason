// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Elevator.h"
#include <frc/MathUtil.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>

Elevator::Elevator(){
    secondElevatorMotor.setFollow(1, true);
    elevatorMotor.setSensorToMechanism(2);
    secondElevatorMotor.setSensorToMechanism(2);
    elevatorMotor.configureMotionMagic(1_tps, 2_tr_per_s_sq, 3_tr_per_s_cu);
    secondElevatorMotor.configureMotionMagic(1_tps, 2_tr_per_s_sq, 3_tr_per_s_cu);
};

void Elevator::moveElevator(units::meter_t target){
    units::turn_t rotations = target / M_PI * ElevatorConstants::diameter;
    elevatorMotor.SetControl(controlRequest.WithPosition(rotations).WithEnableFOC(true));
}

units::meter_t Elevator::getElevatorPosition(){
    units::meter_t position = elevatorMotor.GetPosition().GetValueAsDouble() * M_PI * ElevatorConstants::diameter;
}

bool Elevator::reached(units::meter_t position){
    units::meter_t difference = position - getElevatorPosition();
    return(units::math::abs(difference) < 0.01_m);
}

frc2::CommandPtr Elevator::moveElevatorCmd(units::meter_t targetPos){
    return frc2::FunctionalCommand (
        [this, targetPos]() {moveElevator(targetPos);},

        [this]() {},

        [this](bool interrupted) {},

        [this, targetPos]() {return reached(targetPos);}

    ).ToPtr();
}

// This method will be called once per scheduler run
void Elevator::Periodic() {}
