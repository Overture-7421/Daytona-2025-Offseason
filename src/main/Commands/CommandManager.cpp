#include "CommandManager.h"
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandPtr.h>



CommandManager::CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake){
    this -> elevator = elevator;

    
    
};

frc2::CommandPtr CommandManager::L1(){
    return frc2::cmd::Parallel(
        intake->pivotSetPosition(45_deg)
    );  
}
frc2::CommandPtr CommandManager::L1Confirm(){
    return frc2::cmd::Parallel(
        intake->rollersSetVoltage(5_V)
    );
}

frc2::CommandPtr CommandManager::L2(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(0.5_m),
        arm->SetPosition(120_deg)
    );
}

frc2::CommandPtr CommandManager::L2Confirm(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(0.5_m),
        arm->SetPosition(135_deg)
    );
}

frc2::CommandPtr CommandManager::L3(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(1_m),
        arm->SetPosition(120_deg)
    );
}
frc2::CommandPtr CommandManager::L3Confrim(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(1_m),
        arm->SetPosition(135_deg)
    );
}

frc2::CommandPtr CommandManager::L4(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(2_m),
        arm->SetPosition(135_deg)
    );
}
frc2::CommandPtr CommandManager::L4Confirm(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(2_m),
        arm->SetPosition(170_deg)
    );
}

frc2::CommandPtr CommandManager::Sustain(){
    return frc2::cmd::Sequence(
        elevator->SetPosition(1_m),
        arm->SetPosition(-90_deg),
        frc2::cmd::Wait(500_ms)
    );
}

frc2::CommandPtr CommandManager::Intake(){
    return frc2::cmd::Parallel(
        intake->pivotSetPosition(0_deg),
        intake->centersSetVoltage(7_V),
        intake->rollersSetVoltage(7_V)
    );
}

frc2::CommandPtr CommandManager::Initial(){
    return frc2::cmd::Sequence(
        arm -> SetPosition(90_deg),
        elevator -> SetPosition(0_m),
        intake -> pivotSetPosition(90_deg)
    );
}

frc2::CommandPtr CommandManager::Processor(){
    return frc2::cmd::Sequence(
        intake -> pivotSetPosition(45_deg),
        frc2::cmd::Wait(300_ms),
        frc2::cmd::Parallel(
        elevator -> SetPosition(0.3_m),
        arm->SetPosition(190_deg)
        )
    );
}

frc2::CommandPtr CommandManager::ProcessorConfirm(){
    return frc2::cmd::Sequence(
        intake -> pivotSetPosition(45_deg),
        frc2::cmd::Wait(300_ms),
        frc2::cmd::Parallel(
            elevator -> SetPosition(0.3_m),
            arm->SetPosition(190_deg)
        ),
        frc2::cmd::Wait(500_ms),
        grabber -> grabberSetVoltage(-6_V)
    );
}

frc2::CommandPtr CommandManager::twoPiece(){
    
}