#ifndef APlayer_H
#define APlayer_H

#include "AObject.h"
#include "TSprite.h"
class APlayer :	public AObject
{
public:
	APlayer();
	APlayer(int xPos, int yPos);
	~APlayer();

	APlayer* GetPlayer();
	TSprite* GetPlayerSprite();

private:
	TSprite ActorSprite;

	
	
};

#endif /*APlayer_H*/