#include "Time.h"

void Time::setTime()
{
	_targetFrame = 60;

	QueryPerformanceFrequency(&_frameInfo);
	QueryPerformanceCounter(&_prevFrameCounter);
	_perFrame = _frameInfo.QuadPart / _targetFrame;
}

bool Time::isRenderTiming()
{
	QueryPerformanceCounter(&_nowFrameCounter);
	double time_distance = _nowFrameCounter.QuadPart - _prevFrameCounter.QuadPart;

	if (time_distance > _perFrame)
	{
		_prevFrameCounter = _nowFrameCounter;
		static int count = 0;
		if (count++ > _targetFrame)
		{
			fprintf(stdout, "1 second\n");
			count = 0;

		}
		return true;
	}
	return false;
}
bool Time::isvariableTiming()
{
	return true;
}