
#include "OvertureLib/MotorControllers/OverTalonFX/OverTalonFX.h"
#include "OvertureLib/MotorControllers/OverTalonFX/Config.h"
#include "OvertureLib/Sensors/OverCANCoder/OverCANCoder.h"
#include "OvertureLib/Sensors/OverCANCoder/Config.h"


namespace Constants{
    namespace Arm{
        units::degree_t GroundAlgae = 100_deg;
        units::degree_t HoldAlgae = 90_deg;
        units::degree_t L2Back = 30_deg;
        units::degree_t L3Back = 30_deg;
        units::degree_t L4Back = 30_deg;
        units::degree_t L2BackConfirm = 45_deg;
        units::degree_t L3BackConfirm = 45_deg;
        units::degree_t L4BackConfirm = 45_deg;
        units::degree_t Net = 0_deg;
        units::degree_t NetConfirm = 45_deg;
        units::degree_t HighAlgae = 0_deg;
        units::degree_t LowAlgae = 0_deg;
        units::degree_t Source = -20_deg;
        units::degree_t L2 = 30_deg;
        units::degree_t L2Confirm = 45_deg;
        units::degree_t L3 = 30_deg;
        units::degree_t L3Confirm = 45_deg;
        units::degree_t L4 = 30_deg;
        units::degree_t L4Confirm = 45_deg;
        units::degree_t HoldCoral = 0_deg;
        


    }

    namespace Elevator { 
        units::meter_t GroundAlgae = 0.1_m;
        units::meter_t HoldAlgae = 0.1_m;
        units::meter_t L2Back = 0.3_m;
        units::meter_t L3Back = 0.6_m;
        units::meter_t L4Back = 1.1_m;
        units::meter_t L2BackConfirm = 0.1_m;
        units::meter_t L3BackConfirm = 0.4_m;
        units::meter_t L4BackConfirm = 0.7_m;
        units::meter_t Net = 1.5_m;
        units::meter_t HighAlgae = 0.75_m;
        units::meter_t LowAlgae = 0.25_m;
        units::meter_t LowAlgae = 0.5_m;
        units::meter_t Source = 0.5_m;
        units::meter_t L2 = 0.3_m;
        units::meter_t L2Confirm = 0.1_m;
        units::meter_t L3 = 0.6_m;
        units::meter_t L3Confirm = 0.4_m;
        units::meter_t L4 = 1.1_m;
        units::meter_t L4Confirm = 0.7_m;
        units::meter_t HoldCoral = 0.4_m;


    }
    
    namespace Grabber{
        units::volt_t GroundAlgae = 9_V;
        units::volt_t HoldAlgae = 5_V;
        units::volt_t L2Back = 3_V;
        units::volt_t L3Back = 3_V;
        units::volt_t L4Back = 3_V;
        units::volt_t L2BackConfirm = 1_V;
        units::volt_t L3BackConfirm = 1_V;
        units::volt_t L4BackConfirm = 1_V;
        units::volt_t Net = 3_V;
        units::volt_t NetConfirm = -3_V;
        units::volt_t HighAlgae = 9_V;
        units::volt_t LowAlgae = 9_V;
        units::volt_t Source = 9_V;
        units::volt_t L2 = 3_V;
        units::volt_t L2Confirm = 3_V;
        units::volt_t L3 = 3_V;
        units::volt_t L3Confirm = 1_V;
        units::volt_t L4 = 3_V;
        units::volt_t L4Confirm = 1_V;
        units::volt_t HoldCoral = 1_V;


    }
    namespace Intake{
        namespace Pivot{
            units::degree_t L1 = 20_deg;
            units::degree_t HoldCoral = 20_deg;
            
        }

        namespace Roller{
            units::volt_t L1 = 1_V;
            units::volt_t L1Confirm = -5_V;
            units::volt_t HoldCoral = -1_V;
        }

        namespace Center{

        }

    }
    
}