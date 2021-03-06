/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ScissorControl.h"

ScissorControl::ScissorControl(bool Raise) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intake.get());
	mRaise = Raise;
}

// Called once when the command executes
void ScissorControl::Initialize() {
	if (mRaise) {
		Robot::intake->ScissorRaise();
	}
	else {
		Robot::intake->ScissorLower();
	}
}
