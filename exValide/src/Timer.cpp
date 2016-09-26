#include "Timer.h"

Timer::Timer()
{
	//Initialize variables
	fElapsedTime = 0.0f;
	fCurrentTime = 0.0f;

	//fLastTime = SDL_GetTicks() / 1000.0f ;

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

	}
}


Timer::~Timer()
{
	//Does this need anything?
}

void Timer::Start()
{
	//Start Timer
	bIsStarted = true;

	//Unpause Timer
	bIsPaused = false;

	//Clock current time
	fElapsedTime = 0.0f;
	fCurrentTime = 0.0f;
	fLastTime = SDL_GetTicks() / 1000.0f ;
}

void Timer::Stop()
{
	bIsStarted = false;
	bIsPaused = false;

	fElapsedTime = 0.0f;
	fCurrentTime = 0.0f;
	fLastTime = 0.0f;

	fPausedTime = 0.0f;
}

void Timer::Pause()
{
	//If the timer is running and isn't paused
	if (bIsStarted && !bIsPaused)
	{
		//Pause the timer
		bIsPaused = true;

		//Calculate the paused ticks, pTime = "currentTime" - lastTime???
		//TODO CODE HERE
	}
}

void Timer::Unpause()
{
}


// Updates timer from last delta time
void Timer::Update()
{
	fCurrentTime = SDL_GetTicks() / 1000.0f; //Calculate current time frame
	fElapsedTime = fCurrentTime - fLastTime; //Time since last update call
	fLastTime = fCurrentTime;  //Current time is now the most recent time stamp for update call

	//Accumulate time for local timer
	fTimeAccumulator += fCurrentTime - fLastTime;
}


// Get elapsed time from last timer update call
float Timer::GetElapsedFromLastUpdate()
{
	return fElapsedTime;
}
