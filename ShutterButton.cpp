/*
  ShutterButton.h - Library for ShutterButton.
  September 15, 2019.
  MIT
*/

#include "ShutterButton.h"
#include "Arduino.h"

ShutterButton::ShutterButton(int channel,bool selfHoldingEnable = true, long millSecHolding = 30000)
{
  _channel = channel;
  _signal = false;
  _signalOld = false;
  _selfHoldingActive = false;
  _millSecFirstHit = 0;
  
  _activateSelfHolding = true;
  
  _millSecLastStamp;
  _millSecFirstHit;
  _millSecHolding;	
}

bool ShutterButton::GetSignal()
{
	_millSecLastStamp = millis();
	
	if(_selfHoldingActive)
	{
		if((_millSecLastStamp - _millSecFirstHit) > _millSecHolding)
		{
			Release();
		}
		else
		{
			return true;
		}
	}
	
	return _signal;
}

bool ShutterButton::GetChannel()
{
	return _channel;
}

void ShutterButton::Release()
{
	_selfHoldingActive = false;
	_signal = false;
}