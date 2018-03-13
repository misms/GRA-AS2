#include "Light.h"

Light::Light(GLenum lightEnum, GLfloat* lightColour)
	:lightEnum(lightEnum)
{
	diffuse = lightColour;
	specular = lightColour;
}

void Light::Display()
{
	glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2]);
		drawBulb();
	glPopMatrix();

	GLfloat position[] = { pos[0], pos[1], pos[2], 1 };
	glLightfv(lightEnum, GL_POSITION, position);

	glLightfv(lightEnum, GL_AMBIENT, ambient);
	glLightfv(lightEnum, GL_DIFFUSE, diffuse);
	glLightfv(lightEnum, GL_SPECULAR, specular);
	
	glLightf(lightEnum, GL_LINEAR_ATTENUATION, 0.025f);
	glLightf(lightEnum, GL_QUADRATIC_ATTENUATION, 0.005f);

	glEnable(lightEnum);
}

void Light::drawBulb() {
	glDisable(GL_LIGHTING); //so it appears bright
	glColor3f(diffuse[0], diffuse[1], diffuse[2]);

	glBegin(GL_TRIANGLES);
		glVertex3i(-1, -1, -1);
		glVertex3i(1, 1, -1);
		glVertex3i(-1, 1, 1);

		glVertex3i(-1, -1, -1);
		glVertex3i(1, -1, 1);
		glVertex3i(1, 1, -1);

		glVertex3i(-1, -1, -1);
		glVertex3i(-1, 1, 1);
		glVertex3i(1, -1, 1);

		glVertex3i(1, -1, 1);
		glVertex3i(-1, 1, 1);
		glVertex3i(1, 1, -1);
	glEnd();
	glEnable(GL_LIGHTING);
}
