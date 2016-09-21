#include "FileManager.h"



FileManager::FileManager()
{
	BeginParse();
}


FileManager::~FileManager()
{
}

void FileManager::BeginParse()
{
	fstream parseFile(resFile);
	string readLine;
	string tag;
	string path;
	

	//parseFile.open;

	//Check to see if stream is opened
	if (parseFile.is_open())
	{
		int rangeStart = 0;
		int rangeEnd = 0;
		while (!parseFile.eof())
		{
			//TODO FIXME PsuedoCode
			getline(parseFile, readLine); //Read line?
			
			//Check line for \" or # 
			rangeStart = readLine.find_first_of('\"');
			if (rangeStart != -1)
			{

			}
			//If #
			
				//Ignore The # symbols in text and treat entirety of what follows as comments
				//clear buffer in case?
			//Else if \" char
				//Put all following characters into variable tag until next \" is read, signifies end of tag
				//Continue to read till we hit another character 
				//signifies path name, put following characters into variable path until reach \n char
				//Pair map <tag, name> into resMap
				//clear buffer?			
		}
	}
}

string FileManager::findFileByNameTag(string tag)
{
	return string();
}
