#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>


//Wrapper class that does texture related things for you
class Texture
{
public:
	Texture();
	~Texture();

	SDL_Texture* LoadTexture(std::string path);

	//loads image from specified path
	bool LoadFromFile(std::string path);

	bool LoadFromText(std::string text, SDL_Color textColor);

	//Deallocates Texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Blend mode
	void setBlendMode(SDL_BlendMode blend);

	//Alpha channel set
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, 
				SDL_Rect* clip = NULL, 
				double angle = 0.0,
				SDL_Point* center = NULL, 
				SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:

	//Actual hardware texture
	SDL_Texture* mTexture;

	int mHeight; //Height of image
	int mWidth; //Width of image

	//Render to apply to
	SDL_Renderer* RenderTo; //Todo code functions to set it
};

#endif