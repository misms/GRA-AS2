#pragma once
#include "DisplayableObject.h"
class Lamp :
	public DisplayableObject
{
public:
	// the constructor takes in a texture id for displaying on the lamp stand and lampshade
	Lamp(GLuint textureNum) : textureNum(textureNum) {};
	~Lamp() {};
	void Display();
private:
	GLuint textureNum;
};

