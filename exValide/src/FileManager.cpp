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
	fstream parseFile;
	string readLine = "";
	string tag = "";
	string path = "";
	

	parseFile.open(resFile);

	//Check to see if stream is opened
	if (parseFile.is_open())
	{
		//Initialize the ranges for string search
		int rangeStart = 0;
		int rangeEnd = 0;

		//Keep going till end of file
		while (!parseFile.eof())
		{
			//TODO FIXME PsuedoCode, Can be optimized and NEED A BUNCH OF ERROR CHECKS
			getline(parseFile, readLine); //Read line?
			
			//Check line for first set of Quotes
			rangeStart = readLine.find_first_of('\"');
			if (rangeStart != -1)
			{
				//Last set of quotes, should error check file format
				rangeEnd = readLine.find_last_of('\"') -1;

				tag.append(readLine, rangeStart+1, (rangeEnd - rangeStart));
				cout << tag << "\n"; //Debug
			}

			//Check for second value which is the local path
			rangeStart = readLine.find_first_of('$');
			if (rangeStart != -1)
			{
				rangeEnd = readLine.size();

				path.append(readLine, rangeStart+1, (rangeEnd - rangeStart));
				//Fixme: someone add a check for string whitespace (ie: trailing whitespace)

				path.insert(0, "res/");

				cout << path << "\n"; //debug
			}
	
			if (!tag.empty() || !path.empty())
			{
				MapNamePaths[tag] = path; //plzwork
			}

			//Clear stuff just in case
			tag.clear();
			path.clear();
			readLine.clear();
		}
	}

	//Close da file since we finished loading up stuff
	parseFile.close();
}

string FileManager::findFileByNameTag(string tag)
{
	string foundString;

	//If we dont find stuff we're looking for
	if (MapNamePaths.find(tag) != MapNamePaths.end()) 
	{
		//give pack local path name
		foundString = MapNamePaths.find(tag)->second;
	}
	else
	{
		//Not found :<
		foundString = "";
	}
	return foundString;
}
