#include "Subsystems/Arm/Arm.cpp"
#include "Subsystems/Elevator/Elevator.cpp"
#include "Subsystems/Grabber/Grabber.cpp"
#include "Subsystems/IntakeSubsystem/IntakeSubsystem.cpp"



class CommandManager {
public:

CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake);


frc2::CommandPtr GroundAlgae();
frc2::CommandPtr HoldAlgae();
frc2::CommandPtr L2Back();
frc2::CommandPtr L3Back();
frc2::CommandPtr L4Back();
frc2::CommandPtr L2BackConfirm();
frc2::CommandPtr L3BackConfirm();
frc2::CommandPtr L4BackConfirm();
frc2::CommandPtr Net();
frc2::CommandPtr NetConfirm();
//No hay climber
frc2::CommandPtr HighAlgae();
frc2::CommandPtr LowAlgae();
frc2::CommandPtr Source();

//emini's commands
frc2::CommandPtr L1();
frc2::CommandPtr L1Confirm();
frc2::CommandPtr L2();
frc2::CommandPtr L2Confirm();
frc2::CommandPtr L3();
frc2::CommandPtr L3Confirm();
frc2::CommandPtr L4();
frc2::CommandPtr L4Confirm();
frc2::CommandPtr HoldCoral();






private:
ArmSubsystem *arm = nullptr;
ElevatorSubsystem *elevator = nullptr;
GrabberSubsystem *grabber = nullptr;
IntakeSubsystem *intake = nullptr;

};

