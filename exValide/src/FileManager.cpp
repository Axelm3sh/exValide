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
	

	parseFile.open(RESOURCE_FILE_PATH);

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
				cout << tag << "\n"; //FIXME - Debug
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

void FileManager::MapDefaultResources()
{
	fstream parseFile;
	string tag = "";
	string path = "";
	json defaultResourceJson;

	parseFile.open(RESOURCE_FILE_PATH);



}

void FileManager::DebugParseTypeCheck(json object)
{
	// special iterator member functions for objects
	for (json::iterator it = object.begin(); it != object.end(); ++it)
	{
		std::cout << it.key() << " : " << it.value();
		if (it.value().is_primitive())
		{
			cout << " is a primative and";
			if (it.value().is_null())
			{
				cout << " is a NULL POINTER!";
			}
			else if (it.value().is_number())
			{
				cout << " is a NUMBER!";
			}
			else if (it.value().is_boolean())
			{
				cout << " is a BOOLEAN!";
			}
			else if (it.value().is_string())
			{
				cout << " is a STRING!";
			}
		}
		else if (it.value().is_structured())
		{
			cout << " is structured and";
			if (it.value().is_object())
			{
				cout << " is a another JSON OBJECT!";
			}
			else if (it.value().is_array())
			{
				cout << " is an ARRAY!";
				for (json::iterator it2 = it.value().begin(); it2 != it.value().end(); it2++)
				{
					DebugParseTypeCheck(it2.value());
				}
			}
		}
		
		cout << endl;
	}
}


void FileManager::QuickWrite(json obj, string path)
{
	fstream iostream;
	
	path.insert(0, "res/");

	iostream.open(path, ios::out | ios::binary);
	if (iostream.is_open())
	{
		cout << "Success!\nNow Attempting to write Json...";
		iostream << obj;
	}
	else
	{
		cout << "Unsuccessful QuickWrite\n";
	}
	iostream.close();

}

json FileManager::QuickRead(string path)
{
	json j2;
	fstream ioStream;

	path.insert(0, "res/");

	ioStream.open(path, ios::in | ios::binary);
	if (ioStream.is_open())
	{
		cout << "Success!\nNow Attempting to read Json...";
		ioStream >> j2;
	}
	else
	{
		cout << "Failed QuickRead! ";
		cout << path << endl;
	}
	ioStream.close();

	return j2;
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
		printf("Resource tag %s not found", tag.c_str());
		foundString = "";
	}
	return foundString;
}
