#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include "Timer.h"
#include "SDL.h"


/*This class should act as a container that holds multiple classes. 
	This really should only hold the window to render things on and/or call Update.
	Holds a timer for the duration of the window.
*/
class CFramework
{
private: 
	Timer gTimer; //intializes when this class is also initialized;

	SDL_Window* gWindow;
	SDL_Surface* gWindowSurface;

	bool bIsRunning;


public:
	CFramework();
	CFramework(int w, int h);
	~CFramework();

	// Initializes the window, should be called in constructor
	bool Init(int screenWidth, int screenHeight);
	// Stops Engine Processes, should be the last function called before exiting out of program
	void Quit();
	// Update function, could call multiple update functions from other classes
	void Update();

	//Run function
	void Run();



	// //returns pointer to the window to draw stuff on
	SDL_Window* getWindow();
};

#endif /*FRAMEWORK_H*/