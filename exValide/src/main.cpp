#include "SDL.h"
#include <stdio.h>
#include "Engine.h"

//START MAIN
int main(int argc, char **argv)
{
	cout << "Hello World!";

	FileManager jsonManage;

	jsonManage.DebugParseTypeCheck(jsonManage.Object);

	jsonManage.QuickWrite(jsonManage.Object, "Player01_Anim_Test.json");
	jsonManage.QuickWrite(jsonManage.Resource, "Test_Resource.json");
	
	char te;
	cin >> te;

	//Engine Game;
	//Game.Run();

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


	return 0; 
}

