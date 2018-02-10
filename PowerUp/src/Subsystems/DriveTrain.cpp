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
    powerDistributionPanel = RobotMap::driveTrainPowerDistributionPanel;

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
	talonSRXSlaveLeft1->Set(ControlMode::Follower, 4.0);
	talonSRXSlaveLeft2->Set(ControlMode::Follower, 4.0);
	talonSRXSlaveRight1->Set(ControlMode::Follower, 1.0);
	talonSRXSlaveRight2->Set(ControlMode::Follower, 1.0);


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
	case ControlMode::PercentOutput:
	default:
		SetVoltagePercentMode();
		break;
	}
}

void DriveTrain::SetVelocityMode() {
	SetMotorGains(1, 0);
	talonSRXMasterLeft->Set(ControlMode::Velocity,0.0);
	talonSRXMasterLeft->Set(0.0);
	talonSRXMasterRight->Set(ControlMode::Velocity,0.0);
	talonSRXMasterRight->Set(0.0);

}

void DriveTrain::SetClosedLoopMode() {
	talonSRXMasterLeft->Set(ControlMode::Position,0.0);
	talonSRXMasterRight->Set(ControlMode::Position,0.0);

	talonSRXMasterLeft->Set(0.0);

	talonSRXMasterRight->Set(0.0);
}

void DriveTrain::SetMotionProfileMode() {
	SetMotorGains(0, 0);
	talonSRXMasterLeft->Set(ControlMode::MotionProfile, 0.0);
	talonSRXMasterLeft->Set(SetValueMotionProfile::Disable);

	talonSRXMasterRight->Set(ControlMode::MotionProfile, 0.0);
	talonSRXMasterRight->Set(SetValueMotionProfile::Disable);
}

void DriveTrain::SetMotorGains(int idx, int pidIdx) {
	talonSRXMasterLeft->SelectProfileSlot(idx, pidIdx);
	talonSRXMasterRight->SelectProfileSlot(idx, pidIdx);
}

void DriveTrain::SetVoltagePercentMode(){
	talonSRXMasterLeft->Set(ControlMode::PercentOutput, 0.0);
	talonSRXMasterRight->Set(ControlMode::PercentOutput, 0.0);
}

void DriveTrain::ResetChassisYaw() {
//	if (gyro->IsConnected()) {
//		gyro->Reset();
//	}
}

void DriveTrain::SetMotionProfileState(ControlMode mode) {
	if (talonSRXMasterLeft->GetControlMode()
			== ControlMode::MotionProfile) {
		talonSRXMasterLeft->Set(mode, 0.0);
	}
	if (talonSRXMasterRight->GetControlMode()
			== ControlMode::MotionProfile) {
		talonSRXMasterRight->Set(mode, 0.0);
	}
}
void DriveTrain::SetChassisWheelVelocity(double left, double right) {
	if ((talonSRXMasterLeft->GetControlMode()
			== ControlMode::Velocity)
			&& (talonSRXMasterRight->GetControlMode()
					== ControlMode::Velocity)) {
		talonSRXMasterLeft->Set(left);
		talonSRXMasterRight->Set(-right);
	}
}

bool DriveTrain::MotionProfileComplete() {
//	bool Complete = false;
//
//	talonSRXMasterLeft->GetMotionProfileStatus(LeftStatus);
//	talonSRXMasterRight->GetMotionProfileStatus(RightStatus);
//
//#ifdef DEBUG_TALON
//	printf("Remaining top buffer points:  %d\n", LeftStatus.topBufferRem);
//	printf("Bottom buffer count:  %d\n", LeftStatus.btmBufferCnt);
//	printf("IsUnderrun status:  %d\n", LeftStatus.isUnderrun);
//#endif
//
//	// Start motion profile processing after 5 points are in talon buffer
//	if ((!mMotionProcessingActive) && (LeftStatus.btmBufferCnt > 5)) {
//		SetMotionProfileState(
//				CANTalon::SetValueMotionProfile::SetValueMotionProfileEnable);
//		mMotionProcessingActive = true;
//	}
//
//	if ((LeftStatus.activePointValid && LeftStatus.activePoint.isLastPoint)
//			&& (RightStatus.activePointValid
//					&& RightStatus.activePoint.isLastPoint)) {
//		Complete = true;
//		mMotionProcessingActive = false;
//	}
//
//	return Complete;
	return false;
}

void DriveTrain::TankDriveWithTriggers(double Left, double Right, double Trigger) {
//	double newLeft = 0.0;
//	double newRight = 0.0;   WORK IN PROGRESS
//	double ProcessedLeft = Left;
//	double ProcessedRight = Right;
//	double fExponent = 1.0;
//
//	ProcessedLeft = DEADBAND(AxisPower(ProcessedLeft, fExponent), 0.07);
//
//	ProcessedRight = DEADBAND(AxisPower(ProcessedRight, fExponent), 0.07);
//
//	ProcessedLeft = MapStick(ProcessedLeft);
//	ProcessedRight = MapStick(ProcessedRight);
//
//	newLeft = fmax(fmin(ProcessedLeft + (Trigger * .8), 1.0), -1.0);
//	newRight = fmax(fmin(ProcessedRight + (Trigger * .8), 1.0), -1.0);
//
//	// Select velocity mode or throttle mode
//	if (kDriveVelocityMode) {
//		SetChassisMode(ControlMode::Velocity);
//	} else {
//		SetChassisMode(ControlMode::PercentOutput);
//	}
//
//	// Determine if we are using gyro corrected straight movement
//	if ((ProcessedLeft == 0.0) && (ProcessedRight == 0.0)) {
//		if (DEADBAND(Trigger, 0.10) == 0.0) {
//			ResetChassisYaw();
//			bDriveStraight = true;
//		}
//	} else {
//		bDriveStraight = false;
//	}
//
//	if (bDriveStraight) {
//		if (kDriveVelocityMode) {
//			Trigger *= kDriveMaxVelocity;
//			printf("Speed: %f    Error:  %d\n", Trigger,
//					talonSRXMasterLeft->GetClosedLoopError());
//		}
//		DriveStraight(Trigger * 0.8f);
//	} else {
//		if (kDriveVelocityMode) {
//			newLeft *= kDriveMaxVelocity;
//			newRight *= kDriveMaxVelocity;
//			printf("Speed: %f    Error:  %d\n", newLeft,
//					talonSRXMasterLeft->GetClosedLoopError());
//		}
//		if (!mReverseDrive) {
//			robotDrive->TankDrive(newLeft, newRight, false);
//		} else {
//			robotDrive->TankDrive(-newRight, -newLeft, false);
//		}
//	}
//	//cANTalonSlaveRight->Set(2);
//	//cANTalonSlaveLeft->Set(1);
}

//double DriveTrain::MapStick(double stick) {
//	double NewStick = fabs(stick);
//
//	if (NewStick < kStickBreak) {
//		NewStick = (NewStick / kStickBreak) * kThrottleBreak;
//	} else {
//		NewStick = kThrottleBreak
//				+ ((1 - NewStick) / (1 - kStickBreak)) * (1 - kThrottleBreak);
//	}
//
//	if (stick < 0.0) {
//		NewStick = -NewStick;
//	}
//
//	return NewStick;
//}

// Put methods for controlling this subsystem
// here. Call these from Commands.

