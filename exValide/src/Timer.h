#include "GDefinitions.h"

#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
	float fElapsedTime; //Elapsed time since last update call
	float fCurrentTime; //Current Time
	float fLastTime; //Last time frame since an update was called

	float fPausedTime; //To account Tick time difference since a pause

	float fTimeAccumulator; //Seconds accumulated when timer was unpaused

	bool bIsStarted;
	bool bIsPaused;
public:
	Timer(); //Construct
	Timer(bool); //Construct and Start Timer
	~Timer(); //Destructor

	void Start();
	void Stop();
	void Pause();
	void Unpause();

	// Updates timer from last delta time, should be called every tick cycle if used for world time
	void Update();
	// Get elapsed time from last Time update
	float GetElapsedFromLastUpdate();

	//Return the total time passed unpaused
	float GetTotalTime();
};


#endif
