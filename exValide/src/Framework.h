#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include "GDefinitions.h"

/*This class should act as a container that holds multiple classes. 
	This really should only hold the window to render things on and/or call Update.
	Holds a timer for the duration of the window.
*/
class Framework
{
private: 
	SDL_Window* gWindow; //This is the main window that displays surfaces/textures/etc..
	SDL_Renderer* gWindowRenderer; //This is the renderer for the window

	bool bFrameworkIsRunning;

public:
	Framework();
	Framework(int w, int h);
	~Framework();

	// Initializes the window, should be called in constructor
	bool Init(int screenWidth, int screenHeight);
	// Stops Engine Processes, should be the last function called before exiting out of program
	void Quit();

	//Render textures
	void Refresh(); //Wrapper SDL_RenderPresent(gWindowRenderer);
	//Clear screen
	void Clear();	//Wrapper SDL_RenderClear(gWindowRenderer);
	//void QueueTexture(); //Pushes texture to renderer, when refresh is called update all at once?


	//returns the renderer
	SDL_Renderer* getRenderer();
	//returns pointer to the window to draw stuff on
	SDL_Window* getWindow();
};

#endif /*FRAMEWORK_H*/