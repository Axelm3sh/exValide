#include "SDL.h"
#include <stdio.h>
#include "Engine.h"

#include "InputManager.h"


//START MAIN
int main(int argc, char **argv)
{
	cout << "Hello World!";

	Engine Game;

	InputManager testInput;

	bool quit = false;
	//Test not completed wont work
	//while (!quit)
	//{
	//	testInput.ProcessEvent();

	//	if (testInput.CheckKeyboardEvent() != NULL)
	//	{
	//		printf("\nPhysical %s key acting as %s key",
	//			SDL_GetScancodeName(testInput.getEvent()->key.keysym.scancode),
	//			SDL_GetKeyName(testInput.getEvent()->key.keysym.sym));
	//	}
	//	else
	//	{
	//		//printf("\n**No Input Event**\n");
	//	}

	//}




	return 0; //Test main should have ran for 6 seconds total
}

