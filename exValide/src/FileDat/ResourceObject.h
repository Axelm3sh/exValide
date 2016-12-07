#ifndef RESOURCEOBJECT_H
#define RESOURCEOBJECT_H

#include "..\GDefinitions.hpp"
#include "..\json\json.hpp"

using json = nlohmann::json;

enum RESOURCE_TYPE //Can we map strings to enums?
{
	INVALID,
	RESOURCE, //Resource File, <fileName.robj, pathName> 
	OBJECT,	  //Resource File Object, <objectName, easyName>
	ANIMATION //Animation Data File, <see AnimationOject, too many values>
	//Todo, extend for more Resource types
};

struct PathObject
{
	std::string pathToObject; //Relative Path
	std::string easyName; //Nickname of object for reference
};

struct AnimationObject
{
	std::string fileName;
	std::string animationName;
	int xRect;
	int yRect;
	int frameH;
	int frameW;
	int frameNum;
	int cycleDelay;
	bool readHorizontally;
};

class ResourceObject
{
public:
	
	ResourceObject(RESOURCE_TYPE resType);
	~ResourceObject();

	void Serialize(map<string, string> mMap); //to-string json via map
	json Deserialize(); //from-string json
	
private:
	RESOURCE_TYPE resourceType;
	
};

#endif
