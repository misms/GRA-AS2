#include "Lamp.h"
#include "Light.h"

#define _USE_MATH_DEFINES 
#include <math.h>

void drawCylinder(float h, float r, int textureNum)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureNum);

	//the 'resolution' determines how many quads to draw. num quads = 2pi / resolution
	float resolution = 0.1f * M_PI; 

	//initial x,z before any rotation
	float x1 = r;		
	float z1 = 0.0f;
	float x2;
	float z2;

	//angle starts at 0, goes up to 2pi
	float angle = 0.0f;

	//texture x co-ordinate, this will go from 0 to 1
	float tx1 = 0.0f;
	float tx2;

	glBegin(GL_QUADS);
		do
		{
			angle += resolution;
			tx2 = angle / (2 * M_PI);
			x2  = r*cos(angle);
			z2  = r*sin(angle);

			//outer face
			{
				glNormal3f(x1, 0, z1);
				glTexCoord2f(tx1, 0);
				glVertex3f(x1, 0.0f, z1);

				glNormal3f(x1, 0, z1);
				glTexCoord2f(tx1, 1);
				glVertex3f(x1, h, z1);

				glNormal3f(x2, 0, z2);
				glTexCoord2f(tx2, 1);
				glVertex3f(x2, h, z2);

				glNormal3f(x2, 0, z2);
				glTexCoord2f(tx2, 0);
				glVertex3f(x2, 0.f, z2);
			}

			//inner face (draw in reverse, invert normals)
			{
				glNormal3f(-x2, 0, -z2);
				glTexCoord2f(tx2, 0);
				glVertex3f(x2, 0.f, z2);

				glNormal3f(-x2, 0, -z2);
				glTexCoord2f(tx2, 1);
				glVertex3f(x2, h, z2);

				glNormal3f(-x1, 0, -z1);
				glTexCoord2f(tx1, 1);
				glVertex3f(x1, h, z1);

				glNormal3f(-x1, 0, -z1);
				glTexCoord2f(tx1, 0);
				glVertex3f(x1, 0.0f, z1);
			}

			//update x1 to x2, and so on (for next cycle)
			x1 = x2;
			z1 = z2;
			tx1 = tx2;
		} while (angle <= 2 * M_PI);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void Lamp::Display() {

	glPushMatrix();
	{
		// apply the DisplayableObject attributes (defined in MyScene.cpp)
		glTranslatef(pos[0], pos[1], pos[2]);		//position
		glScalef(scale[0], scale[1], scale[2]);		//scale

		// set the color to white, so that the texure shows in its true colors
		glColor3f(1, 1, 1);

		// draw the 'light stand' as a cylinder, 20 units tall, 1 unit wide, from 10 units down
		glTranslatef(0, -10, 0);
		drawCylinder(20, 1, textureNum);

		// draw the lampshade also as a cylinder, 5 units tall, 5 units wide, from the top of the light stand
		glTranslatef(0, 18, 0);
		drawCylinder(5, 5, textureNum);
	}
	glPopMatrix();

	// create a new light instance (on GL_LIGHT3)
	static GLfloat color[] = { 0.6f, 0.6f, 0.6f };		// a slightly dim white
	Light* light = new Light(GL_LIGHT3, color);
	light->position(pos[0], pos[1] + 11, pos[2]);		// position it at the top of the light stand
	light->Display();
}
