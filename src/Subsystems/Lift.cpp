/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Lift.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"

Lift::Lift() : Subsystem("Lift"), lift(new TalonSRX(LIFT_MOTOR_PORT)) {
	lift->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 10);
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveLift());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
TalonSRX* Lift::getLift() {
	return lift;
}

void Lift::moveLift(double speed) {
	lift->Set(ControlMode::PercentOutput, speed);
}

void Lift::resetEncoder() {
	lift->SetSelectedSensorPosition(0, 0, 10);
}

double Lift::getRelativePosition() {
	return lift->GetSensorCollection().GetQuadraturePosition()/4096 * 10;//4096 ticks per rev, 10 inch circumference
}
