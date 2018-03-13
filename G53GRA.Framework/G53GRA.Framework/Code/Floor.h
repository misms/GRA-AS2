#pragma once
#include "DisplayableObject.h"

class Floor : public DisplayableObject
{
public:
	Floor(GLuint textureNum);
	~Floor() {};
	void Display();
private:
	GLuint textureNum;
};

