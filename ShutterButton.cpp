/*
  Multiplexer.h - Library for Jalousie.
  September 15, 2019.
  MIT
*/

#include "Jalousie.h"
#include "Arduino.h"

ShutterButton::ShutterButton(int channel,bool selfHoldingEnable = true, long millSecHolding = 30000);
{
  _channel = channel;
  _signal = false;
  _selfHoldingActive = false;
  _counterFirstHit = 0;
  
  _activateSelfHolding = true;
  
  _millSecLastStamp;
  _millSecFirstHit;
  _millSecHolding;	
}

bool ShutterButton::GetSignal()
{
	_millSecLastStamp = mills();
	
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