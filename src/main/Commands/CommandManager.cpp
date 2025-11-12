#include "CommandManager.h"



CommandManager::CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake){
    this -> elevator = elevator;

    
    
};

frc2::CommandPtr CommandManager::MoveElevator(){
    return frc2::cmd::Sequence(
        elevator->SetPosition(1_m),
        elevator->SetPosition(0_m)
        );
    };

frc2::CommandPtr CommandManager::MoveElevatorAndArm(){
    return frc2::cmd::Sequence(
        frc2::cmd::Parallel(
            elevator->SetPosition(1_m),
            arm->SetPosition(-90_deg)
        ),
        frc2::cmd::Wait(500_ms),
        frc2::cmd::Parallel(
            elevator->SetPosition(1_m),
            arm->SetPosition(-90_deg)    
        )
    );
}