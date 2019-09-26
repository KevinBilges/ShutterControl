/*
  ShutterButton.h - Library for ShutterButton.
  September 15, 2019.
  MIT
*/

#ifndef ShutterButton_h
#define ShutterButton_h

#include "Arduino.h"
#include <CD74HC4067.h>

class ShutterButton
{
  public:
    ShutterButton(int pinIn, CD74HC4067& mux, int channel,bool selfHoldingEnable, long millSecActivateHolding, long millSecHolding);
	bool GetSignal();
	int GetActualSignal();
	bool GetChannel();
	void Release();
  private:
  	int _channel;
	bool _signal;
	bool _signalOld;
		
	bool _activateSelfHolding;
	
	long _millSecLastStamp;
	long _millSecFirstHit;
	long _millSecActivateHolding;
	long _millSecHolding;
	
	bool _selfHoldingActive;
	
	int _pinIn;
	CD74HC4067 _mux;
	};

#endif