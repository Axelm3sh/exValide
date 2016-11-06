#include "Texture.h"



Texture::Texture()
{
	mHeight = 0;
	mWidth = 0;

	mTexture = NULL;
	mFont = NULL;
	RenderTo = NULL;
}


Texture::~Texture()
{
	free();
}

//Should not really use this explicitly
SDL_Texture * Texture::LoadTexture(std::string path, SDL_Color keyColor)
{
	SDL_Texture* newTexture = NULL;

	printf("\nThe texture path is: %s\n", path.c_str()); //Debug

	SDL_Surface* loadedSurfacePixel = IMG_Load(path.c_str());
	if (loadedSurfacePixel == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image, keying out cyan (taking out the color cyan to see through those parts colored cyan) TODO optimize
		SDL_SetColorKey(loadedSurfacePixel, SDL_TRUE, SDL_MapRGB(loadedSurfacePixel->format, keyColor.r, keyColor.g, keyColor.b));
		
		//Todo create new texture from surface
		newTexture = SDL_CreateTextureFromSurface(RenderTo, loadedSurfacePixel);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
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

bool Texture::LoadFromFile(std::string path, SDL_Color keyColor)
{
	mTexture = LoadTexture(path, keyColor); //Return Texture

	if (mTexture != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Texture::LoadFromText(std::string text, SDL_Color textColor, int textSize, std::string pathToTFF)
{
	bool success = true;

	//Unload exisiting texture
	free();

	//Open the font, default to size 28
	mFont = TTF_OpenFont(pathToTFF.c_str(), textSize);
	if (mFont == NULL)
	{
		printf("Failed to load %s font! SDL_ttf Error: %s\n", pathToTFF.c_str(),TTF_GetError());
		success = false;
	}

	//Converts the font over to a surface we can render
	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, text.c_str(), textColor);
	if (textSurface == NULL) //Check pointer
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(RenderTo, textSurface);
		if (mTexture == NULL) //Check pointer
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	return success;
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

	if (mFont != NULL)
	{
		TTF_CloseFont(mFont);
		mFont = NULL;
	}
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blend)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blend);
}

void Texture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}


void Texture::render(int x, int y, SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
{
	//Create our destination target
	SDL_Rect destination;

	//Set x and y position of our texture
	destination.x = x;
	destination.y = y;

	//Set target rendering dimensions
	if (clip != NULL)
	{
		destination.w = clip->w;
		destination.h = clip->h;
	}

	//Render to screen, Same as RenderCopy but with EXtra angle and flip vars
	//clip is our section of the entire image we want to render if not NULL
	//destination is where inside the renderer we want to display our clipped image
	SDL_RenderCopyEx(RenderTo, mTexture, clip, &destination ,angle, center, flip);
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
