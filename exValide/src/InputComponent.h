#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "GDefinitions.h"
#include <list>
#include <map>


//This class should never be added in a 
class InputComponent
{
public:

	//Constructor must have the event queue passed in
	InputComponent(SDL_Event &e);

	~InputComponent();

	/*Check functions for different types of events, acts as filters after calling Process Event*/

	virtual SDL_KeyboardEvent* CheckKeyboardEvent();//KEYDOWN and KEYUP

	virtual SDL_MouseMotionEvent* CheckMouseMotionEvent(); //MOUSEMOTION

	virtual SDL_MouseButtonEvent* CheckMouseButtonEvent(); //MOUSEBUTTONDOWN and MOUSEBUTTONUP

	virtual SDL_MouseWheelEvent* CheckMouseWheelEvent(); //MOUSEWHEEL

	virtual SDL_QuitEvent* CheckQuitEvent(); //QUIT

private:

	typedef void(*funcParam)();//Func pointer type def

	std::map<SDL_Keycode, std::list<funcParam> > BindsMapping; //Map of keyboard keys to a list of function parameters

	SDL_Event event;

};

#endif INPUTCOMPONENT_H /*INPUTCOMPONENT_H*/