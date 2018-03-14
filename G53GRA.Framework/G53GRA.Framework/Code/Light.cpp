#include "Light.h"

// Light as a DisplayableObject allows for simple setup of additional lights.
// The light bulb is visualised with a small tetrahedron
Light::Light(GLenum lightEnum, GLfloat* lightColour)
	:lightEnum(lightEnum)
{
	// The diffuse color and specular highlights will match the color passed in the constructor
	// (ambient is 0,0,0 as described in Light.h)
	diffuse = lightColour;
	specular = lightColour;
}

void Light::Display()
{
	glPushMatrix();
		// Apply the DisplayableObject position (defined in MyScene.cpp)
		glTranslatef(pos[0], pos[1], pos[2]);
		drawBulb();
	glPopMatrix();

	// Also set the position of the light to the same as the bulb
	GLfloat position[] = { pos[0], pos[1], pos[2], 1 };
	glLightfv(lightEnum, GL_POSITION, position);

	// Set light ambient, diffuse, specular
	glLightfv(lightEnum, GL_AMBIENT, ambient);
	glLightfv(lightEnum, GL_DIFFUSE, diffuse);
	glLightfv(lightEnum, GL_SPECULAR, specular);
	
	// Set light fall-off. We have chosen to just use linear attenuation for simplicity.
	glLightf(lightEnum, GL_CONSTANT_ATTENUATION, 1.0f);
	glLightf(lightEnum, GL_LINEAR_ATTENUATION, 0.05f);
	glLightf(lightEnum, GL_QUADRATIC_ATTENUATION, 0.0f);

	glEnable(lightEnum);
}

void Light::drawBulb() {
	// The bulb wants to be bright, so we disable lighting when drawing it
	glDisable(GL_LIGHTING);
	// Set color to the same color as the light
	glColor3f(diffuse[0], diffuse[1], diffuse[2]);

	// Draw a simple tetrahedron for the bulb
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
	glEnable(GL_LIGHTING); //re-enable lighting
}
