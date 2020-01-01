/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RotateTo.h"
#include "Robot.h"
#include "RobotMap.h"

int degrees = 90;
bool isFinished;

RotateTo::RotateTo(int deg) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::drivetrain);
  degrees = deg;
  isFinished = false;
}

// Called just before this Command runs the first time
void RotateTo::Initialize() {}
// Called repeatedly when this Command is scheduled to run
void RotateTo::Execute() 
{
  while(!Robot::drivetrain.RotateTo(degrees)){}
  isFinished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool RotateTo::IsFinished() { 
  return isFinished;
}

// Called once after isFinished returns true
void RotateTo::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateTo::Interrupted() {}

