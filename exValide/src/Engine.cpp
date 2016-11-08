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
	engineScreenWidth = w; 
	engineScreenHeight = h;

	bEngineIsPaused = false;

	worldTime.Start();

	//Three-step rule for loading sprites, Load image, Initialize anim, SET ANIMATION
	sprite.InitSprite(RenderFramework.getRenderer(), true, fileManager.findFileByNameTag("PlayerSS"), CMagenta);
	sprite.InitSprAnim(0, 0, 36, 36, 11, 30);
	sprite.SetAnimation("Anim_Default", true);

	while (bEngineIsRunning) //While the engine is running
	{
		while (InputHandler.ProcessEvent() != 0) //while we have input events on queue
		{
			/*This section is reserved for the player usually, if we made an input call
			then it should change the player's own data values and then call Step to force update values to the world
			"Time still moves when you don't"
			*/

			if (InputHandler.getEvent()->type == SDL_QUIT || InputHandler.isKeyPressed(SDLK_ESCAPE))
			{
				Quit();
			}

			//Vertical Movement
			if (InputHandler.isKeyPressed(SDLK_UP) && (sprite.GetYPos() > 0) )
			{
				sprite.SetYPos(sprite.GetYPos() - 1);
			}
			else if (InputHandler.isKeyPressed(SDLK_DOWN) && (sprite.GetYPos() < engineScreenHeight))
			{
				sprite.SetYPos(sprite.GetYPos() + 1);
			}
			
			//Horizontalmovement
			if (InputHandler.isKeyPressed(SDLK_RIGHT) && (sprite.GetXPos() < engineScreenWidth) )
			{
				sprite.SetXPos(sprite.GetXPos() + 1);
			}
			else if (InputHandler.isKeyPressed(SDLK_LEFT) && (sprite.GetXPos() > 0) )
			{
				sprite.SetXPos(sprite.GetXPos() - 1);
			}
			

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

	printf("x %d, y %d, w %d, h %d\n", sprite.GetXPos(), sprite.GetYPos(), sprite.GetBoundingBox()->w,  sprite.GetBoundingBox()->h);
	SDL_SetRenderDrawColor(RenderFramework.getRenderer(), 0, 255, 25, 150); //Set color for rect, overrides background window color
	SDL_RenderDrawRect(RenderFramework.getRenderer(), sprite.GetBoundingBox()); 

	SDL_SetRenderDrawColor(RenderFramework.getRenderer(), CCyan.r, CCyan.g, CCyan.b, 255); //Set color for rect, overrides background window color
	SDL_RenderDrawPoint(RenderFramework.getRenderer(), sprite.GetXPos(), sprite.GetYPos());

	sprite.FrameUpdate();
	sprite.RenderSprite();

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
