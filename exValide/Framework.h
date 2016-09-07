#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_


#include <iostream>
#include "SingletonInstance.h"


class CFramework: public TInstance<CFramework>
{
public:
	CFramework();
	~CFramework();
};

#endif /*FRAMEWORK_H_*/