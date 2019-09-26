/*
  ShutterButtonGroup.h - Library for ShutterButtonGroup.
  September 15, 2019.
  MIT
*/

#include "ShutterButtonGroup.h"
#include "Arduino.h"

ShutterButtonGroup::ShutterButtonGroup(ShutterButton btnUp, ShutterButton btnDown)
{	
	_buttonUp = btnUp;
	_buttonDown = btnDown;	
}

ShutterState ShutterButtonGroup::GetState()   
{ 
	if(_buttonUp.GetSignal() && !_buttonDown.GetSignal())
	{
		
	}
	
	if(!_buttonUp.GetSignal() && _buttonDown.GetSignal())
	{
		
	}		
}