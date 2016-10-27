#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GDefinitions.h"
#include "Timer.h"
#include <map>

//Basically a Queue for different types of events, class is mostly wrapper for ease of use
class InputManager
{
public:
	InputManager();
	~InputManager();
	
	//Single event dequeue, returns non-zero if events are on queue
	int ProcessEvent();

	//Get the event on queue, doesn't check for NULL yet, and I'm not sure what is in the queue when empty
	SDL_Event* getEvent();

	bool isPressed(SDL_Keycode key);
	bool isReleased(SDL_Keycode key);

	//TODO also do something similar to mouse control

private:
	SDL_Event event;
	
	//To handle multi-key input
	std::map<SDL_Keycode, Uint32> keyState;

	//Timer counter; //use for Key Press delays? Restrictions/cooldown? Long-press?
};

#endif /*INPUTMANAGER_H*/