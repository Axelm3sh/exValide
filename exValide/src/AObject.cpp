#include "AObject.h"


AObject::AObject()
{
	objectName = "NULL";
	objFlag = OBJ_FLAGS::ASSET_DATA;
	objType = OBJ_TYPE::NONE;
}


AObject::~AObject()
{
	objectName.clear();
}


// Return this object
AObject* AObject::GetObj()
{
	return this;
}

void AObject::SetObjName(std::string name)
{
	objectName = name;
}

void AObject::SetFlag(OBJ_FLAGS flag)
{
	objFlag = flag;
}

void AObject::SetType(OBJ_TYPE type)
{
	objType = type;
}
