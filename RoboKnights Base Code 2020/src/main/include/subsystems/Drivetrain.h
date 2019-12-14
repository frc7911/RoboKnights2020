/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

#include "WPILib.h"

#include "RobotMap.h"

class Drivetrain : public frc::Subsystem {
 public:
  Drivetrain();
  void InitDefaultCommand() override;
  void MecanumDrive(double x, double y, double rot);

 private:
  frc::VictorSP leftFront{DRIVE_FRONT_LEFT};
  frc::VictorSP leftBack{DRIVE_BACK_LEFT};
  frc::VictorSP rightFront{DRIVE_FRONT_RIGHT};
  frc::VictorSP rightBack{DRIVE_BACK_RIGHT};

  frc::MecanumDrive mecanumDrive{leftFront, leftBack, rightFront, rightBack};
};
