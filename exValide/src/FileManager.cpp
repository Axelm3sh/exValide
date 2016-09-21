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
	string readLine;
	string tag;
	string path;
	

	parseFile.open(resFile);

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
				rangeEnd = readLine.find_last_of('\"') -1;

				tag.append(readLine, rangeStart+1, (rangeEnd - rangeStart));
				cout << tag << "\n"; //Debug
				
			}

			rangeStart = readLine.find_first_of('$');
			if (rangeStart != -1)
			{
				rangeEnd = readLine.size();

				path.append(readLine, rangeStart+1, (rangeEnd - rangeStart));
				cout << path << "\n"; //debug
			}
	
			if (!tag.empty() || !path.empty())
			{
				MapNamePaths[tag] = path; //plzwork
			}

			tag.clear();
			path.clear();
			readLine.clear();
		}
	}

	parseFile.close();
}

string FileManager::findFileByNameTag(string tag)
{
	return string();
}
