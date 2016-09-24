#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include "GDefinitions.h"

//Wrapper class that does texture related things for you
class Texture
{
public:
	Texture();
	~Texture();

	//CALL THIS FIRST OR ELSE TEXTURE WILL NOT RENDER AT ALL
	void setRenderTo(SDL_Renderer* reference);

	SDL_Texture* LoadTexture(std::string path);

	//loads image from specified path, DO NOT USE IF RENDERER IS NOT SET
	bool LoadFromFile(std::string path);

	//Makes texture from a text string, you can override last 2 parameters for different font size or font file
	bool LoadFromText(std::string text, SDL_Color textColor, int textSize = 28, std::string pathToTFF = "res/fonts/VCR_OSD_MONO_1.001.ttf");

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

	//Font to use for this texture
	TTF_Font* mFont;

	int mHeight; //Height of image
	int mWidth; //Width of image

	//Render to apply to
	SDL_Renderer* RenderTo; //Todo code functions to set it
};

#endif