// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	std::shared_ptr<frc::Joystick> joystickOperator;
	std::shared_ptr<frc::JoystickButton> joystickButtonBumperRight;
	std::shared_ptr<frc::JoystickButton> joystickButtonBumperLeft;
	std::shared_ptr<frc::JoystickButton> joystickButtonY;
	std::shared_ptr<frc::JoystickButton> joystickButtonX;
	std::shared_ptr<frc::JoystickButton> joystickButtonB;
	std::shared_ptr<frc::JoystickButton> joystickButtonA;
	std::shared_ptr<frc::Joystick> joystickDriverRight;
	std::shared_ptr<frc::Joystick> joystickDriverLeft;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::JoystickButton> leftDriverButtonLeft;


public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<frc::Joystick> getJoystickDriverLeft();
	std::shared_ptr<frc::Joystick> getJoystickDriverRight();
	std::shared_ptr<frc::Joystick> getJoystickOperator();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
