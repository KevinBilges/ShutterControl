/*
  Multiplexer.h - Library for Shutter.
  September 15, 2019.
  MIT
*/

#include "Shutter.h"
#include "Arduino.h"

Shutter::Shutter(int channelUp, int channelDown);
{
  _channelUp = channelUp;
  _channelDown = channelDown;
  _signalUp = false;
  _signalDown = false;
}

void Shutter::Idle()
{
  _signalUp = false;
  _signalDown = false;
}

void Shutter::Up()
{
  _signalUp = false;
  _signalDown = false;
}

void Shutter::Down()
{
  _signalUp = false;
  _signalDown = false;
}

ShutterState Shutter::GetState()
{
	if(_signalUp && !_signalDown)
	{
		return ShutterState.Up;
	}
	
	if(!_signalUp && _signalDown)
	{
		return ShutterState.Down;
	}
	
	if(!_signalUp && !_signalDown)
	{
		return ShutterState.Idle;
	}
	
	return ShutterState.Unkown;
}

bool Shutter::GetSignalUp()
{
	return _signalUp;
}

bool Shutter::GetSignalDown()
{
	return _signalDown;
}

bool Shutter::GetChannelUp()
{
	return _channelUp;
}

bool Shutter::GetChannelDown()
{
	return __channelDown;
}