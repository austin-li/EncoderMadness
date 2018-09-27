/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "RobotMap.h"

OI::OI(): leftStick(new Joystick(LEFT_JOYSTICK_PORT)),
		rightStick(new Joystick(RIGHT_JOYSTICK_PORT)),
		liftStick(new Joystick(LIFT_JOYSTICK_PORT)) {
	// Process operator interface input here.
}

Joystick* OI::getLeft() {
	return leftStick;
}

Joystick* OI::getRight() {
	return rightStick;
}

Joystick* OI::getLift() {
	return liftStick;
}
