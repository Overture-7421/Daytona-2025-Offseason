// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Arm.h"
#include "ArmConstants.h"
#include <iostream>
#include <cmath>
#include <frc/MathUtil.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>

Arm::Arm() {
    armMotor.setFusedCANCoder(12);
    armMotor.setRotorToSensorRatio(2);
    armMotor.configureMotionMagic(1_tps, 2_tr_per_s_sq, 3_tr_per_s_cu);
}

void Arm::moveArm(units::degree_t target){
    armMotor.SetControl(controlRequest.WithPosition(target).WithEnableFOC(true));
}

bool Arm::reached(units::degree_t position){
    units::degree_t difference = position - armMotor.GetPosition().GetValueAsDouble();  
    return (units::math::abs(difference) < 1_deg);
}

frc2::CommandPtr Arm::moveArmCmd(units::degree_t targetPos) {
    return frc2::FunctionalCommand(
        [this, targetPos]() {moveArm(targetPos);},

        [this]() {},

        [this](bool interrupted) {},
        
        [this, targetPos]() {return reached(targetPos);},

        {this}).ToPtr();
}


// This method will be called once per scheduler run
void Arm::Periodic() {}