#include "GDefinitions.h"

#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:

	float fStartTime; //clock time when timer started
	float fPausedTime; //Stored Time at when timer was paused

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

	//Get the current clock time the timer is at
	float GetTime();

	//float GetDelta();

};


#endif
