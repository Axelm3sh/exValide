#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "GDefinitions.hpp"
#include "../json/json.hpp"

using namespace std;
// for convenience
using json = nlohmann::json;

/*Class File Manager
	@brief: Purpose is to manage files in the resources folder through an external file
	The class loads all resources pointed from a file
	Used for shortcutting later when we load textures from files and all we can do is find a texture
	by an index number or key name.
	Therefore we don't have to store the textures or surfaces in memory which will slow down progress but rather
	stream in as we need it.
*/

class FileManager
{
public:
	FileManager();
	~FileManager();

	void BeginParse();
	void BeginParseResourceFile();


	void DebugParseTypeCheck(json object);

	//DEV dEBUG
	json Resource = 
	{
		{"Alias", 
			//Nickname,		path to file inside res directory
			{"PlayerSS", "Players_SpriteSheet.png"},
			//Nickname,		path in sub res directory
			{"Tiles", "background/BG_Tiles_And_Masks.png"}
		},
		{"Object", 
			//Type,			path to file
			{"Animation", "Player01_Anim_Test.json"}
		}

	};
	

	json Object =
	{ 
		{"Animation", //Object Type, 
			{
				{ //Object inside object which  the internal obj has a list
					{ "file", "Players_SpriteSheet.png" },
					{ "animName", "Anim_Default_Name_Obj" },
					{ "x", 0 },
					{ "y", 0 },
					{ "frameH", 36 },
					{ "frameW", 36 },
					{ "frameNum", 2 },
					{ "cycleDelay", 6 },
					{ "readHorizontally", true }
				}
			}
		}
	};

	void QuickWrite(json obj, string path);
	json QuickRead(string path);

	//Search map for object name, return path to file
	string findFileByNameTag(string tag);

private:
	map<string, string> MapNamePaths;

};


#endif // !FILEMANAGER_H