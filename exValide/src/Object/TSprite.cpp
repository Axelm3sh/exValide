#include "TSprite.h"

TSprite::TSprite()
{
	worldX = worldY = 0; //Default position
	//No animations loaded
	bIsAnimated = false;
	bIsAnimationLooped = false;
	currentClipRect = NULL;

	//No offset yet
	textureXOffset = textureYOffset = 0;

	currentFrameCount = 0;
	rotationAngle= 0.0;
	flipMode = SDL_FLIP_NONE;

	numSkins = 0;//FIXME

	//TSprite should be used in conjuction by inheritence, nothing used but positional render by default
	objFlag = OBJ_FLAGS::ASSET_DATA;
	objType = OBJ_TYPE::NONE;
}


TSprite::~TSprite()
{
	ObjTexture.free(); //Free texture
	rendererPtr = NULL; //Unload renderer
	
	//FIXME Cleanup
	currentClipRect = NULL; //Unload referenced data from CurrentAnimation
	CurrentAnimation = NULL; //Unload referenced data from Flipbook
	
	FlipbookAnim.clear(); //Clear animation data
}

void TSprite::InitSprite(SDL_Renderer * targetRenderer, bool isImage, std::string filePathOrText, SDL_Color color, int txtSize)
{
	rendererPtr = targetRenderer;

	if(rendererPtr)
	{
		ObjTexture.setRenderTo(rendererPtr); //DON'T FORGET THIS, RIP 3 hours life

		//If we are an image, load the image from path with color as our colorkey
		if (isImage)
		{
			ObjTexture.LoadFromFile(filePathOrText, color);
		}
		else //Else we are text so create text from the string and set our color and size
		{
			ObjTexture.LoadFromText(filePathOrText, color, txtSize);
		}

		//Calculate render offset first
		UpdateTextureOffset();

		//Update Bounding box to reflect whatever our render texture is
		UpdateBoundingBox();
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
		printf("Existing Animation \"%s\" already in Flipbook! Ignoring Initialize Animation...\n", AnimationName.c_str());
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
			/*********************************
			Example Calculations
			//gSpriteClips[0].x = 0;	//xStartPos = 0; MaxIndex = 4
			//gSpriteClips[0].y = 0;	//yStartPos = 0; Not Moving vertically (downwards)
			//gSpriteClips[0].w = 64;	//Should be consistent
			//gSpriteClips[0].h = 205;	//Should be consistent

			//gSpriteClips[1].x = 64; //0 + (64*1) [ie: frameWidth * index]
			//gSpriteClips[1].y = 0;
			//gSpriteClips[1].w = 64;
			//gSpriteClips[1].h = 205;
			*********************************/

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

	}//END IF (FlipbookAnim.count(AnimationName) == 1)

}

void TSprite::SetFrame(int frame)
{
	currentFrameCount = frame;
}

bool TSprite::SetAnimation(std::string animName, bool animPlay)
{
	bool success = false;

	//Check to see if AnimationData exists within current flipbook
	if (FlipbookAnim.find(animName) != FlipbookAnim.end())
	{
		//Set the current Animation to the referenced animation data
		CurrentAnimation = FlipbookAnim.find(animName)->second;

		//Check to see if we want to play the animation right away
		if (animPlay)
		{
			//Animated is true 
			bIsAnimated = true;
		}

		//and reset current frame to beginning
		currentFrameCount = 0;
		//Load up first frame clip data for render from currentAnimation
		currentClipRect = &CurrentAnimation->SprFrameClips.at(currentFrameCount);

		if (currentClipRect)
		{
			//Update the texture offset using newly loaded frame
			UpdateTextureOffset();
			//Update Bounding box
			UpdateBoundingBox();
			
		}
		
		success = true;
	}

	return success;
}

void TSprite::PauseAnim()
{
	bIsAnimated = false;
}

void TSprite::PlayAnim()
{
	bIsAnimated = true;
}

//TODO - allow for non-vsync frame updates, right now it's constrained to the 60fps buffer
void TSprite::FrameUpdate()
{
	if (bIsAnimated) //Only need to animate when we have our animation bool as true
	{
		//Check if our current Animation is loaded
		if (CurrentAnimation != NULL)
		{
			/***************************
			Animation calculation is processed by incrementing a frameCounter, with that value divided by a frameRate
			to get the index cell of the current clipping frame within our AnimationData. 
			Should frameCounter reach frameRate*maxFrameRange(max animation frames) we reset frameCounter to 0;

			****************************/
			++currentFrameCount; //Increment the frame counter

			//If we exceeded the max frame range (which is maxFrameRange * frameCycle), reset the animation
			if (currentFrameCount >= (CurrentAnimation->maxFrameRange * CurrentAnimation->frameCycle))
			{
				currentFrameCount = 0;
			}

			//Access the vector of Rectangles containing clip data, uses integer division for cell access
			currentClipRect = &CurrentAnimation->SprFrameClips.at(int(currentFrameCount / CurrentAnimation->frameCycle));
			
		}
		else
		{
			printf("Error, Animation Failed to Update! Check to see if CurrentAnimation is loaded!");
			currentFrameCount = 0;
		}//END if (CurrentAnimation!=NULL)

	}//END if(bIsAnimated)

	//Update stuff
	UpdateTextureOffset();
	UpdateBoundingBox();
}

void TSprite::RenderSprite()
{
	//Set the origin of rotation in relative texture space, so instead of the top-left corner (0,0), it should be the Offset values
	SDL_Point rotationOrigin;
	rotationOrigin.x = abs(textureXOffset);
	rotationOrigin.y = abs(textureYOffset);

	//Finalize and copy the Sprite to the Render queue
	ObjTexture.render((worldX-textureXOffset), (worldY-textureYOffset), currentClipRect, rotationAngle, &rotationOrigin, flipMode);
}

Texture * TSprite::GetSpriteTexture()
{
	return &ObjTexture;
}

SDL_Rect* TSprite::GetBoundingBox()
{
	return &SBBox;
}

void TSprite::UpdateBoundingBox()
{
	//Calculate worldSpace Position
	SBBox.x = (worldX - textureXOffset);
	SBBox.y = (worldY - textureYOffset);

	if (bIsAnimated) //use clip rects
	{
		SBBox.h = currentClipRect->h;
		SBBox.w = currentClipRect->w;
	}
	else //No animation, thus calculate by texture width and height?
	{
		SBBox.h = GetSpriteTexture()->getHeight();
		SBBox.w = GetSpriteTexture()->getWidth();
	}
}

void TSprite::UpdateTextureOffset()
{
	if (bIsAnimated)
	{
		if (currentClipRect)
		{
			textureXOffset = currentClipRect->w / 2;
			textureYOffset = currentClipRect->h / 2;
		}
		else
		{
			printf("Error: UpdatingtextureOffset Failed with currentClipRect");
		}
	}
	else //Use actual texture height and width
	{
		textureXOffset = GetSpriteTexture()->getWidth() / 2;
		textureYOffset = GetSpriteTexture()->getHeight() / 2;
	}
}

void TSprite::SetXPos(int positionX)
{
	worldX = positionX;
}

void TSprite::SetYPos(int positionY)
{
	worldY = positionY;
}

int TSprite::GetXPos() const
{
	return worldX;
}

int TSprite::GetYPos() const
{
	return worldY;
}

void TSprite::SetRotation(double angle)
{
	rotationAngle = angle;
}

double TSprite::GetRotation() const
{
	return rotationAngle;
}

void TSprite::SetFlipMode(SDL_RendererFlip flag)
{
	flipMode = flag;
}

SDL_RendererFlip TSprite::GetFlipMode()
{
	return flipMode;
}
