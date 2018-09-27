/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "Commands/MoveLift.h"

class Lift : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* lift;
public:
	Lift();
	void InitDefaultCommand() override;
	TalonSRX* getLift();
	void moveLift(double speed);
	void resetEncoder();
	double getRelativePosition();
};

