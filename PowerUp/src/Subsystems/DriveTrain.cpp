// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TeleopTankDrive.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    talonSRXMasterLeft = RobotMap::driveTrainTalonSRXMasterLeft;
    talonSRXMasterRight = RobotMap::driveTrainTalonSRXMasterRight;
    differentialDrive1 = RobotMap::driveTrainDifferentialDrive1;
    talonSRXSlaveLeft1 = RobotMap::driveTrainTalonSRXSlaveLeft1;
    talonSRXSlaveLeft2 = RobotMap::driveTrainTalonSRXSlaveLeft2;
    talonSRXSlaveRight1 = RobotMap::driveTrainTalonSRXSlaveRight1;
    talonSRXSlaveRight2 = RobotMap::driveTrainTalonSRXSlaveRight2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    InitMotors();
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new TeleopTankDrive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::Periodic() {
    // Put code here to be run every loop

}

void DriveTrain::InitMotors() {
	//Initialize slave motors to follower mode
	talonSRXSlaveLeft1->Set(ControlMode::Follower, 1.0);
	//talonSRXSlaveLeft2->Set(ControlMode::Follower, 1.0);
	talonSRXSlaveRight1->Set(ControlMode::Follower, 2.0);
	//talonSRXSlaveRight2->Set(ControlMode::Follower, 2.0);


	talonSRXMasterLeft->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	talonSRXMasterRight->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

	//Master motor direction configuration
	talonSRXMasterLeft->SetInverted(false);
	talonSRXMasterRight->SetInverted(false);
	talonSRXMasterLeft->SetSensorPhase(false);
	talonSRXMasterLeft->SetSensorPhase(false);

	//Master left and master right set control modes
	talonSRXMasterLeft->Set(ControlMode::PercentOutput, 0.0);
	talonSRXMasterRight->Set(ControlMode::PercentOutput, 0.0);




}

void DriveTrain::TankDrive(double leftSpeed, double rightSpeed) {

	differentialDrive1->TankDrive(leftSpeed, rightSpeed, true);
}

void DriveTrain::FillProfileBuffer(
		std::shared_ptr<const ProfileData> LeftWheel) {
	size_t i;
	TrajectoryPoint pt;

	pt.zeroPos = true;
	pt.isLastPoint = false;
	pt.profileSlotSelect0 = 0;

	talonSRXMasterRight->Set(SetValueMotionProfile::Disable);
	talonSRXMasterRight->Set(SetValueMotionProfile::Disable);
	talonSRXMasterLeft->ClearMotionProfileTrajectories();
	talonSRXMasterLeft->ClearMotionProfileHasUnderrun(0);
	talonSRXMasterRight->ClearMotionProfileTrajectories();
	talonSRXMasterRight->ClearMotionProfileHasUnderrun(0);

	for (i = 0; i < LeftWheel->size(); i++) {
		// check if this is the last point
		if ((i + 1) == LeftWheel->size()) {
			pt.isLastPoint = true;
		}

		pt.position = LeftWheel->at(i).at(0);
		pt.velocity = LeftWheel->at(i).at(1);
		pt.timeDur = (TrajectoryDuration)LeftWheel->at(i).at(2);
		if (!talonSRXMasterLeft->PushMotionProfileTrajectory(pt)) {
			printf("left can push failed\n");
		}

		// Negative position and velocity for right side
		pt.position = -pt.position;
		pt.velocity = -pt.velocity;
		if (!talonSRXMasterRight->PushMotionProfileTrajectory(pt)) {
			printf("right can push failed\n");
		}
		pt.zeroPos = false;
	}

}

void DriveTrain::FillProfileBuffer(std::shared_ptr<const ProfileData> LeftWheel,
		std::shared_ptr<const ProfileData> RightWheel) {
	size_t i;
	TrajectoryPoint pt;

	pt.zeroPos = true;
	pt.isLastPoint = false;
	pt.profileSlotSelect0 = 0;

	talonSRXMasterRight->Set(SetValueMotionProfile::Disable);
	talonSRXMasterRight->Set(SetValueMotionProfile::Disable);
	talonSRXMasterRight->ClearMotionProfileTrajectories();
	talonSRXMasterRight->ClearMotionProfileHasUnderrun(0);
	talonSRXMasterRight->ClearMotionProfileTrajectories();
	talonSRXMasterRight->ClearMotionProfileHasUnderrun(0);

	for (i = 0; i < LeftWheel->size(); i++) {
		// check if this is the last point
		if ((i + 1) == LeftWheel->size()) {
			pt.isLastPoint = true;
		}

		pt.position = LeftWheel->at(i).at(0);
		pt.velocity = LeftWheel->at(i).at(1);
		pt.timeDur = (TrajectoryDuration)LeftWheel->at(i).at(2);
		talonSRXMasterLeft->PushMotionProfileTrajectory(pt);

		// Use right wheel profile for right side
		pt.position = -RightWheel->at(i).at(0);
		pt.velocity = -RightWheel->at(i).at(1);
		pt.timeDur = (TrajectoryDuration)RightWheel->at(i).at(2);
		talonSRXMasterRight->PushMotionProfileTrajectory(pt);
		pt.zeroPos = false;
	}
}

void DriveTrain::ServiceMotionProfile() {
	talonSRXMasterLeft->ProcessMotionProfileBuffer();
	talonSRXMasterRight->ProcessMotionProfileBuffer();
}

void DriveTrain::SetChassisMode(ControlMode mode) {
	switch (mode) {
	case ControlMode::MotionProfile:
		SetMotionProfileMode();
		break;
	case ControlMode::Position:
		SetClosedLoopMode();
		break;
	case ControlMode::Velocity:
		SetVelocityMode();
		break;
	case ControlMode::MotionMagic:
		break;
	case ControlMode::PercentOutput:
	default:
		SetVoltagePercentMode();
		break;
	}
}

void DriveTrain::SetVelocityMode() {
	//SetMotorGains(1); ***
	talonSRXMasterLeft->Set(ControlMode::Velocity,0.0);
	talonSRXMasterLeft->Set(0.0);
	talonSRXMasterRight->Set(ControlMode::Velocity,0.0);
	talonSRXMasterRight->Set(0.0);
	//LeftLog->StartSession(); ***
	//RightLog->StartSession(); ***
}

void DriveTrain::SetClosedLoopMode() {
	talonSRXMasterLeft->Set(ControlMode::Position,0.0);
	talonSRXMasterRight->Set(ControlMode::Position,0.0);

	//SetRampRate(0.0); ***

	talonSRXMasterLeft->Set(0.0);

	talonSRXMasterRight->Set(0.0);
}

void DriveTrain::SetMotionProfileMode() {
	SetMotorGains(0);
	talonSRXMasterLeft->Set(ControlMode::MotionProfile, 0.0);
	//talonSRXMasterLeft->SetPosition(0.0);
	talonSRXMasterLeft->Set(SetValueMotionProfile::Disable);

	talonSRXMasterRight->Set(ControlMode::MotionProfile, 0.0);
	//talonSRXMasterRight->SetPosition(0.0);
	talonSRXMasterRight->Set(SetValueMotionProfile::Disable);

	LeftLog->StartSession();
	RightLog->StartSession();
	SetRampRate(0.0);
}

void DriveTrain::SetRampRate(double ramp) {

	//talonSRXMasterLeft->SetVoltageRampRate(ramp);
	//talonSRXSlaveLeft1->SetVoltageRampRate(ramp);
	//talonSRXSlaveLeft2->SetVoltageRampRate(ramp);
//	talonSRXMasterRight->SetVoltageRampRate(ramp);
//	talonSRXSlaveRight1->SetVoltageRampRate(ramp);
//	talonSRXSlaveRight2->
//	SetVoltageRampRate(ramp);
}

void DriveTrain::SetMotorGains(int idx) {
	talonSRXMasterLeft->SelectProfileSlot(idx);
	talonSRXMasterRight->SelectProfileSlot(idx);
}



// Put methods for controlling this subsystem
// here. Call these from Commands.

