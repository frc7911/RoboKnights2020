/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include "Robot.h"

#include <frc/WPILib.h>
#include <frc/buttons/JoystickButton.h>

#include "commands/RotateTo.h"

using namespace frc;

OI::OI() 
{
  joystick = new Joystick(JOYSTICK_PORT);
  flightstick = new Joystick(FLIGHTSTICK_PORT);

	JoystickButton* rotateTo90Button = new JoystickButton(joystick, 1);

  rotateTo90Button->WhenPressed(new RotateTo(90));
}

//For now, if int controller == 0, return the coresponding value on the flightstick,
//else if 1, return the coresponding value on the joystick

//There's probably a better way to do this...

double OI::getAxis(int axis, int controller)
{
  //return whatever axis is passed through the args
  if(controller == 0)
  {
    return flightstick->GetRawAxis(axis);
  }else if(controller == 1)
  {
    return joystick->GetRawAxis(axis);
  }
}

