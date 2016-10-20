#include "InputComponent.h"



InputComponent::InputComponent(SDL_Event &e)
{
	event = e;
}


InputComponent::~InputComponent()
{
}

SDL_KeyboardEvent* InputComponent::CheckKeyboardEvent()
{
	SDL_KeyboardEvent* keyEvent = NULL;

	if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
		keyEvent = &event.key;
	}

	return keyEvent;
}

SDL_MouseMotionEvent * InputComponent::CheckMouseMotionEvent()
{
	SDL_MouseMotionEvent* mMotionEvent = NULL;

	if (event.type == SDL_MOUSEMOTION)
	{
		mMotionEvent = &event.motion;
	}

	return mMotionEvent;
}

SDL_MouseButtonEvent * InputComponent::CheckMouseButtonEvent()
{
	SDL_MouseButtonEvent* mButtonEvent = NULL;

	if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
	{
		mButtonEvent = &event.button;
	}

	return mButtonEvent;
}

SDL_MouseWheelEvent * InputComponent::CheckMouseWheelEvent()
{
	SDL_MouseWheelEvent* mWheelEvent = NULL;

	if (event.type == SDL_MOUSEWHEEL)
	{
		mWheelEvent = &event.wheel;
	}

	return mWheelEvent;
}

SDL_QuitEvent * InputComponent::CheckQuitEvent()
{
	SDL_QuitEvent* quitEvent = NULL;

	if (event.type == SDL_QUIT)
	{
		quitEvent = &event.quit;
	}

	return quitEvent;
}
