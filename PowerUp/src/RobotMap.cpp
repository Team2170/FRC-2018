// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainTalonSRXMasterLeft;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainTalonSRXMasterRight;
std::shared_ptr<frc::DifferentialDrive> RobotMap::driveTrainDifferentialDrive1;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainTalonSRXSlaveLeft1;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainTalonSRXSlaveLeft2;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainTalonSRXSlaveRight1;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveTrainTalonSRXSlaveRight2;
std::shared_ptr<frc::PowerDistributionPanel> RobotMap::driveTrainPowerDistributionPanel;
std::shared_ptr<frc::SpeedController> RobotMap::intakeLeftIntakeWheel;
std::shared_ptr<frc::SpeedController> RobotMap::intakeRightIntakeWheel;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::intakeIntakeDoubleSolenoid;
std::shared_ptr<frc::Compressor> RobotMap::intakeCompressor;
std::shared_ptr<frc::DigitalInput> RobotMap::intakeLSLeft;
std::shared_ptr<frc::DigitalInput> RobotMap::intakeLSRight;
std::shared_ptr<frc::DigitalInput> RobotMap::armLimitSwitchFront;
std::shared_ptr<frc::DigitalInput> RobotMap::armLimitSwitchBack;
std::shared_ptr<frc::DigitalInput> RobotMap::armOpticalFlagSensor;
std::shared_ptr<WPI_TalonSRX> RobotMap::armTalonSRXArmMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    driveTrainTalonSRXMasterLeft.reset(new WPI_TalonSRX(4));
    
    
    driveTrainTalonSRXMasterRight.reset(new WPI_TalonSRX(1));
    
    
    driveTrainDifferentialDrive1.reset(new frc::DifferentialDrive(*driveTrainTalonSRXMasterLeft, *driveTrainTalonSRXMasterRight));
    lw->AddActuator("DriveTrain", "Differential Drive 1", driveTrainDifferentialDrive1);
    driveTrainDifferentialDrive1->SetSafetyEnabled(true);
        driveTrainDifferentialDrive1->SetExpiration(0.1);
        driveTrainDifferentialDrive1->SetMaxOutput(1.0);

    driveTrainTalonSRXSlaveLeft1.reset(new WPI_TalonSRX(5));
    
    
    driveTrainTalonSRXSlaveLeft2.reset(new WPI_TalonSRX(6));
    
    
    driveTrainTalonSRXSlaveRight1.reset(new WPI_TalonSRX(2));
    
    
    driveTrainTalonSRXSlaveRight2.reset(new WPI_TalonSRX(3));
    
    
    driveTrainPowerDistributionPanel.reset(new frc::PowerDistributionPanel(0));
    lw->AddSensor("DriveTrain", "PowerDistributionPanel", driveTrainPowerDistributionPanel);
    
    intakeLeftIntakeWheel.reset(new frc::Spark(0));
    lw->AddActuator("Intake", "Left Intake Wheel", std::static_pointer_cast<frc::Spark>(intakeLeftIntakeWheel));
    
    intakeRightIntakeWheel.reset(new frc::Spark(1));
    lw->AddActuator("Intake", "Right Intake Wheel", std::static_pointer_cast<frc::Spark>(intakeRightIntakeWheel));
    
    intakeIntakeDoubleSolenoid.reset(new frc::DoubleSolenoid(20, 0, 1));
    lw->AddActuator("Intake", "Intake Double Solenoid", intakeIntakeDoubleSolenoid);
    
    intakeCompressor.reset(new frc::Compressor(20));
    lw->AddActuator("Intake", "Compressor", intakeCompressor);
    
    intakeLSLeft.reset(new frc::DigitalInput(3));
    lw->AddSensor("Intake", "LS Left", intakeLSLeft);
    
    intakeLSRight.reset(new frc::DigitalInput(4));
    lw->AddSensor("Intake", "LS Right", intakeLSRight);
    
    armLimitSwitchFront.reset(new frc::DigitalInput(0));
    lw->AddSensor("Arm", "Limit Switch Front", armLimitSwitchFront);
    
    armLimitSwitchBack.reset(new frc::DigitalInput(1));
    lw->AddSensor("Arm", "Limit Switch Back", armLimitSwitchBack);
    
    armOpticalFlagSensor.reset(new frc::DigitalInput(5));
    lw->AddSensor("Arm", "Optical Flag Sensor", armOpticalFlagSensor);
    
    armTalonSRXArmMotor.reset(new WPI_TalonSRX(7));
    
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
