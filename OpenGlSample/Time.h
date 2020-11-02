#pragma once

#include <Windows.h>
#include "setwindow.h"

class Time
{
private:
	int _targetFrame;
	float _perFrame;
	LARGE_INTEGER _frameInfo;
	LARGE_INTEGER _prevFrameCounter;
	LARGE_INTEGER _nowFrameCounter;

public:

	void setTime();

	//고정 프레임
	bool isRenderTiming();

	//가변 프레임
	bool isvariableTiming();


};