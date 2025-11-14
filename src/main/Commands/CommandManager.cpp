#include "CommandManager.h"



CommandManager::CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake){
    this -> elevator = elevator;

    
    
};

frc2::CommandPtr CommandManager::Sustain(){
    return frc2::cmd::Sequence(
        elevator->SetPosition(1_m),
        frc2::cmd::Wait(500_ms),
        arm->SetPosition(-90_deg)
    );
}

frc2::CommandPtr CommandManager::Intake(){
    return frc2::cmd::Parallel(
            intake -> pivotSetPosition(0_deg),
            intake -> moveRollers(6_V),
            intake -> moveCenters(7_V)
    );
}