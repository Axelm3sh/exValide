#ifndef RESOURCEOBJECT_H
#define RESOURCEOBJECT_H

#include "..\GDefinitions.hpp"
#include "..\json\json.hpp"

using json = nlohmann::json;

enum RESOURCE_TYPE //Can we map strings to enums?
{
	INVALID,
	ALIAS,
	OBJECT,
	ANIMATION
	//Todo, extend for more Resource types
};

struct PathObject
{
	std::string pathToObject; //Relative Path
	std::string easyName;
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

	void Serialize();
	json Deserialize();
	
private:
	RESOURCE_TYPE resourceType;

	
};

#endif
