#include "SDL.h"
#include <stdio.h>
#include "Engine.h"

//TEST CLASS
#include "DummyBox.h"


//START MAIN
int main(int argc, char **argv)
{
	cout << "Hello World!";

	DummyBox dummy;
	dummy.SetObjName("What am I?");

	printf("TYPE: %d FLAG: %d\n", dummy.GetType(), dummy.GetFlag() );
	cout << dummy.GetObjName();
	
	char te;
	cin >> te;

	Engine Game;
	Game.Run();

	//InputManager testInput;

	//bool quit = false;
	////Test not completed wont work
	//while (!quit)
	//{
	//	while (testInput.ProcessEvent() != 0)
	//	{
	//		switch (testInput.getEvent()->type)
	//		{
	//		case SDL_QUIT:
	//			quit = true;
	//			break;
	//		default:;

	//		}

	//		if (testInput.CheckKeyboardEvent())
	//		{

	//			printf("\nPhysical %s key acting as %s key",
	//				SDL_GetScancodeName(testInput.getEvent()->key.keysym.scancode),
	//				SDL_GetKeyName(testInput.getEvent()->key.keysym.sym));

	//		}
	//	}

	//	//printf("No Events On Queue\n");

	//}

	//Game.Quit();


	return 0; //Test main should have ran for 6 seconds total
}

