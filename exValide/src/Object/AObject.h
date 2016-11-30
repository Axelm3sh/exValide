#ifndef AObject_H
#define AObject_H

#include "../GDefinitions.hpp"
#include "../json/json.hpp"
#include <vector>

class AObject
{
public:
	//Constructor
	AObject();
	//Destructor
	virtual ~AObject();

	/*ACCESSORS*/
	// Return this object reference
	AObject* GetObj();

	/*METHODS*/
	void SetObjName(std::string name);
	inline std::string GetObjName() { return objectName; };

	void SetFlag(OBJ_FLAGS flag);
	void SetType(OBJ_TYPE type);

	void addTag(std::string tag);
	bool getTag(std::string tag);

	inline OBJ_FLAGS GetFlag() { return objFlag; };
	inline OBJ_TYPE GetType() { return objType; };

protected:
	std::string objectName;
	std::vector<std::string> objectTags; //Ease of use search indexer, probably useful
	OBJ_FLAGS objFlag;
	OBJ_TYPE objType;
};



#endif /*AObject_H*/