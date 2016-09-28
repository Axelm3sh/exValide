#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::ProcessEvent()
{
	SDL_EventType returnType;

	if (SDL_PollEvent(&event)) //Check if input queue is empty or not, pop and save to &event if we have something in queue.
	{
		switch (event.type) //Check type of input
		{
		case SDL_KEYDOWN: //Keyboard Key Press
			CheckKeyboardEvent(event);
			break;
		case SDL_KEYUP: //Keyboard Key Release

			//...

			break;
		default: 
		}
	}
	

}
