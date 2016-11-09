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

	if (returnCode != 0 && event.key.repeat == 0) //Event in queue and not a repeat keyboard input
	{
		switch (event.type)
		{
			//Case where event type is a Keyboard press or release, set keycode and then the type
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			keyState[event.key.keysym.sym] = event.key.type;
			break;
			//Case where mouse buttons are clicked
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			mouseState[event.button.button] = event.button.type;
			
			//TODO - Implement mouse wheel detection SDL_MouseMotionEvent
			//TODO - Mouse motion detection?
			//TODO - controller support? Touch Support?
		default: ;
		}

	}
	return returnCode;
}


SDL_Event * InputManager::getEvent()
{
	return &event;
}

bool InputManager::isKeyPressed(SDL_Keycode key)
{
	return (keyState[key] == SDL_KEYDOWN);
}

bool InputManager::isKeyReleased(SDL_Keycode key)
{
	return (keyState[key] == SDL_KEYUP);
}

bool InputManager::isLeftClickPressed()
{
	return (mouseState[SDL_BUTTON_LEFT] == SDL_MOUSEBUTTONDOWN);
}

bool InputManager::isRightClickedPressed()
{
	return (mouseState[SDL_BUTTON_RIGHT] == SDL_MOUSEBUTTONDOWN);
}

bool InputManager::isMiddleClickedPressed()
{
	return (mouseState[SDL_BUTTON_MIDDLE] == SDL_MOUSEBUTTONDOWN);
}



