#include "Lamp.h"
#include "Light.h"

#define _USE_MATH_DEFINES 
#include <math.h>

void outerCylinder(float h, float tr, float br)
{
	float res = 0.1f * M_PI;
	float x, z;
	float progress;
	float ratio = tr / br;

	glBegin(GL_QUAD_STRIP);
		for (float t = 0.f; t <= 2 * M_PI; t += res)
		{
			progress = t / (2 * M_PI);
			x = br*cos(t);
			z = br*sin(t);

			glNormal3f(x, 0, z);

			glTexCoord2f(progress, 0);
			glVertex3f(x, 0.f, z);
			glTexCoord2f(progress, 1);
			glVertex3f(x * ratio, h, z * ratio);
		}

		glNormal3f(0, 0, -1);
		glTexCoord2f(1, 0);
		glVertex3f(br, 0.f, 0.f);
		glTexCoord2f(1, 1);
		glVertex3f(tr, h, 0.f);
	glEnd();
}

void innerCylinder(float h, float tr, float br)
{
	float res = 0.1f * M_PI;
	float x, z;
	float progress;
	float ratio = tr / br;

	glBegin(GL_QUAD_STRIP);
		for (float t = 2 * M_PI; t >= 0; t -= res)
		{
			progress = t / (2 * M_PI);
			x = br*cos(t);
			z = br*sin(t);

			glNormal3f(-x, 0, -z);

			glTexCoord2f(progress, 0);
			glVertex3f(x, 0.f, z);
			glTexCoord2f(progress, 1);
			glVertex3f(x * ratio, h, z * ratio);
		}
		glNormal3f(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(br, 0.f, 0.f);
		glTexCoord2f(0, 1);
		glVertex3f(tr, h, 0.f);
	glEnd();
}

void cylinder(float h, float tr, float br, GLuint textureNum)
{
	float res = 0.1f * M_PI;
	float x, z;           
	float progress;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureNum);

	outerCylinder(h, tr, br);
	innerCylinder(h, tr, br);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}


void Lamp::Display() {

	glPushMatrix();

		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);

		glColor3f(1, 1, 1);
		
		glTranslatef(0, -10, 0);
		cylinder(20, 1, 1, textureNum);

		glTranslatef(0, 20, 0);
		//lampshade (textured)
		cylinder(5, 1, 5, textureNum);


	glPopMatrix();

	//light (spotlight?)
	static GLfloat colour[] = { 0.6f, 0.6f, 0.6f };
	Light* light = new Light(GL_LIGHT3, colour);
	light->position(pos[0], pos[1] + 12.5, pos[2]);
	light->Display();
	//light stand
	//glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	//gluCylinder(gluNewQuadric(), 1, 2, 10, 10, 1);
	//glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
}
