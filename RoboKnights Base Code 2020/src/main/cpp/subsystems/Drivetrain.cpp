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
  SetDefaultCommand(new DefaultDrive());
}

void Drivetrain::MecanumDrive(double x, double y, double rot)
{
  mecanumDrive.DriveCartesian(x * 0.5, y * 0.5, rot * 0.5);
}