#include "Framework.h"

CFramework::CFramework()
{
	gWindow = NULL;
	gWindowSurface = NULL;
}

CFramework::CFramework(int w, int h)
{
	Init(w, h);
}

CFramework::~CFramework()
{
	Quit();
}


// Initializes the window, should be called in constructor
bool CFramework::Init(int screenWidth, int screenHeight)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window with screenWidth and screenHeight
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gWindowSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	//Should probably load world background here

	//Should probably initialize player here

	return success;

}

// Stops Engine Processes, should be the last function called before exiting out of program
void CFramework::Quit()
{
	//Deallocate surface
	SDL_FreeSurface(gWindowSurface);
	gWindowSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


// This function will update/refresh the window
void CFramework::Update()
{
	//Do stuff per update Call
	gTimer.Update(); //Update Framework Timer

	/*If we split calls into several steps we can divide it up as
		World->Update
		Player->Update
		Enemy->Update
		UI->Update
	*/
}



// //returns pointer to the window to draw stuff on
SDL_Window* CFramework::getWindow()
{
	return gWindow;
}
