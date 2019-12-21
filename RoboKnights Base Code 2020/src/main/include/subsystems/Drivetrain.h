/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

#include "frc/WPILib.h"

#include "RobotMap.h"

#include "ctre/Phoenix.h"

class Drivetrain : public frc::Subsystem {
 public:
  Drivetrain();
  void InitDefaultCommand() override;
  void MecanumDrive(double x, double y, double rot);
  void AlignTo(double degrees);

 private:
  //Motor Controllers
  WPI_VictorSPX leftFront{DRIVE_FRONT_LEFT};
  WPI_VictorSPX leftBack{DRIVE_BACK_LEFT};
  WPI_VictorSPX rightFront{DRIVE_FRONT_RIGHT};
  WPI_VictorSPX rightBack{DRIVE_BACK_RIGHT};

  //Sensors
  PigeonIMU mainGyro{GYROSCOPE_ID};

  //MecanumDrive
  frc::MecanumDrive mecanumDrive{leftFront, leftBack, rightFront, rightBack};
};
