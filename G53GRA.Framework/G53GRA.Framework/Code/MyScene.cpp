#include "MyScene.h"
#include "Floor.h"
#include "Wall.h"
#include "Light.h"
#include "Lamp.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{}

void MyScene::Initialise()
{
	//setup background and lighting ambience
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//textured floor
	Floor* floor = new Floor(Scene::GetTexture("Textures/cobble.bmp"));
	AddObjectToScene(floor);
	floor->size(50);
	floor->position(0, -10, 0);

	//wall
	Wall* wall = new Wall();
	AddObjectToScene(wall);
	wall->size(50);
	wall->position(0, 25, -50);
		
	//lights
	static GLfloat lightColour1[] = { 1, 0, 0 };
	Light* light1 = new Light(GL_LIGHT1, lightColour1);
	light1->position(15, 10, -20);
	AddObjectToScene(light1);
	
	static GLfloat lightColour2[] = { 0, 0, 1 };
	Light* light2 = new Light(GL_LIGHT2, lightColour2);
	light2->position(-10, 10, -40);
	AddObjectToScene(light2);

	//lamp
	Lamp* lamp = new Lamp(Scene::GetTexture("Textures/leather.bmp"));
	lamp->position(20, -5, -30);
	AddObjectToScene(lamp);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
