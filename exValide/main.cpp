#include "SDL.h"
#include <stdio.h>
#include "Timer.h"
#include "Framework.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//FUNCTIONS
//start SDL and create window
bool init();

//load media
bool loadMedia();

//frees media and shut down SDL
void close();

//Test function that runs timer class
void DEBUG_TIMER();

//GLOBAL VAR
/**FIXME testing purpose, remove global vars and move into class**/
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

/**FIXME testing purpose, remove global vars and move into class**/
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

/**FIXME testing purpose, remove global vars and move into class**/
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


//START MAIN
int main(int argc, char **argv)
{
	
	//Initialize main test and timer test
	DEBUG_TIMER();


	//CFramework Test_Framework(SCREEN_WIDTH, SCREEN_HEIGHT);


	return 0; //Test main should have ran for 6 seconds total
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


void DEBUG_TIMER()
{
	Timer gTime;
	printf("initial Time %f\n", gTime.GetElapsed());

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
			//Wait two seconds
			SDL_Delay(2000);
		}
	}


	gTime.Update();
	printf("Seconds Passed: %f\n", gTime.GetElapsed());
	SDL_Delay(1000);

	gTime.Update(); //clear last delay
	float totalTimeAccum = 0.0f;
	float totalFrames = 0;
	while (totalTimeAccum < 1.00f) //over 1 second
	{

		gTime.Update();
		totalFrames++; //Add frame
		totalTimeAccum += gTime.GetElapsed();
		printf("Tick(ms): %f\n", gTime.GetElapsed());

	}
	printf("FPS: %f\n", totalFrames);

	SDL_Delay(2000);

	//Free resources and close SDL
	close();
}