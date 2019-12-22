/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

// Drivetrain CAN Device IDS
constexpr int DRIVE_FRONT_LEFT = 8;
constexpr int DRIVE_FRONT_RIGHT = 5;
constexpr int DRIVE_BACK_LEFT = 7;
constexpr int DRIVE_BACK_RIGHT = 6;
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

// Sensors CAN Device IDS
constexpr int GYROSCOPE_ID = 10;
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_

// Joystick USB/Driver Station Ports
constexpr int FLIGHTSTICK_PORT = 0;
constexpr int JOYSTICK_PORT = 1;
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

// Joystick axis numbers
constexpr int JOYSTICK_X_AXIS = 4;
constexpr int JOYSTICK_Y_AXIS = 1;
constexpr int JOYSTICK_ROT_AXIS = 0;
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

//Drivetrain adjustable values
constexpr double MAX_SPEED = 0.5;

//PID Values
constexpr double ROT_P = 0.5;
constexpr double ROT_I = 0.5;
constexpr double ROT_D = 0.5;
