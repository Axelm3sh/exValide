#ifndef GLOBALDEF_H
#define GLOBALDEF_H

#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <cmath>

//Colors
const SDL_Color CWhite = {255,255,255}; //WWhite
const SDL_Color CBlack = { 0, 0, 0 }; //Black
const SDL_Color CRed = { 255, 0, 0}; //Red
const SDL_Color CGreen = { 0, 255, 0}; //Green
const SDL_Color CBlue = { 0, 0, 255}; //Blue
const SDL_Color CYellow = { 255, 255, 0 }; //Yellow
const SDL_Color CCyan  = {0, 255, 255 }; //Cyan
const SDL_Color CMagenta = {255, 0, 255 }; //Magenta
const SDL_Color COrange = {243, 156, 18 }; //Orange
const SDL_Color CPurple = {169, 7, 228 }; //Purple
const SDL_Color CTurquoise = {26, 188, 156 }; //Turquoise
const SDL_Color CSilver = {189, 195, 199 }; //Silver
const SDL_Color CEmerald = {46, 204, 113 }; //Emerald
const SDL_Color CTransparent{ 0,0,0,0 }; //Transparent
//End Colors

//Resources file used for FileManager
const std::string resFile = "res/resources.txt";

#endif /*END GLOBALDEF_H */