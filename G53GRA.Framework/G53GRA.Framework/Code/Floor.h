#pragma once
#include "DisplayableObject.h"

class Floor : public DisplayableObject
{
public:
	// the constructor takes in a texture id for displaying on the floor
	Floor(GLuint textureNum) : textureNum(textureNum) {};
	~Floor() {};
	void Display();
private:
	GLuint textureNum;
};

