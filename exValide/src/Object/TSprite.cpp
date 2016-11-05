#include "TSprite.h"



TSprite::TSprite()
{
	//No animations loaded
	bIsAnimated = false;
	bIsAnimationLooped = false;
	currFrameCount = 0;
}


TSprite::~TSprite()
{
	ObjTexture.free(); //Free texture
	rendererPtr = NULL; //Unload renderer
	FlipbookAnim.clear(); //Clear animation data
}

void TSprite::InitSprite(SDL_Renderer * targetRenderer, bool isImage, std::string filePathOrText, SDL_Color color, int txtSize)
{
	rendererPtr = targetRenderer;

	if(rendererPtr)
	{
		//If we are an image, load the image from path with color as our colorkey
		if (isImage)
		{
			ObjTexture.LoadFromFile(filePathOrText, color);
		}
		else
		{
			ObjTexture.LoadFromText(filePathOrText, color, txtSize);
		}

		//Update Bounding box to reflect whatever our texture is
		SBBox.h = ObjTexture.getHeight();
		SBBox.w = ObjTexture.getWidth();
	}
	else
	{
		printf("ERROR: No Render Target Specified!\n");
	}

	
}


void TSprite::InitSprAnim(int xStartPos, int yStartPos, int frameWidth, int frameHeight, int maxFrames, int frameCycle, std::string AnimationName, bool readHorizontally)
{
	//Check if animation is already exisiting
	if (FlipbookAnim.count(AnimationName) == 1)
	{
		printf("Existing Animation \"%s\" already in Flipbook! Ignoring Initialize Animation...\n", AnimationName);
	}
	else 
	{
		//Make new AnimationData struct pointer
		AnimationData* newAnimData; //Oh joy pointers
		newAnimData = new AnimationData;

		//Set frameCycle and max number of frames this animation has
		newAnimData->frameCycle = frameCycle;
		newAnimData->maxFrameRange = maxFrames;

		//Set up temporary Rectangle struct to clip sprite frame out
		SDL_Rect tempClip;

		//Set sprite clips
		for (int fIndex = 0; fIndex < maxFrames; fIndex++)
		{
			//Example Calculations
			//gSpriteClips[0].x = 0;	//xStartPos = 0; MaxIndex = 4
			//gSpriteClips[0].y = 0;	//yStartPos = 0; Not Moving vertically (downwards)
			//gSpriteClips[0].w = 64;	//Should be consistent
			//gSpriteClips[0].h = 205;	//Should be consistent

			//gSpriteClips[1].x = 64; //0 + (64*1) [ie: frameWidth * index]
			//gSpriteClips[1].y = 0;
			//gSpriteClips[1].w = 64;
			//gSpriteClips[1].h = 205;

			//gSpriteClips[2].x = 128;//0 + (64*2) [ie: frameWidth * index]
			//gSpriteClips[2].y = 0;
			//gSpriteClips[2].w = 64;
			//gSpriteClips[2].h = 205;

			//Calculate the the frames using the size of the image and divide it up horizontally or vertically
			if (readHorizontally)
			{
				tempClip.x = (xStartPos + (frameWidth * fIndex));
				tempClip.y = yStartPos;
			}
			else //vertically
			{
				tempClip.x = xStartPos;
				tempClip.y = (yStartPos + (frameHeight* fIndex));
			}
			
			//Should be consistant
			tempClip.w = frameWidth;
			tempClip.h = frameHeight;

			//Push frame data to this animation's frame data array/vector
			newAnimData->SprFrameClips.push_back(tempClip);
		}//END FOR fIndex
		
		//Insert into the map
		FlipbookAnim.emplace(AnimationName, newAnimData);

		//Do I need to do this to clean up dangling pointers???
		//newAnimData = NULL;

	}//END IF (FlipbookAnim.count(AnimationName) == 1)

}

void TSprite::SetFrame(int frame)
{
	currFrameCount = frame;
}

void TSprite::PauseAnim()
{
	bIsAnimated = false;
}

void TSprite::PlayAnim()
{
	bIsAnimated = true;
}

Texture * TSprite::GetSpriteTexture()
{
	return &ObjTexture;
}
