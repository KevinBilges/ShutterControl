/*
  ShutterButton.h - Library for ShutterButton.
  September 15, 2019.
  MIT
*/

#include "ShutterButton.h"
#include "Arduino.h"
#include <CD74HC4067.h>

ShutterButton::ShutterButton(int pinIn, CD74HC4067& mux,int channel,bool selfHoldingEnable, long millSecActivateHolding, long millSecHolding)
{
	_pinIn = pinIn;
	_mux = mux;
  _channel = channel;
  _signal = false;
  _signalOld = false;
  _selfHoldingActive = false;
  _millSecFirstHit = 0;
  
  _activateSelfHolding = true;
  
  _millSecLastStamp;
  _millSecHolding = millSecHolding;	
  _millSecActivateHolding = millSecActivateHolding;
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
	
	int val = GetActualSignal();
		
	if(val > 0)
	{
		if(!_signalOld)
		{
			_millSecFirstHit = millis();
		}
		
	    if((_millSecLastStamp - _millSecFirstHit) > _millSecActivateHolding)
		{
			_selfHoldingActive = true;
			_signal = true;
		}
		
		_signalOld = true;			
	    return true;
	}
	else
	{
		_signalOld = false;
	}
	
	return _signal;
}

int ShutterButton::GetActualSignal()
{
	_mux.channel(GetChannel());
	int tmp = analogRead(_pinIn);	
	return tmp;
}

bool ShutterButton::GetChannel()
{
	return _channel;
}

void ShutterButton::Release()
{
	_selfHoldingActive = false;
	_signal = false;
		_signalOld = false;
}