#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GDefinitions.h"
#include "Timer.h"
#include "InputComponent.h"

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

	//Get the event on queue, doesn't check for NULL yet, and I'm not sure what is in the queue when empty
	SDL_Event* getEvent();

private:
	SDL_Event event;

	//Timer counter; //use for Key Press delays? Restrictions/cooldown? Long-press?
};

#endif /*INPUTMANAGER_H*/