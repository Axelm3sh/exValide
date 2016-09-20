#include "GlobalDefinition.h"

#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
	float fElapsedTime;
	float fCurrentTime;
	float fLastTime;
public:
	Timer(); //Construct and initialize
	~Timer(); //Destructor

	// Updates timer from last delta time, should be called every tick cycle if used for world time
	void Update();
	// Get elapsed time from timer initialization
	float GetElapsed();
};


#endif
