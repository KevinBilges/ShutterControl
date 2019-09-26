/*
  ShutterControl.h - Library for ShutterControl.
  September 15, 2019.
  MIT
*/

#ifndef ShutterControl_h
#define ShutterControl_h

#include "Arduino.h"

class ShutterControl
{
  public:
    ShutterControl();
	void Add(Shutter shutter);
	void Add(ShutterButtonGroup shutterBtnGrp);
  private:
	Shutter* _shutterList;
	ShutterButtonGroup* _shutterButtonGroup;
	int _numShutters;
	int _numButtonGroups;
};

#endif
