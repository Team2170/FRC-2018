// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <math.h>

#define PI 3.141592653589793238462643383279502884
#define DEG PI/180
#define ENCODER_COUNTS_PER_REV 1440
#define ROTATION_DEG 360

/**
 *
 *
 * @author ExampleAuthor
 */
class Arm: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::DigitalInput> limitSwitchFront;
	std::shared_ptr<frc::DigitalInput> limitSwitchBack;
	std::shared_ptr<frc::DigitalInput> opticalFlagSensor;
	std::shared_ptr<WPI_TalonSRX> talonSRXArmMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Arm();
	void InitDefaultCommand() override;
	void Periodic() override;

	bool readLimitSwitchFront();
	bool readLimitSwitchBack();

	int readArmEncoder();
	void resetArmEncoder();


	double getArmPosition();

	bool readArmOpticalFlagSensor();

	void stopArmMotor();
	void setArmMotorSpeed(double speed);

	void activateSolenoid(bool onOff);

	double getArmMotorTemp();

	double setArmPosition(double alphaFinalRad);

	double encoderCountsToDeg(int encoderCounts);
	double degToEncoderCounts(double degrees);
	double RadSecToNativeUnits(double nativeValue);

	void setMotorControl(int mode, double value);
	double getArmMotorVelocity();
	double NativeUnitsToRadSec(double nativeUnits);

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
