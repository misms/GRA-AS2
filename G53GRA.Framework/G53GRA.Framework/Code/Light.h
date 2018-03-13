#pragma once
#include "DisplayableObject.h"

class Light : public DisplayableObject
{
public:
	Light(GLenum lightEnum, GLfloat* lightColour);
	~Light() {};
	void Display();
private:
	void drawBulb();
	GLenum lightEnum;
	GLfloat ambient[3]  = {0, 0, 0};
	GLfloat* diffuse;//  = {1, 1, 1};
	GLfloat* specular;// = {1, 1, 1};
};

