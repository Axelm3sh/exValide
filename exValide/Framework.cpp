#include "Framework.h"

CFramework::CFramework()
{
	gWindow = NULL;
	gWindowRenderer = NULL;
}

CFramework::CFramework(int w, int h)
{
	Init(w, h); //Initialize engine and set loop bool to true if non-default construct
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
			//Create renderer for window
			gWindowRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gWindowRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{

				//Get clear screen and update window with renderer
				SDL_SetRenderDrawColor(gWindowRenderer, 100, 0, 0, 255);
				SDL_RenderClear(gWindowRenderer);

				SDL_RenderPresent(gWindowRenderer);
			}
		}
	}

	return success;

}

// Stops Engine Processes, should be the last function called before exiting out of program
void CFramework::Quit()
{
	//Destroy Renderer
	SDL_DestroyRenderer(gWindowRenderer);
	gWindowRenderer = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


SDL_Renderer* CFramework::getRenderer()
{
	return gWindowRenderer;
}

//returns pointer to the window to draw stuff on
SDL_Window* CFramework::getWindow()
{
	return gWindow;
}
