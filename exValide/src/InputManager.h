#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GDefinitions.h"
#include "Timer.h"

//Basically a Queue for different types of events, class is mostly wrapper for ease of use
class InputManager
{
public:
	InputManager();
	~InputManager();
	
	//Single dequeue
	void ProcessEvent();

	/*Check functions for different types of events, acts as filters after calling Process Event*/

	SDL_KeyboardEvent* CheckKeyboardEvent();//KEYDOWN and KEYUP

	SDL_MouseMotionEvent* CheckMouseMotionEvent(); //MOUSEMOTION

	SDL_MouseButtonEvent* CheckMouseButtonEvent(); //MOUSEBUTTONDOWN and MOUSEBUTTONUP

	SDL_MouseWheelEvent* CheckMouseWheelEvent(); //MOUSEWHEEL

	SDL_QuitEvent* CheckQuitEvent(SDL_Event &e); //QUIT

	SDL_Event* getEvent();

private:
	SDL_Event event;

	//Timer counter; //use for Key Press delays? Restrictions/cooldown? Long-press?
};

#endif /*INPUTMANAGER_H*/