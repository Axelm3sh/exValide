#ifndef TSPRITE_H
#define TSPRITE_H

#include "../Texture.h"
#include "AObject.h"
#include <vector>
#include <map>


class TSprite :	public AObject
{
public:
	TSprite();
	~TSprite();

	//Struct for animation data, not used directly
	struct AnimationData
	{
		//From a given sprite sheet, animations can be used by flipping through a frame range.
		int maxFrameRange;
		//Speed of frames
		int frameCycle; 
		//These are the Rectangles that specify the frame locations inside the animated sprite sheet
		std::vector<SDL_Rect> SprFrameClips;
	};

	/****************************
	*	Methods and Accessors	*
	*****************************/

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
		Calculates the frames by scrolling horizontally for next frame 
			 {{ Rect.X = (xStartPos + (frameWidth*frameNumber)); Rect.Y = yStartPos }} //FIXME, rollover to next row maybe for longer animations?
	@param xStartPosition, used to determine the starting x position of the animation
	@param yStartPosition, used to determine the starting y position of the animation
	@param frameHeight, frameWidth, the height and width of a single frame to be used in animation, should be same number across all anim sFrames
	@param maxFrames, max number of frames this animation will have
	@param frameCycle, determines how long we display a frame, 6 frames by default(ie. A value of 4 would display the current frame 4 times before moving to the next frame)
	@param AnimationName, The name of the animation to be stored for later reference if needed
	@param ReadHorizontally, divide up the animation in the sprite sheet horizontally rather than vertically, true by default (ie: each frames are positioned to the right of the previous frame rather than below)
	*/
	void InitSprAnim(int xStartPos, int yStartPos, int frameWidth, int frameHeight, int maxFrames, int frameCycle = 6, std::string AnimationName = "Anim_Default", bool readHorizontally = true);

	//Override current frame of animation to this frame number;
	void SetFrame(int frame);

	//Set current animation by name, if it doesn't exist default to Anim_Default and return false, Set animPlay to true if you want animation to start playing right after setting animation;
	bool SetAnimation(std::string animName, bool animPlay = false);

	//Play or Pause Animation
	void PauseAnim();
	void PlayAnim();

	//Update current texture with frame
	void FrameUpdate();

	//Wrapper for Texture::Render(), Finalize and Display Sprite on Screen
	void RenderSprite();
	
	//May or may not need?
	Texture* GetSpriteTexture();

private:
	//Actual Texture of sprite
	Texture ObjTexture;

	//Sprite Bounding Box, reflects MAXIMUM size of the sprite. Used for simple Collision Checks
	SDL_Rect SBBox;

	//Current Animation Data
	AnimationData* CurrentAnimation;
	int currFrameCount; //variable for current animation frame currently being displayed, note to self zero-based counter

	//Holds all Animations, pointers of AnimationData
	std::map<std::string,AnimationData*> FlipbookAnim;

	bool bIsAnimated; //Is the sprite animated or not?
	bool bIsAnimationLooped; //Is the animation looped?
	int numSkins; //Number of alternate skins a sprite has //FIXME  -WIP
	
	SDL_Renderer* rendererPtr; //Pointer to renderer, make sure this is set by calling InitSprite
};

#endif /*TSPRITE_H*/