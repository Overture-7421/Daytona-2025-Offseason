#include "Subsystems/Arm/Arm.cpp"
#include "Subsystems/Elevator/Elevator.cpp"
#include "Subsystems/Grabber/Grabber.cpp"
#include "Subsystems/IntakeSubsystem/IntakeSubsystem.cpp"



class CommandManager {
public:

CommandManager(ArmSubsystem *arm, ElevatorSubsystem *elevator, GrabberSubsystem *grabber, IntakeSubsystem *intake);


frc2::CommandPtr MoveElevator();
frc2::CommandPtr MoveElevatorAndArm();


private:
ArmSubsystem *arm = nullptr;
ElevatorSubsystem *elevator = nullptr;
GrabberSubsystem *grabber = nullptr;
IntakeSubsystem *intake = nullptr;

};

