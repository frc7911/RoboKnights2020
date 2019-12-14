/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DefaultDrive.h"
#include "Robot.h"
#include "RobotMap.h"

DefaultDrive::DefaultDrive() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::drivetrain);
}

// Called just before this Command runs the first time
void DefaultDrive::Initialize() {
  
}

// Called repeatedly when this Command is scheduled to run
void DefaultDrive::Execute() 
{
    //get x, y, and z from the joystick
    double x = Robot::oi.getAxis(4);
    double y = Robot::oi.getAxis(1);
    double rot = Robot::oi.getAxis(0);

    //drive using the MecanumDrive in the drivetrain object
    Robot::drivetrain.MecanumDrive(x, y, rot);
}

// Make this return true when this Command no longer needs to run execute()
bool DefaultDrive::IsFinished() { 
  return false;
}

// Called once after isFinished returns true
void DefaultDrive::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultDrive::Interrupted() {
}

