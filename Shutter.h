/*
  Shutter.h - Library for Shutter.
  September 15, 2019.
  MIT
*/

#ifndef Shutter_h
#define Shutter_h

#include "Arduino.h"

enum ShutterState
{
	Unkown,
	Idle,
	Up,
	Down
};

class Shutter
{
  public:
    Shutter(int channelUp, int channelDown);
	void Idle();
	void Up();
	void Down();
	ShutterState GetState();
	bool GetSignalUp();
	bool GetSignalDown();	
	bool GetChannelUp();
	bool GetChannelDown();
  private:
  	int _channelUp;
  	int _channelDown;
	bool _signalUp;
	bool _signalDown;
};

#endif
