#ifndef TSPRITE_H
#define TSPRITE_H

#include "../Texture.h"
#include "AObject.h"
#include <vector>


class TSprite :	public AObject
{
public:
	TSprite();
	~TSprite();

	struct AnimationData
	{
		std::string AnimationName;
		//From a given sprite sheet, animations can be used by flipping through a frame range. //DEVELOPMENT
		int maxFrameRange;
		std::vector<SDL_Rect> SprFrameRects;
	};

	/*@brief Initialize sprite to be ready to displayed, Sets bounding box to entire image or text initially
	@param targetRenderer the renderer to be used when sprite is loaded
	@param isImage this bool sets if the sprite used is an Image or if it's text
	@param filePathOrText used for file path to image or the text to be displayed as the sprite
	@param color SDL_Color struct for keying out the image color or the text color to be used
	@param txtSize ONLY USED WITH TEXT, DEFAULT 24pt
	*/
	void InitSprite(SDL_Renderer* targetRenderer, bool isImage, std::string filePathOrText, SDL_Color color, int txtSize = 24);

	/* TODO - Parse data from json? easier to specify stuff perhaps
	@brief Initialize an animation for a sprite from the current Sprite Image/Sheet
	@param xStartPosition, used to determine the starting x position of the animation
	@param yStartPosition, used to determine the starting y position of the animation
	@param frameHeight, frameWidth, the height and width of a single frame to be used in animation
	@param maxFrames, max number of frames this animation will have
	@param AnimationName, The name of the animation to be stored for later reference if needed
	*/
	void InitSprAnim(int xStartPos, int yStartPos, int frameWidth, int frameHeight, int maxFrames, std::string AnimationName = "Anim_Default");

	void SetFrame(int frame);

protected:
	Texture ObjTexture;

	//Sprite Bounding Box, reflects MAXIMUM size of the sprite. Used for simple Collision Checks
	SDL_Rect SBBox;

	std::vector<AnimationData> FlipbookAnim;

	bool bIsAnimated; //True if sprite is animated, false if it sprite is not //DEVELOPMENT
	int numSkins; //Number of alternate skins a sprite has //DEVELOPMENT
	
	SDL_Renderer* rendererPtr; //Pointer to renderer, make sure this is set by calling InitSprite
};

#endif /*TSPRITE_H*/