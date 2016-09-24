#include "SDL.h"
#include <stdio.h>
#include "Timer.h"
#include "Framework.h"
#include "FileManager.h"
#include "Texture.h"

//Screen dimension constants, can be changed down line
const int SCREEN_WIDTH_SD = 640;
const int SCREEN_HEIGHT_SD = 480;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//START MAIN
int main(int argc, char **argv)
{
	
	//Initialize main test and timer test
	//DEBUG_TIMER(); //In Test01_loadTimer.cpp Todo: Delete me


	CFramework Test_Framework(SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Window* ptrWin;
	ptrWin = Test_Framework.getWindow();

	if (ptrWin)
	{
		std::cout << SDL_GetWindowTitle(ptrWin) << "\n";

		SDL_Delay(1000);
		SDL_SetRenderDrawColor(Test_Framework.getRenderer(), 0, 100, 100, 255); //External color call
		SDL_RenderClear(Test_Framework.getRenderer());
		SDL_RenderPresent(Test_Framework.getRenderer());
	}

	SDL_Delay(4000);

	//*****************FileManager*******************
	FileManager FM;

	Texture texture;

	//*****IMPORTANT THAT TEXTURE NEEDS A SET RENDERER****
	texture.setRenderTo(Test_Framework.getRenderer()); //Set up our target to render to
	texture.LoadFromFile(FM.findFileByNameTag("spinlol"));//Loaded up texture, now stored in this class
	
	

	std::cout << "Post-Init File Manager\n";

	SDL_Delay(4000);

	std::cout << "\nInitialze Protocall success, moving to Event Drive\n";

	/*************Should move below code to a class?********************/
	//Event handler
	SDL_Event e;
	Timer delta;
	float accumulator = 0.0;
	bool quit = false;

	

	while (!quit) //while application is running
	{
		delta.Update(); //Update timer

		accumulator += delta.GetElapsed(); //Accumulate time

		//Handle Events on queue, update colors if user does anything input wise(mouse movement included)
		while (SDL_PollEvent(&e) != 0)
		{
			delta.Update();
			accumulator += delta.GetElapsed(); //Accumulate time

			//User request quit by escape key or by exiting window
			if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYDOWN)) 
			{
				quit = true;
			}

			SDL_RenderClear(Test_Framework.getRenderer()); //Clear 
			//Check acc status
			if (accumulator < 1.f)
			{
				SDL_SetRenderDrawColor(Test_Framework.getRenderer(), 0, 100, 100, 255); //External color call
				printf("R0 G100 B100 A255\n");
				
			}
			else if (accumulator < 2.f)
			{
				SDL_SetRenderDrawColor(Test_Framework.getRenderer(), 155, 0, 50, 255); //External color call
				printf("R155 G0 B50 A255\n");

			}
			else if (accumulator < 3.f)
			{
				SDL_SetRenderDrawColor(Test_Framework.getRenderer(), 50, 255, 100, 255); //External color call
				printf("R50 G255 B100 A255\n");

			}
			else if (accumulator < 4.f)
			{
				SDL_SetRenderDrawColor(Test_Framework.getRenderer(), 255, 100, 25, 255); //External color call
				printf("R255 G100 B25 A255\n");

			}
			else
			{
				SDL_SetRenderDrawColor(Test_Framework.getRenderer(), 255, 255, 255, 255); //External color call
				printf("WHITE\n");
				
			}

			//Call AFTER RenderClear or else you'll lose this texture
			//50 units right, 50 units down, No Clipping, +45 degree rotation, No center offset?, No Flip
			//texture.render(50, 50, NULL, 45.0, NULL); //FIXME test debug 
			//SDL_RenderPresent(Test_Framework.getRenderer()); //Push to renderer
		}

		//Outerloop test
		SDL_RenderClear(Test_Framework.getRenderer());
		texture.render(20, 20, NULL, (accumulator*60.0), NULL); //FIXME test debug 
		SDL_RenderPresent(Test_Framework.getRenderer()); //Push to renderer


		if (accumulator > 6)
		{
			accumulator = 0.0f;
		}
	}


	return 0; //Test main should have ran for 6 seconds total
}

