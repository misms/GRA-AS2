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

	//this sets a global ambient, no need for ambient on individual lights
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//create and get id for the 'cobble' texture
	int cobbleTextureId = Scene::GetTexture("Textures/cobble.bmp");
	//create a new instance of the floor
	Floor* floor = new Floor(cobbleTextureId);
	floor->size(50);			//scale it up
	floor->position(0, -10, 0); //move floor down 10 units, so that it doesnt collide with the camera
	AddObjectToScene(floor);

	//wall
	Wall* wall = new Wall();
	wall->size(50);				//scale it up
	wall->position(0, 25, -50); //move to the edge of the floor, in front of the camera on launch
	AddObjectToScene(wall);
	
		
	//Create a red light
	static GLfloat lightColour1[] = { 1, 0, 0 };
	Light* light1 = new Light(GL_LIGHT1, lightColour1);	
	//put near the wall (so the light reflects off it
	light1->position(10, 10, -40);		

	AddObjectToScene(light1);
	
	//Create a blue light
	static GLfloat lightColour2[] = { 0, 0, 1 };
	Light* light2 = new Light(GL_LIGHT2, lightColour2);
	//put near the wall, 20 units to the left of the other one
	light2->position(-10, 10, -40);
	AddObjectToScene(light2);

	//Create a lamp
	Lamp* lamp = new Lamp(Scene::GetTexture("Textures/leather.bmp"));
	//put to the right corner of the wall
	lamp->position(30, -5, -45);
	AddObjectToScene(lamp);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
