#include "Floor.h"

#define NUM_PARTS 10 // This constant defines how much tessellation occurs

void Floor::Display()
{
	glPushMatrix(); // save transformation
	{
		// Set color to white, so the correct texture color is shown
		glColor3f(1.f, 1.f, 1.f);

		// Enable texturing + bind cobble texture
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureNum); // the textureNum is passed in the constructor (from MyScene.cpp)
		
		// Apply the DisplayableObject attributes (defined in MyScene.cpp)
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);

		glBegin(GL_QUADS);
		{
			// Normal remains the same for the whole floor (pointing upwards in the y direection)
			glNormal3f(0.0f, 1.0f, 0.0f);

			// Just like with wall.cpp, we use tesselation to break up the floor into smaller squares
			float partSize = 2.f / NUM_PARTS;
			for (float x = -1.f; x < 1.f; x += partSize) {
				for (float y = -1.f; y < 1.f; y += partSize) {
					glTexCoord2f(0.0f, 0.0f);		// texture
					glVertex3f(x, 0, y);			// vertex
											 
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, 0, y + partSize);

					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x + partSize, 0, y + partSize);

					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x + partSize, 0, y);
				}
			}
		}
		glEnd();
		//unbind + disable textures again, now that the floor is drawn.
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix(); // restore transformation
}
