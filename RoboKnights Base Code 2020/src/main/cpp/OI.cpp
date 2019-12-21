/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

OI::OI() {}

//For now, if int controller == 0, return the coresponding value on the flightstick,
//else if 1, return the coresponding value on the joystick

//There's probably a better way to do this...

double OI::getAxis(int axis, int controller)
{
  //return whatever axis is passed through the args
  if(controller == 0)
  {
    return flightstick.GetRawAxis(axis);
  }else if(controller == 1)
  {
    return joystick.GetRawAxis(axis);
  }
}

bool OI::getButton(int button, int controller)
{
  if(controller == 0)
  {
    return flightstick.GetRawButton(button);
  }else if(controller == 1)
  {
    return joystick.GetRawButton(button);
  }
}
