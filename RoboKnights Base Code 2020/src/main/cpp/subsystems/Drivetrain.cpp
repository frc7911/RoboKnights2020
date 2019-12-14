/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

#include "commands/DefaultDrive.h"

#include "RobotMap.h"

#include "WPILib.h"

#include <iostream>

using namespace std;

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain"){}

void Drivetrain::InitDefaultCommand() 
{
  //set the default command to regular driving
  SetDefaultCommand(new DefaultDrive());
}

void Drivetrain::MecanumDrive(double x, double y, double rot)
{
  //Use FRCs method for mecanum driving
  mecanumDrive.DriveCartesian(x * MAX_SPEED, y * MAX_SPEED, rot * MAX_SPEED);
}