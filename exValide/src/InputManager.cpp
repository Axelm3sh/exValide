#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::ProcessEvent()
{
	//If there is an event, dequeue and put into &event
	SDL_PollEvent(&event);
}

SDL_KeyboardEvent* InputManager::CheckKeyboardEvent()
{
	SDL_KeyboardEvent* keyEvent;

	if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
		keyEvent = &event.key;
	}
	else
	{
		keyEvent = NULL;
	}

	return keyEvent;
}

SDL_Event * InputManager::getEvent()
{
	return &event;
}

