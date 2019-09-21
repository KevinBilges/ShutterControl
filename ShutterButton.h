/*
  ShutterButton.h - Library for ShutterButton.
  September 15, 2019.
  MIT
*/

#ifndef ShutterButton_h
#define ShutterButton_h

#include "Arduino.h"

class ShutterButton
{
  public:
    ShutterButton(int channel,bool selfHoldingEnable, long millSecHolding);
	bool GetSignal();
	bool GetChannel();
	void Release();
  private:
  	int _channel;
	bool _signal;
	bool _signalOld;
	
	bool _activateSelfHolding;
	
	long _millSecLastStamp;
	long _millSecFirstHit;
	long _millSecHolding;
	
	bool _selfHoldingActive;
	};

#endif