#include "Wall.h"

#define NUM_PARTS 20 // This constant defines how much tessellation occurs

void Wall::Display()
{
	//wall colour is grey
	glColor3f(0.5f, 0.5f, 0.5f);

	//save current attributes / transformations
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	{
		// Apply the DisplayableObject attributes (defined in MyScene.cpp)
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);

		// Set material specular and shininess properties
		float specular[4] = { .1f, .1f, .1f, 1.f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);

		glBegin(GL_QUADS);
		{
			// The normal will stay constant for all vertices, so only has to be set once
			glNormal3f(0.0f, 0.0f, 1.0f); 

			// Draw the wall as multiple smaller pieces (tesselation)
			// the wall will be made up of NUM_PARTS * NUM_PARTS smaller squares
			float partSize = 2.f / NUM_PARTS;
			for (float x = -1.f; x < 1.f; x += partSize) {
				for (float y = -1.f; y < 1.f; y += partSize) {
					glVertex3f(x, y, 0);
					glVertex3f(x + partSize, y, 0);
					glVertex3f(x + partSize, y + partSize, 0);
					glVertex3f(x, y + partSize, 0);
				}
			}
		}
		glEnd();
	}
	//restore to saved attrib / transformation
	glPopMatrix();
	glPopAttrib();
}