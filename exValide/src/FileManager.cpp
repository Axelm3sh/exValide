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

void FileManager::DebugWriteJsonObj()
{
	string pathToRes = "res/";
	fstream ioStream;

	cout << "creating json Obj\n";
	json jObject = 
	{
		{ "pi", 3.141 },
		{ "happy", true },
		{ "name", "Niels" },
		{ "nothing", nullptr }, //null object by passing nullptr
		{ "answer",
			{
				{ "everything", 42 } //Object inside object
			} 
		},
		{ "list", { 1, 0, 2 } }, //Array stored as vector (using initializer list)
		{ "object",
			{	
				{ "currency", "USD" },	//another object (using initializer list of pairs)
				{ "value", 42.99 }	
			} 
		}
	};

	cout << setw(4) << jObject << endl; //Prettify the output of the entire object

	cout << "Writing to res folder \"myJson.json\"\n\n";

	ioStream.open("res/myJson.json", ios::out | ios::binary);
	if (ioStream.is_open())
	{
		cout << "Successful Write!\n";
		ioStream << jObject;
	}
	else
	{
		cout << "Unsuccessful Write!\n";
	}
	ioStream.close();

	cout << "Creating new json object, j2\n Opening Stream\n\n";
	json j2;

	cout << "Press \'x\' to Jason\n";
	string lol;
	cin >> lol;

	ioStream.open("res/myJson.json", ios::in | ios::binary);
	if (ioStream.is_open())
	{
		cout << "Success!\nNow Attempting to read Json...";
		ioStream >> j2;
	}
	else
	{
		cout << "Failed!";
	}
	ioStream.close();

	cout << j2 << endl;

	cout << "Press \'x\' to Jason\n\n";
	cin >> lol;
	
	// special iterator member functions for objects
	for (json::iterator it = j2.begin(); it != j2.end(); ++it) 
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
			}
		}

		cout << endl;
	}
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
