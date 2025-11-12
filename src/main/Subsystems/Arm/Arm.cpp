// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Arm.h"

// Grabber.cpp


ArmSubsystem::ArmSubsystem(){
    armMotor.setRotorToSensorRatio(ArmConstants::ArmRotorToSensorRatio);
    armMotor.setFusedCANCoder(ArmConstants::ArmCANCoderId);
    armMotor.configureMotionMagic(ArmConstants::ArmMMCruiseVelocity, ArmConstants::ArmMMAcceleration, ArmConstants::ArmMMJerk);
};


void ArmSubsystem::moveArm(units::degree_t target){
    armMotor.SetControl(armPositionRequest.WithPosition(target).WithEnableFOC(true));
};

bool ArmSubsystem::isArmFinished(units::degree_t target){
    return units::math::abs(armMotor.GetPosition().GetValue() - target.value())<1.0_deg;
}

units::degree_t ArmSubsystem::armGetPosition(){
     return armMotor.GetPosition().GetValue();
}



frc2::CommandPtr ArmSubsystem::SetPosition(units::degree_t target) {
    return frc2::FunctionalCommand(
        // Init
        [this, target] { moveArm(target); },
        // onExecute
        [this] { },
        // onEnd
        [this] (bool interrupted) { },
        // isFinished
        [this, target] { return isArmFinished(target); }
    ).ToPtr();
}