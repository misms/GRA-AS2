#include "Floor.h"

#define NUM_PARTS 10

Floor::Floor(GLuint textureNum)
	:textureNum(textureNum){}

void Floor::Display()
{
	glPushMatrix();

	glColor3f(1.f, 1.f, 1.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureNum);

	float partSize = 2.f / NUM_PARTS;

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);

	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);

	for (float x = -1.f; x < 1.f; x += partSize) {
		for (float y = -1.f; y < 1.f; y += partSize) {
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, 0, y);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, 0, y + partSize);

			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x + partSize, 0, y + partSize);

			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x + partSize, 0, y);

		}
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
