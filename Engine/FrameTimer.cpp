#include "FrameTimer.h"

using namespace std::chrono;

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

float FrameTimer::Mark()
{
	old = last;
	last = steady_clock::now();
	duration<float> frameTime = last - old;
	return frameTime.count() * frameDelayFactor;
}
