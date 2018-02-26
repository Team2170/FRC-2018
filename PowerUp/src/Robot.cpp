// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Commands/ArmInitialize.h"
#include "Commands/NoCommand.h"
#include "Commands/AutonomousInitGroup.h"
#include "Commands/AutonomousMotionProfile.h"
#include "Commands/AutonomousSwitchGroup.h"
#include "AutoMoves/Straight.h"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Arm> Robot::arm;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<frc::Timer> Robot::BlendTimer;

void Robot::RobotInit() {
	RobotMap::init();
	BlendTimer.reset(new frc::Timer());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    intake.reset(new Intake());
    arm.reset(new Arm());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS


	chooser.AddDefault("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	frc::SmartDashboard::PutData("Auto Modes", &chooser);

	chooser.AddDefault("A Do Nothing", new NoCommand());
	chooser.AddObject("ZZ Auto Test TEMPORARY",
			new AutonomousMotionProfile(&AutoMove_Straight_L));
		chooser.AddObject("C Blue Middle Right",
				new AutonomousSwitchGroup(AutonomousSwitchGroup::kBlueMiddleRight));
		chooser.AddObject("D Blue Middle Left",
				new AutonomousSwitchGroup(AutonomousSwitchGroup::kBlueMiddleLeft));
		chooser.AddObject("E Red Middle Right",
				new AutonomousSwitchGroup(AutonomousSwitchGroup::kRedMiddleRight));
		chooser.AddObject("F Red Middle Left",
						new AutonomousSwitchGroup(AutonomousSwitchGroup::kRedMiddleLeft));
		chooser.AddObject("G AutonomousCommand",
						new AutonomousCommand());


	Robot::arm->resetArmEncoder();
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	UpdateSmartDash();
}

void Robot::AutonomousInit() {
	std::string switchScalePositions = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	char switchPosition = switchScalePositions[0];
	autonomousCommand = chooser.GetSelected();

	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
	UpdateSmartDash();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	UpdateSmartDash();
}

START_ROBOT_CLASS(Robot);

void Robot::UpdateSmartDash() {
	double velocity = Robot::arm->getArmMotorVelocity();
	double velocityRadSec = Robot::arm->NativeUnitsToRadSec(velocity);
	SmartDashboard::PutNumber("Arm Speed [rad/sec]", velocityRadSec);
	SmartDashboard::PutBoolean("Limit Switch Front", Robot::arm->readLimitSwitchFront());
	SmartDashboard::PutBoolean("Reverse Direction", Robot::driveTrain->isReverseDrive());
	SmartDashboard::PutBoolean("Limit Switch Back", Robot::arm->readLimitSwitchBack());
	SmartDashboard::PutNumber("Arm Motor Temp degC", Robot::arm->getArmMotorTemp());
	SmartDashboard::PutNumber("Arm Encoder Count", Robot::arm->readArmEncoder());
	SmartDashboard::PutNumber("Arm Position [radians]", Robot::arm->getArmPosition());

}

