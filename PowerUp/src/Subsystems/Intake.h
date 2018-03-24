// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef INTAKE_H
#define INTAKE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */

typedef enum {
	left, right, both
} intakeModeType;

class Intake: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::SpeedController> leftIntakeWheel;
	std::shared_ptr<frc::SpeedController> rightIntakeWheel;
	std::shared_ptr<frc::DoubleSolenoid> intakeDoubleSolenoid;
	std::shared_ptr<frc::Compressor> compressor;
	std::shared_ptr<frc::DigitalInput> lSLeft;
	std::shared_ptr<frc::DigitalInput> lSRight;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	const double kIntakeSpeed;
	const double kOuttakeSpeed;
	std::shared_ptr<frc::DoubleSolenoid> climberDoubleSolenoid;

public:
	Intake();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

//	typedef enum {
//		left, right, both
//	} intakeModeType;

//	intakeModeType intakeMode;

	void OpenIntake();
	void CloseIntake();
	bool IntakeIsClosed();
	void IntakeFwd();
	void IntakeFwd(intakeModeType intakeMode, double speed);
	void IntakeRev();
	void IntakeRev(intakeModeType intakeMode, double speed);
	void IntakeOff();
	void IntakeOff(intakeModeType intakeMode);

	bool getIntakeLSLeft();
	bool getIntakeLSRight();
};

#endif
