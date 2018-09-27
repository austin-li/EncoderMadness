/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

#include "MoveLift.h"
#include "Robot.h"

MoveLift::MoveLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::lift);
}

// Called just before this Command runs the first time
void MoveLift::Initialize() {
	Robot::lift->resetEncoder();
}

// Called repeatedly when this Command is scheduled to run
void MoveLift::Execute() {
	Robot::lift->moveLift(Robot::oi->getLift()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLift::IsFinished() {
	return Robot::lift->getLift()->GetSensorCollection().IsFwdLimitSwitchClosed();
}

// Called once after isFinished returns true
void MoveLift::End() {
	std::cout << Robot::lift->getRelativePosition() << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLift::Interrupted() {

}
