#include "SDL.h"
#include <stdio.h>
#include "Engine.h"

#include "InputManager.h"


//START MAIN
int main(int argc, char **argv)
{
	cout << "Hello World!";

	Engine Game;
	Game.Run();

	InputManager testInput;

	bool quit = false;
	//Test not completed wont work
	while (!quit)
	{
		testInput.ProcessEvent();

		switch (testInput.getEvent()->type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		default:;

		}

		if (testInput.CheckKeyboardEvent())
		{
			
			printf("\nPhysical %s key acting as %s key",
				SDL_GetScancodeName(testInput.getEvent()->key.keysym.scancode),
				SDL_GetKeyName(testInput.getEvent()->key.keysym.sym));

		}

	}

	Game.Quit();


	return 0; //Test main should have ran for 6 seconds total
}

