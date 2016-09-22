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

	std::string appendedPath = path;
	appendedPath.insert(0, "res/");//Append res directory

	printf("\nThe texture path is: %s\n", appendedPath.c_str()); //Debug

	SDL_Surface* loadedSurfacePixel = IMG_Load(appendedPath.c_str());
	if (loadedSurfacePixel == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", appendedPath.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image, keying out cyan (taking out the color cyan to see through those parts colored cyan) TODO optimize
		SDL_SetColorKey(loadedSurfacePixel, SDL_TRUE, SDL_MapRGB(loadedSurfacePixel->format, 0, 0xFF, 0xFF));

		//Todo create new texture from surface
		newTexture = SDL_CreateTextureFromSurface(RenderTo, loadedSurfacePixel);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", appendedPath.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurfacePixel->w;
			mHeight = loadedSurfacePixel->h;
		}

		//Free's up old surface
		SDL_FreeSurface(loadedSurfacePixel);
	}

	return newTexture;
}

bool Texture::LoadFromFile(std::string path)
{
	mTexture = LoadTexture(path); //Return Texture

	if (mTexture != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
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

void Texture::render(int x, int y, SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen, Same as RenderCopy but with EXtra angle and flip vars
	SDL_RenderCopyEx(RenderTo, mTexture, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}

void Texture::setRenderTo(SDL_Renderer * reference)
{
	//Point this pointer to the other pointer's pointing thing
	RenderTo = reference;
}
