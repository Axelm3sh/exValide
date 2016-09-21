#ifndef GLOBALDEF_H
#define GLOBALDEF_H

#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

//Colors
const SDL_Color CWhite = {255,255,255,255};
const SDL_Color CRed = { 255, 0, 0, 255 };
const SDL_Color CGreen = { 0, 255, 0, 255 };
const SDL_Color CBlue = { 0, 0, 255, 255 };
const SDL_Color CBlack = { 0, 0, 0, 255 };
//End Colors

//Resources file used for FileManager
const std::string resFile = "res/resources.txt";

#endif /*END GLOBALDEF_H */