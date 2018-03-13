#pragma once
#include "DisplayableObject.h"
class Lamp :
	public DisplayableObject
{
public:
	Lamp(GLuint textureNum) : textureNum(textureNum) {};
	~Lamp() {};
	void Display();
private:
	GLuint textureNum;
};

