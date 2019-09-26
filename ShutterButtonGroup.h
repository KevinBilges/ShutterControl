/*
  ShutterButtonGroup.h - Library for ShutterButtonGroup.
  September 15, 2019.
  MIT
*/

#ifndef ShutterButtonGroup_h
#define ShutterButtonGroup_h

#include "Arduino.h"

class ShutterButtonGroup
{
  public:
    ShutterButtonGroup(ShutterButton btnUp, ShutterButton btnDown);
	ShutterState GetState();
  private:
	ShutterButton _buttonUp;
	ShutterButton _buttonDown;
	};
	
#endif