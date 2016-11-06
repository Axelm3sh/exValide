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

	SDL_Texture* LoadTexture(std::string path, SDL_Color keyColor);

	//loads image from specified path, default color key is cyan, DO NOT USE IF RENDERER IS NOT SET
	bool LoadFromFile(std::string path, SDL_Color keyColor = CCyan);

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

	/*@brief: Renders texture with given variables applied.
	@param x X-pos to shift texture
	@param y Y-pos to shift texture
	@param clip The Rectangle that we use to crop the image, leave this as NULL if you want to display the entire image
	@param angle The degree that the image should be rotated
	@param center The point at which image should be rotated, NULL means rotation will be applied to center of image
	@param flip Used for flipping around the image (ie vertically, horizontally), default is no flip*/
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