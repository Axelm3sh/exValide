#ifndef TSPRITE_H
#define TSPRITE_H

#include "../Texture.h"
#include "AObject.h"


class TSprite :	public AObject
{
public:
	TSprite();
	~TSprite();

	void InitSprite(SDL_Renderer* targetRenderer, bool isImage, );

protected:
	Texture ObjTexture;
	bool bIsAnimated; //True if sprite is animated, false if it sprite is not
	int numSkins; //Number of alternate skins a sprite has

	//Sprite Bounding Box, reflects Maximum edge of the sprite. Used for simple Collision Checks
	SDL_Rect SBBox;

	SDL_Renderer* rendererPtr;
};

#endif