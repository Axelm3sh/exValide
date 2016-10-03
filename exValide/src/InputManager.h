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
	
	//Single event dequeue
	void ProcessEvent();

	/*Check functions for different types of events, acts as filters after calling Process Event*/

	virtual SDL_KeyboardEvent* CheckKeyboardEvent();//KEYDOWN and KEYUP

	virtual SDL_MouseMotionEvent* CheckMouseMotionEvent(); //MOUSEMOTION

	virtual SDL_MouseButtonEvent* CheckMouseButtonEvent(); //MOUSEBUTTONDOWN and MOUSEBUTTONUP

	virtual SDL_MouseWheelEvent* CheckMouseWheelEvent(); //MOUSEWHEEL

	virtual SDL_QuitEvent* CheckQuitEvent(); //QUIT

	SDL_Event* getEvent();

private:
	SDL_Event event;

	//Timer counter; //use for Key Press delays? Restrictions/cooldown? Long-press?
};

#endif /*INPUTMANAGER_H*/