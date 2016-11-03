#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "GDefinitions.h"
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
	
	//Test Debug Write Json
	void DebugWriteJsonObj();

	//Search map for object name, return path to file
	string findFileByNameTag(string tag);

private:
	map<string, string> MapNamePaths;
};


#endif // !FILEMANAGER_H