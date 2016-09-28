#include "Framework.h"

Framework::Framework()
{
	gWindow = NULL;
	gWindowRenderer = NULL;
}

Framework::Framework(int w, int h)
{
	Init(w, h); //Initialize engine and set loop bool to true if non-default construct
}

Framework::~Framework()
{
	Quit();
}


// Initializes the window, should be called in constructor
bool Framework::Init(int screenWidth, int screenHeight)
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
		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG|IMG_INIT_JPG|IMG_INIT_TIF;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize PNG|JPG|TIF support! SDL_image Error: %s\n", IMG_GetError());
			success = false;
		}

		//Initialize SDL_ttf
		if (TTF_Init() == -1)
		{
			printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
			success = false;
		}

		//Create window with screenWidth and screenHeight
		gWindow = SDL_CreateWindow("exValide Build x.xx", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
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
				SDL_SetRenderDrawColor(gWindowRenderer, 100, 0, 0, 255); //dark red window
				SDL_RenderClear(gWindowRenderer);

				SDL_RenderPresent(gWindowRenderer); //render nothing~!
			}//gWindowRenderer

		}//gWindow

	}//SDL_INIT_EVERYTHING

	bFrameworkIsRunning = success;
	return success;

}

// Stops Engine Processes, should be the last function called before exiting out of program
void Framework::Quit()
{
	//Destroy Renderer
	SDL_DestroyRenderer(gWindowRenderer);
	gWindowRenderer = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


void Framework::Refresh()
{
	SDL_RenderPresent(gWindowRenderer);
}

void Framework::Clear()
{
	SDL_RenderClear(gWindowRenderer);
}


//Return the pointer to the renderer, should point textures and surfaces here
SDL_Renderer* Framework::getRenderer()
{
	return gWindowRenderer;
}

//returns pointer to the window to draw stuff on
SDL_Window* Framework::getWindow()
{
	return gWindow;
}