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

SDL_KeyboardEvent* InputManager::CheckKeyboardEvent()
{
	SDL_KeyboardEvent* keyEvent = NULL;

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

SDL_MouseMotionEvent * InputManager::CheckMouseMotionEvent()
{
	SDL_MouseMotionEvent* mMotionEvent = NULL;

	if (event.type == SDL_MOUSEMOTION)
	{
		mMotionEvent = &event.motion;
	}
	else
	{
		mMotionEvent = NULL;
	}
	return mMotionEvent;
}

SDL_MouseButtonEvent * InputManager::CheckMouseButtonEvent()
{
	SDL_MouseButtonEvent* mButtonEvent = NULL;

	if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
	{
		mButtonEvent = &event.button;
	}
	else
	{
		mButtonEvent = NULL;
	}
	return mButtonEvent;
}

SDL_MouseWheelEvent * InputManager::CheckMouseWheelEvent()
{
	SDL_MouseWheelEvent* mWheelEvent = NULL;

	if (event.type == SDL_MOUSEWHEEL)
	{
		mWheelEvent = &event.wheel;
	}
	else
	{
		mWheelEvent = NULL;
	}
	return mWheelEvent;
}

SDL_QuitEvent * InputManager::CheckQuitEvent()
{
	SDL_QuitEvent* quitEvent = NULL;

	if (event.type == SDL_QUIT)
	{
		quitEvent = &event.quit;
	}
	else
	{
		quitEvent = NULL;
	}
	return quitEvent;
}

SDL_Event * InputManager::getEvent()
{
	return &event;
}

