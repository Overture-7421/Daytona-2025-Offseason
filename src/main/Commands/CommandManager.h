#include "Subsystems/Arm/Arm.cpp"
#include "Subsystems/Elevator/Elevator.cpp"
#include "Subsystems/Grabber/Grabber.cpp"
#include "Subsystems/IntakeSubsystem/IntakeSubsystem.cpp"



class CommandManager {
public:

CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake);

frc2::CommandPtr L1();
frc2::CommandPtr L2();
frc2::CommandPtr L3();
frc2::CommandPtr L4();
frc2::CommandPtr L1Confirm();
frc2::CommandPtr L2Confirm();
frc2::CommandPtr L3Confrim();
frc2::CommandPtr L4Confirm();
frc2::CommandPtr holdCoral();
frc2::CommandPtr Sustain();
frc2::CommandPtr Processor();
frc2::CommandPtr ProcessorConfirm();
frc2::CommandPtr Intake();
frc2::CommandPtr twoPiece();
frc2::CommandPtr Initial();


private:
ArmSubsystem *arm = nullptr;
ElevatorSubsystem *elevator = nullptr;
GrabberSubsystem *grabber = nullptr;
IntakeSubsystem *intake = nullptr;

};

