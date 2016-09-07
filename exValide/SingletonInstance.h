#ifndef SINGLETONINSTANCE_H_
#define SINGLETONINSTANCE_H_

/**
TInstance<T> Class
Based on Singleton design where there should be one object
and only one object that would act as a "control hub" for objects within it.

Template class allows for universal class instances but should really be used
in conjunction with game framework. This just provides a skeleton to build the
flesh around it.

Prefix Key
===========
T-prefix Template
C-prefix Class
p-prefix Pointer
work-in-progress

*/
template <class T>
class TInstance
{
protected:
	
	static T* pInstance; //Pointer to instance of type, should be assigned to self?

public:
	TInstance(); //No need to make more than one instance of this, not really called by client

	//Returns pointer to myself or if I don't exist make new instance
	static T* GetInstance();

	//Should call this if you wanna fully get rid of instance. 
	//Should be used with virtual destructor?
	bool Destroy(); 

	virtual ~TInstance(); //Templated class should implement a cleanup method

};

template<class T>
inline TInstance<T>::TInstance()
{
}

template<class T>
static T* TInstance<T>::GetInstance()
{
	if (!pInstance) //check nullptr
	{
		pInstance = new T; //Make new thing of us if we are not here
	}

	return pInstance;
}

template<class T>
bool TInstance<T>::Destroy()
{
	bool ok = true; //fixme
	if (pInstance)
	{
		delete pInstance; //I should reaaaaaaally do a check...
	}

	pInstance = nullptr;

	return ok;

}

#endif // !SINGLETONINSTANCE_H_