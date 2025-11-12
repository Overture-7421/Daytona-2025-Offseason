// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Elevator.h"



ElevatorSubsystem::ElevatorSubsystem(){
    rightMotor.setRotorToSensorRatio(ElevatorConstants::RightRotorToSensorRatio);
    rightMotor.configureMotionMagic(ElevatorConstants::RightMMCruiseVelocity, ElevatorConstants::RightMMAcceleration, ElevatorConstants::RightMMJerk);

    leftMotor.setRotorToSensorRatio(ElevatorConstants::LeftRotorToSensorRatio);
    leftMotor.setFollow(rightMotor.GetDeviceID(), true); 

    rightMotor.SetPosition(0_tr);
    leftMotor.SetPosition(0_tr);
};

void ElevatorSubsystem::moveElevator(units::meter_t target_in_meters){
    units::degree_t target_in_degrees = units::degree_t(target_in_meters.value()/(ElevatorConstants::Diameter.value()*M_PI));
    rightMotor.SetControl(rightPositionRequest.WithPosition(target_in_degrees).WithEnableFOC(true));
};

bool ElevatorSubsystem::isElevatorFinished(units::meter_t target_in_meters){
    units::degree_t target_in_degrees = units::degree_t(target_in_meters.value()/(ElevatorConstants::Diameter.value()*M_PI));
    return units::math::abs(rightMotor.GetPosition().GetValue() - target_in_degrees.value())<1.0_deg;
}

units::meter_t ElevatorSubsystem::elevatorGetPosition(){
    units::degree_t target_in_meters = units::meter_t(rightMotor.GetPosition().GetValue()*(ElevatorConstants::Diameter.value()*M_PI));
    return target_in_meters;
}

frc2::CommandPtr ElevatorSubsystem::SetPosition(units::meter_t target) {
    return frc2::FunctionalCommand(
        // Init
        [this, target] { moveElevator(target); },
        // onExecute
        [this] { },
        // onEnd
        [this] (bool interrupted) { },
        // isFinished
        [this, target] { return isElevatorFinished(target);; }
    ).ToPtr();
}
