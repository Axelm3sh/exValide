#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GDefinitions.h"
#include "Timer.h"

//Basically a Queue for different types of events, class is mostly wrapper for ease of use
class InputManager
{
public:
	enum E_EVENTCHECKTYPE
	{
		QUIT,
		KEYBOARD,
		MOUSEMOTION,
		MOUSEBUTTON,
		MOUSEWHEEL
	};

	InputManager();
	~InputManager();
	
	//Single event dequeue, returns non-zero if events are on queue
	int ProcessEvent();

	/*Check functions for different types of events, acts as filters after calling Process Event*/

	virtual SDL_KeyboardEvent* CheckKeyboardEvent();//KEYDOWN and KEYUP

	virtual SDL_MouseMotionEvent* CheckMouseMotionEvent(); //MOUSEMOTION

	virtual SDL_MouseButtonEvent* CheckMouseButtonEvent(); //MOUSEBUTTONDOWN and MOUSEBUTTONUP

	virtual SDL_MouseWheelEvent* CheckMouseWheelEvent(); //MOUSEWHEEL

	virtual SDL_QuitEvent* CheckQuitEvent(); //QUIT

	//Get the event on queue, doesn't check for NULL yet, and I'm not sure what is in the queue when empty
	SDL_Event* getEvent();

private:
	SDL_Event event;



	//Timer counter; //use for Key Press delays? Restrictions/cooldown? Long-press?
};

#endif /*INPUTMANAGER_H*/