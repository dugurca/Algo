#pragma once
#include "stdafx.h"

class Timer
{
	chrono::time_point<chrono::system_clock> start, end;

public:
	Timer()
	{}

	void startTime()
	{
		start = chrono::system_clock::now();
	}

	void endTime()
	{
		end = chrono::system_clock::now();
	}

	double elapsedSeconds()
	{
		chrono::duration<double> elapsedSecs = end - start;
		return elapsedSecs.count();
	}
};