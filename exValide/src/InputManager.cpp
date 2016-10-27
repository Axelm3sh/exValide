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
	int returnCode = SDL_PollEvent(&event);

	if (returnCode != 0)
	{
		switch (event.type)
		{
			//Case where event type is a Keyboard press or release, set keycode and then the type
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			keyState[event.key.keysym.sym] = event.type;
			break;
		default:
		}

	}
	return returnCode;
}


SDL_Event * InputManager::getEvent()
{
	return &event;
}

bool InputManager::isPressed(SDL_Keycode key)
{
	return (keyState[key] == SDL_KEYDOWN);
}

bool InputManager::isReleased(SDL_Keycode key)
{
	return (keyState[key] == SDL_KEYUP);
}



