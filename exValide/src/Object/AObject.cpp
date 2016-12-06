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

void AObject::addTag(std::string tag)
{
	//convert lowercase?
	objectTags.push_back(tag);
}

bool AObject::objectHasTag(std::string tag)
{
	bool foundTag = false;
	std::vector<std::string>::iterator it;
	//Todo search through tags, iterate
	for (it = objectTags.begin(); it != objectTags.end(); it++)
	{
		if (*it == tag)
		{
			foundTag = true;
		}
	}

	return foundTag;
}

void AObject::clearTags()
{
	objectTags.clear();
}
