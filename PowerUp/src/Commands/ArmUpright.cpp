// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ArmUpright.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ArmUpright::ArmUpright(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::arm.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ArmUpright::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmUpright::Execute() {
	bool limitSwitchFrontValue = Robot::arm->readLimitSwitchFront();
	bool limitSwitchBackValue = Robot::arm->readLimitSwitchBack();

	int kArmSpeed = 100;							// Verify and possibly change this value
	int middleCount = 0;

	if (limitSwitchFrontValue != true && limitSwitchBackValue != true) {
			// if arm is forward of center arm axis, move arm backwards until centered
			int encoderCounts = Robot::arm->readArmEncoder();

			// Encoder +: Arm closer to front
			// Encoder -: Arm closer to back
			while (encoderCounts < middleCount) {
				Robot::arm->setArmMotorSpeed(kArmSpeed);
				encoderCounts = Robot::arm->readArmEncoder();
			}
			Robot::arm->stopArmMotor();

			while (encoderCounts > middleCount) {
				Robot::arm->setArmMotorSpeed(-kArmSpeed);
			}
			Robot::arm->stopArmMotor();
			// if arm is backward of center arm axis, move arm forwards until centered
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmUpright::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void ArmUpright::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUpright::Interrupted() {

}
