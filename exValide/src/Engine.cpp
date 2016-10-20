#include "Engine.h"



Engine::Engine()
{
	bEngineIsPaused = bEngineIsRunning = false;
}


Engine::~Engine()
{

}

void Engine::Run(int w, int h, bool vsync)
{
	bEngineIsRunning = RenderFramework.Init(w ,h, vsync);
	bEngineIsPaused = false;

	worldTime.Start();

	while (bEngineIsRunning) //While the engine is running
	{
		while (InputHandler.ProcessEvent() != 0) //while we have input events on queue
		{
			/*This section is reserved for the player usually, if we made an input call
			then it should change the player's own data values and then call Step to force update values to the world
			"Time still moves when you don't"
			*/

			switch (InputHandler.getEvent()->type)
			{
			case SDL_QUIT:
				Quit();
				break;
			case SDL_KEYDOWN:
				if (InputHandler.getEvent()->key.keysym.sym == SDLK_ESCAPE)
				{
					Quit();
				}
				break;

			default:;

			}//END SWITCH EVENT TYPE

			Step();
		}

		Step();
		UpdateFrame(); 
	}


}

void Engine::Pause()
{
}

void Engine::Unpause()
{
}

void Engine::Step()
{
	//Every step should go through a list of actors, npcs, and enemies and update their new values by calling their tick function


	//FIXME
	//TEST
	RenderFramework.Clear();

	printf("Time %f, Sinx %f\n", worldTime.GetTime(), (100 + sin(worldTime.GetTime()) * 20) );
	SDL_Rect Rect = { (60 + (int)floor(sin(worldTime.GetTime()) * 60)), 60, (100 + (int) floor( sin(worldTime.GetTime())*30 ) ), 20 };
	SDL_SetRenderDrawColor(RenderFramework.getRenderer(), 0, 255, 25, 150); //Set color for rect, overrides background window color
	SDL_RenderFillRect(RenderFramework.getRenderer(), &Rect); 
	
	//Rerender
	RenderFramework.Refresh();

}

void Engine::UpdateFrame()
{
	//Should step just update the actor's render components as well? this might not be needed...
	/*RenderFramework.Refresh();*/
}

void Engine::Quit()
{
	bEngineIsPaused = false;
	bEngineIsRunning = false;
	RenderFramework.Quit();
}
