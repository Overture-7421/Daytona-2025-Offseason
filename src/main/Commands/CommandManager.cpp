#include "CommandManager.h"
#include "CommandManagerConstants.h"


using namespace Constants;

CommandManager::CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake){
    this -> elevator = elevator;

    
    
};



frc2::CommandPtr CommandManager::GroundAlgae(){
    return frc2::cmd::Parallel(
        elevator->SetPosition(Elevator::GroundAlgae),
         arm->SetPosition(Arm::GroundAlgae),
         grabber->SetVoltage(Grabber::GroundAlgae)
    );
};

frc2::CommandPtr CommandManager::HoldAlgae(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::HoldAlgae),
            elevator->SetPosition(Elevator::HoldAlgae)
        ),
        grabber->SetVoltage(Grabber::HoldAlgae)
    );
};

frc2::CommandPtr CommandManager::L2Back(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::L2Back),
            arm->SetPosition(Arm::L2Back)),
        grabber->SetVoltage(Grabber::L2Back)
    );
};

frc2::CommandPtr CommandManager::L3Back(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::L3Back),
            arm->SetPosition(Arm::L3Back)),
        grabber->SetVoltage(Grabber::L3Back)
    );
};

frc2::CommandPtr CommandManager::L4Back(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::L4Back),
            arm->SetPosition(Arm::L4Back)),
        grabber->SetVoltage(Grabber::L4Back)
    );
};

frc2::CommandPtr CommandManager::L2BackConfirm(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::L2BackConfirm),
            elevator->SetPosition(Elevator::L2BackConfirm)),
        grabber->SetVoltage(Grabber::L2BackConfirm)
    );
};

frc2::CommandPtr CommandManager::L3BackConfirm(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::L3BackConfirm),
            elevator->SetPosition(Elevator::L3BackConfirm)),
        grabber->SetVoltage(Grabber::L3BackConfirm)
    );
};

frc2::CommandPtr CommandManager::L4BackConfirm(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::L4BackConfirm),
            elevator->SetPosition(Elevator::L4BackConfirm)),
        grabber->SetVoltage(Grabber::L4BackConfirm)
    );
};

frc2::CommandPtr CommandManager::Net(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::Net),
            elevator->SetPosition(Elevator::Net)),
        grabber->SetVoltage(Grabber::Net)
    );
};

frc2::CommandPtr CommandManager::NetConfirm(){
    return frc2::cmd::Sequence(
        arm->SetPosition(Arm::NetConfirm),
        grabber->SetVoltage(Grabber::NetConfirm)
    );
};

frc2::CommandPtr CommandManager::HighAlgae(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::HighAlgae),
            arm->SetPosition(Arm::HighAlgae)),
        grabber->SetVoltage(Grabber::HighAlgae)
    );
};

frc2::CommandPtr CommandManager::LowAlgae(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::LowAlgae),
            arm->SetPosition(Arm::LowAlgae)),
        grabber->SetVoltage(Grabber::LowAlgae)
    );
};

frc2::CommandPtr CommandManager::LowAlgae(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::Source),
            arm->SetPosition(Arm::Source)),
        grabber->SetVoltage(Grabber::Source)
        );
};

frc2::CommandPtr CommandManager::L1(){
    return frc2::cmd::Sequence(
        intake->pivotSetPosition(Intake::Pivot::L1),
        intake->rollersSetVoltage(Intake::Roller::L1)
    );
};

frc2::CommandPtr CommandManager::L1Confirm(){
    return frc2::cmd::Sequence(
        intake->rollersSetVoltage(Intake::Roller::L1Confirm)
    );
};

frc2::CommandPtr CommandManager::L2(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::L2),
            arm->SetPosition(Arm::L2)),
        grabber->SetVoltage(Grabber::L2)
    );
};

frc2::CommandPtr CommandManager::L2Confirm(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::L2Confirm),
            elevator->SetPosition(Elevator::L2Confirm)),
        grabber->SetVoltage(Grabber::L2Confirm)
    );
};

frc2::CommandPtr CommandManager::L3(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::L3),
            arm->SetPosition(Arm::L3)),
        grabber->SetVoltage(Grabber::L3)
    );
};

frc2::CommandPtr CommandManager::L3Confirm(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::L3Confirm),
            elevator->SetPosition(Elevator::L3Confirm)),
        grabber->SetVoltage(Grabber::L3Confirm)
    );
};

frc2::CommandPtr CommandManager::L4(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::L4),
            arm->SetPosition(Arm::L4)),
        grabber->SetVoltage(Grabber::L4)
    );
};

frc2::CommandPtr CommandManager::L4Confirm(){
    return frc2::cmd::Parallel(
        frc2::cmd::Sequence(
            arm->SetPosition(Arm::L4Confirm),
            elevator->SetPosition(Elevator::L4Confirm)),
        grabber->SetVoltage(Grabber::L4Confirm)
    );
};

frc2::CommandPtr CommandManager::HoldCoral(){
    return frc2::cmd::Parallel(
        intake->rollersSetVoltage(Intake::Roller::HoldCoral),
        grabber->SetVoltage(Grabber::HoldCoral),
        frc2::cmd::Sequence(
            elevator->SetPosition(Elevator::HoldCoral),
            frc2::cmd::Parallel(
                intake->pivotSetPosition(Intake::Pivot::HoldCoral),
                arm->SetPosition(Arm::HoldCoral)
            )
        )
    );
};

