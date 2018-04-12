#pragma once

#include <chrono>

class FrameTimer
{
public:
	FrameTimer();
	float Mark();
private :
	std::chrono::steady_clock::time_point last;
	std::chrono::steady_clock::time_point old;
	float frameDelayFactor = 10.0f;
};

 