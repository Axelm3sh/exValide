#include "TSprite.h"



TSprite::TSprite()
{
}


TSprite::~TSprite()
{
	ObjTexture.free();
	rendererPtr = NULL;
}

void TSprite::InitSprite(SDL_Renderer * targetRenderer, bool isImage, std::string filePathOrText, SDL_Color color, int txtSize)
{
	rendererPtr = targetRenderer;

	if(rendererPtr)
	{
		if (isImage)
		{
			ObjTexture.LoadFromFile(filePathOrText, color);
		}
		else
		{
			ObjTexture.LoadFromText(filePathOrText, color, txtSize);
		}
	}
	
}
