#ifndef GLOBALDEF_H
#define GLOBALDEF_H

#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <cmath>

//Screen dimension constants, can be changed down line
const int SCREEN_WIDTH_SD = 640;
const int SCREEN_HEIGHT_SD = 480;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const std::string BUILD_VER = "ExValide Build 0.10";

//Colors
const SDL_Color CWhite = {255,255,255, 255}; //WWhite
const SDL_Color CBlack = { 0, 0, 0, 255 }; //Black
const SDL_Color CRed = { 255, 0, 0, 255 }; //Red
const SDL_Color CGreen = { 0, 255, 0, 255 }; //Green
const SDL_Color CBlue = { 0, 0, 255, 255 }; //Blue
const SDL_Color CYellow = { 255, 255, 0, 255 }; //Yellow
const SDL_Color CCyan  = {0, 255, 255, 255 }; //Cyan
const SDL_Color CMagenta = {255, 0, 255, 255 }; //Magenta
const SDL_Color COrange = {243, 156, 18, 255 }; //Orange
const SDL_Color CPurple = {169, 7, 228, 255 }; //Purple
const SDL_Color CTurquoise = {26, 188, 156, 255 }; //Turquoise
const SDL_Color CSilver = {189, 195, 199, 255 }; //Silver
const SDL_Color CEmerald = {46, 204, 113, 255 }; //Emerald
const SDL_Color CTransparent{ 0,0,0,0 }; //Transparent
//End Colors

//Resources file used for FileManager
const std::string RESOURCE_FILE_PATH = "res/resources.txt";

//Used for determining Engine interactions 
enum OBJ_FLAGS
{
	ASSET_DATA,		//IGNORES MOVEMENT, IGNORE TRACES, NOT USED IN PHYSICS
	ASSET_STATIC,	//STATIC NON-MOVABLE, CAN BLOCK MOVEMENT, CAN BLOCK TRACES
	ASSET_QUERY,	//IGNORE MOVEMENT BUT CAN BLOCK TRACES (think of trigger boxes)
	ASSET_PHYSICS,	//CAN MOVE AND BE INFLUENCED BY PHYSICS BUT IGNORES TRACES (ie. debris chunk from rubble but player cannot walk on it)
	ASSET_ALL		//COMBINATION OF PHYSICS AND TRACES
};

//Used for classifying AObject Class
enum OBJ_TYPE
{
	NONE,			//NULL|UNINITIALIZED
	WORLD_STATIC,	//BACKGROUND TILES, SHOULDN'T CHANGE
	WORLD_DYNAMIC,	//ROCKS, TREES? WORLD OBJECTS THAT ARE INTERACTABLE
	WORLD_ACTOR,	//FRIENDLY NPCS, PLAYER, MERCHANTS?? STUFF THAT DOESN'T ATTACK PLAYERS
	WORLD_ENEMY,	//STUFF THAT DOES ATTACK PLAYERS
	WORLD_EFFECTS	//MAYBE FOR EFFECTS/PARTICLES??
};

//2D Vector
class Vector2
{
public:
	//Constructor
	inline Vector2() { x = 0; y = 0; };
	//Destructor
	inline ~Vector2() { };

	//Non-Default constructor
	inline Vector2(float xVal, float yVal) { x = xVal, y = yVal; };

	//Overload Add vector 2d
	inline Vector2 operator+(Vector2 vec2) { return Vector2(x + vec2.x, y + vec2.y); };

	//Overload Subtract vector 2d
	inline Vector2 operator-(Vector2 vec2) { return Vector2(x - vec2.x, y - vec2.y); };

	//Overload Multiply vector2d
	inline Vector2 operator*(Vector2 vec2) { return Vector2(x * vec2.x, y * vec2.y); };

	//Overload Divide vector2d
	inline Vector2 operator/(Vector2 vec2) { return Vector2(x / vec2.x, y / vec2.y); };

	//Overload Multiply scalar
	inline Vector2 operator*(float scalar) { return Vector2(x * scalar, y * scalar); };

	//Overload Divide scalar
	inline Vector2 operator/(float scalar) { return Vector2(x / scalar, y / scalar); };

	//Return dot product of this vector and another vector
	inline float dot(Vector2 vec2) { return (x * vec2.x ) + (y * vec2.y); };

	//Return cross product of this vector and another vector
	inline float dot(Vector2 vec2) { return (x * vec2.x) - (y * vec2.y); };

	//Cross product 3d case
	//inline Vector3 cross(Vector3 vec3) {return Vector3(y * vec3.z – z * vec3.y, z * vec3.x – x* vec3.z, x* vec3.y – y*vec3.x); };

	//Length of the vector
	inline float length() { return sqrt(x*x + y*y);  };

	//Square of the Length of vector, useful for 
	inline float squaredLength() { return sqrt(x*x + y*y); };

	//normalize***
	//inline float unit() { return (this / this->length()); };



	float x;
	float y;
};

//Unused for now
//3D Vector
struct Vector3
{
	float x;
	float y;
	float z;
};



#endif /*END GLOBALDEF_H */