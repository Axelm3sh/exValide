#include "Texture.h"



Texture::Texture()
{
	mHeight = 0;
	mWidth = 0;

	mTexture = NULL;
	RenderTo = NULL;
}


Texture::~Texture()
{
	free();
}

SDL_Texture * Texture::LoadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurfacePixel = IMG_Load(path.c_str());
	if (loadedSurfacePixel == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{

	}

	return nullptr;
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
