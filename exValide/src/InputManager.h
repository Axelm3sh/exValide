#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GDefinitions.h"

//Basically a Queue for different types of events, class is mostly wrapper for ease of use
class InputManager
{
public:
	InputManager();
	~InputManager();
	
	void ProcessEvent();

	/*Check functions for different types of events, acts as filters after calling Process Event*/
	SDL_KeyboardEvent CheckKeyboardEvent(SDL_Event &e);
	SDL_MouseMotionEvent CheckMouseMotionEvent(SDL_Event &e);
	SDL_MouseButtonEvent CheckMouseButtonEvent(SDL_Event &e);
	SDL_MouseWheelEvent CheckMouseWheelEvent(SDL_Event &e);
	SDL_QuitEvent CheckQuitEvent(SDL_Event &e);

private:

	SDL_Event event;
};

#endif /*INPUTMANAGER_H*/