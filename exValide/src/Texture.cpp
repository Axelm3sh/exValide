#include "Texture.h"



Texture::Texture()
{
	mHeight = 0;
	mWidth = 0;

	mTexture = NULL;
}


Texture::~Texture()
{
	free();
}

bool Texture::LoadFromFile(std::string path)
{

	return false;
}

bool Texture::LoadFromText(std::string text, SDL_Color textColor)
{
	//Unload exisiting texture
	free();

	//SDL_Surface* textSurface = TTF_RenderText_Solid(); //TODO get font to display



	return false;
}

void Texture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}
