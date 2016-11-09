#include "Timer.h"

Timer::Timer()
{
	fStartTime = 0.0f;
	fPausedTime = 0.0f;
	
	currTickTime = 0.0f;
	lastTickTime = 0.0f;

	bIsPaused = false;
	bIsStarted = false;

}

Timer::Timer(bool init)
{
	if (init)
	{
		Start();
	}
	else
	{
		fStartTime = 0.0f;
		fPausedTime = 0.0f;

		bIsPaused = false;
		bIsStarted = false;
	}
}


Timer::~Timer()
{
	//Does this need anything?
	Stop();
}

void Timer::Start()
{
	//Start Timer
	bIsStarted = true;

	//Unpause Timer
	bIsPaused = false;

	//Clock current time
	fStartTime = (SDL_GetTicks() / 1000.0f);
	fPausedTime = 0;
}

void Timer::Stop()
{
	bIsStarted = false;
	bIsPaused = false;

	fStartTime = 0.0f;
	fPausedTime = 0.0f;
}

void Timer::Pause()
{
	//If the timer is running and isn't paused
	if (bIsStarted && !bIsPaused)
	{
		//Pause the timer
		bIsPaused = true;

		//Set the time mark for when we paused
		fPausedTime = (SDL_GetTicks() / 1000.0f) - fStartTime;
		fStartTime = 0;
	}
}

void Timer::Unpause()
{
	//If timer is running and paused
	if(bIsStarted && bIsPaused)
	{
		//Resume timer
		bIsPaused = false;

		//Reset Start Time
		fStartTime = (SDL_GetTicks() / 1000.f) - fPausedTime;

		//Reset Paused Time
		fPausedTime = 0;
	}
}


// Get elapsed time from last timer update call
float Timer::GetTime()
{
	float time = 0;

	if (bIsStarted)
	{
		if (bIsPaused)
		{
			time = fPausedTime; //Time marked at pause call
		}
		else
		{
			time = (SDL_GetTicks() / 1000.f) - fStartTime;
		}
	}

	return time;
}

void Timer::Tick()
{
	currTickTime = SDL_GetTicks() / 1000.0f;

	elapsedTickTime = currTickTime - lastTickTime;
	lastTickTime = currTickTime;
}

float Timer::GetDelta()
{
	return elapsedTickTime;
}
