// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Grabber.h"

GrabberSubsystem::GrabberSubsystem() {
};

void GrabberSubsystem::moveGrabber(units::volt_t target){
      grabberMotor.SetControl(grabberMotorRequest.WithOutput(target).WithEnableFOC(true));
};

bool GrabberSubsystem::isAlgaeIn(){
      return grabberMotor.GetStatorCurrent().GetValueAsDouble() > GrabberConstants::Algae::CurrentLimit;

};

frc2::CommandPtr GrabberSubsystem::SetVoltage(units::volt_t target) {
    return frc2::FunctionalCommand(
        // Init
        [this, target] { SetVoltage(target); },
        // onExecute
        [this] { },
        // onEnd
        [this] (bool interrupted) { },
        // isFinished
        [this, target] { return true; }
    ).ToPtr();
}