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

	/*while (bEngineIsRunning)
	{

	}*/


}

void Engine::Pause()
{
}

void Engine::Unpause()
{
}

void Engine::Step()
{
}

void Engine::UpdateFrame()
{
}

void Engine::Quit()
{
	bEngineIsPaused = false;
	bEngineIsRunning = false;
	RenderFramework.Quit();
}
