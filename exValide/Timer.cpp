#include "Timer.h"

Timer::Timer()
{
	fElapsedTime = 0.0f;
	fCurrentTime = 0.0f;
	fLastTime = SDL_GetTicks() / 1000.0f ;
}


Timer::~Timer()
{
	//Does this need anything?
}


// Updates timer from last delta time
void Timer::Update()
{
	fCurrentTime = SDL_GetTicks() / 1000.0f;
	fElapsedTime = fCurrentTime - fLastTime;
	fLastTime = fCurrentTime;
}


// Get elapsed time from timer initialization
float Timer::GetElapsed()
{
	return fElapsedTime;
}
