#pragma once

#include "NonRenderableObject.h"
#include "sphere.h"
#include "objdata.h"
#include "setwindow.h"

class gamecontroller :public NonRenderableObject
{
	sphere* sp;
	objdata* ob;
	setwindow* sw;
	
	float ran = 0;
	float speed = -0.3f;
	bool gamestart = false;
public:
	gamecontroller(sphere* a, objdata* b, setwindow* c)
	{
		getunit(a, b, c);
	}

	void gameControll();

	void getunit(sphere* a, objdata* b, setwindow* c);
	virtual void up() override { gameControll(); };
	virtual void deletebuffer() override { };
	virtual void init() override { printf("GameController ON\n"); };
};