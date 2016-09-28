#ifndef ENGINE_H
#define ENGINE_H

#include "GDefinitions.h"
#include "Timer.h"
#include "Framework.h"
#include "FileManager.h"
#include "Texture.h"

class Engine
{
public:
	Engine();
	~Engine();

	//Starts the engine initializing everything to defaults, if already running don't do anything (shouldn't call more than once??)
	void Run();

	//Pauses the game, pauses timer, brings up pause menu (TODO)
	void Pause();

	//Unpauses the game, timer, hides menu
	void Unpause();

	//Step into the next logic frame, all image calculations should be done here, think of it as a pre-render stage
	void Step();

	//Update the current Frame to reflect the logic decision made in the Step Function
	void UpdateFrame();

	//FIXME - May or may not need this, calculations done after the frame has been already rendered
	void PostStep();

	//Stops the engine if it's running and closes window
	void Quit();

private:
	bool bEngineIsRunning;
	bool bEngineIsPaused;

	Timer worldTime; //Timer that runs for the duration of the engine lifetime, does not tick over pause
	SDL_Event InputHandler; //SDL_Event handles all input user has made

	Framework RenderFramework;

};

#endif  /*ENGINE_H*/