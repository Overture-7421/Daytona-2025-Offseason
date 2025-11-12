// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "IntakeSubsystem.h"

// Grabber.cpp


IntakeSubsystem::IntakeSubsystem(){
    pivotMotor.setRotorToSensorRatio(IntakeConstants::PivotRotorToSensorRatio);
    pivotMotor.setFusedCANCoder(IntakeConstants::PivotCANCoderId);
    pivotMotor.configureMotionMagic(IntakeConstants::PivotMMCruiseVelocity, IntakeConstants::PivotMMAcceleration, IntakeConstants::PivotMMJerk);
};

void IntakeSubsystem::moveCenters(units::volt_t target){
    centersMotor.SetControl(centersMotorRequest.WithOutput(target).WithEnableFOC(true));
};
void IntakeSubsystem::moveRollers(units::volt_t target){
    rollersMotor.SetControl(rollersMotorRequest.WithOutput(target).WithEnableFOC(true));
};
void IntakeSubsystem::movePivot(units::degree_t target){
    pivotMotor.SetControl(pivotPositionRequest.WithPosition(target).WithEnableFOC(true));
};

bool IntakeSubsystem::isPivotFinished(units::degree_t target){
    return units::math::abs(pivotMotor.GetPosition().GetValue() - target.value())<1.0_deg;
}

units::degree_t IntakeSubsystem::pivotGetPosition(){
     return pivotMotor.GetPosition().GetValue();
}

frc2::CommandPtr IntakeSubsystem::rollersSetVoltage(units::volt_t target) {
    return frc2::FunctionalCommand(
        // Init
        [this, target] { moveRollers(target); },
        // onExecute
        [this] { },
        // onEnd
        [this] (bool interrupted) { },
        // isFinished
        [this] { return true; }
    ).ToPtr();
}
frc2::CommandPtr IntakeSubsystem::centersSetVoltage(units::volt_t target) {
    return frc2::FunctionalCommand(
        // Init
        [this, target] { moveCenters(target); },
        // onExecute
        [this] { },
        // onEnd
        [this] (bool interrupted) { },
        // isFinished
        [this] { return true; }
    ).ToPtr();
}
frc2::CommandPtr IntakeSubsystem::pivotSetPosition(units::degree_t target) {
    return frc2::FunctionalCommand(
        // Init
        [this, target] { movePivot(target); },
        // onExecute
        [this] { },
        // onEnd
        [this] (bool interrupted) { },
        // isFinished
        [this, target] { return isPivotFinished(target); }
    ).ToPtr();
}