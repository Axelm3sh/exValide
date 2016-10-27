#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

int InputManager::ProcessEvent()
{
	//If there is an event, dequeue and put into &event
	return SDL_PollEvent(&event);
}


SDL_Event * InputManager::getEvent()
{
	return &event;
}



