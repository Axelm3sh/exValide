#ifndef AObject_H
#define AObject_H

#include "GDefinitions.h"

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

	inline OBJ_FLAGS GetFlag() { return objFlag; };
	inline OBJ_TYPE GetType() { return objType; };
	

private:
	std::string objectName;
	OBJ_FLAGS objFlag;
	OBJ_TYPE objType;
};



#endif /*AObject_H*/