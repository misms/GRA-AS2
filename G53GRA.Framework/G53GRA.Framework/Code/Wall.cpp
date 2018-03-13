#include "Wall.h"
#define NUM_PARTS 30

Wall::Wall()
{}

void Wall::Display()
{
	glPushMatrix();

	glColor3f(0.5f, 0.5f, 0.5f);

	float partSize = 2.f / NUM_PARTS;

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);

	for (float x = -1.f; x < 1.f; x += partSize) {
		for (float y = -1.f; y < 1.f; y += partSize) {
			glVertex3f(x, y, 0);
			glVertex3f(x + partSize, y, 0);
			glVertex3f(x + partSize, y + partSize, 0);
			glVertex3f(x, y + partSize, 0);
		}
	}
	glEnd();
	glPopMatrix();
}