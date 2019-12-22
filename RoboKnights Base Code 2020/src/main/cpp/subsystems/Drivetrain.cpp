/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

#include "commands/DefaultDrive.h"

#include <frc/PIDController.h>

#include "RobotMap.h"

#include <frc/WPILib.h>

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
  double gyroReading = mainGyro.GetFusedHeading();
  if(gyroReading >= 360)
  {
    mainGyro.SetFusedHeading(0);
  }
  if(gyroReading <= -360)
  {
    mainGyro.SetFusedHeading(0);
  }
  mecanumDrive.DriveCartesian(x * MAX_SPEED, y * MAX_SPEED, rot * MAX_SPEED);
}

double Drivetrain::GetGyroAngle()
{
  double gyroAngle;
  gyroAngle = mainGyro.GetFusedHeading();
  if(gyroAngle >= 360)
  {
    mainGyro.SetFusedHeading(0);
    gyroAngle = 0;
  }
  if(gyroAngle <= -360)
  {
    mainGyro.SetFusedHeading(0);
    gyroAngle = 0;
  }
  return gyroAngle;
}

bool Drivetrain::RotateTo(double setpoint)
{
  //Setup PID variables
  double integral, previous_error, error, derivative, pidValue, gyroReading;

  //get the reading of the gyro, MIGHT HAVE TO ADD ABS()
  gyroReading = GetGyroAngle();

  //If the gyro reading is not withing 1 degree...
  if((gyroReading <= (setpoint - 1)) || (gyroReading >= setpoint + 1))
  {
    
    //Get the gyro angle
    gyroReading = GetGyroAngle();

    //PID stuffs
    error = (setpoint - gyroReading);
    integral += (error * 0.2);
    derivative = ((error - previous_error) / 0.2);
    pidValue = (ROT_P * error) + (ROT_I * integral) + (ROT_D * derivative);

    mecanumDrive.DriveCartesian(0,0, pidValue);

    //since it is not within 1 degree, return false
    return false;

  }else 
  {
    //It is within 1 degree, so we return true
    return true;
  }
}