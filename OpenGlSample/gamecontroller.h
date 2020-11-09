#pragma once

#include "NonRenderableObject.h"
#include "IU.h"
#include "sphere.h"
#include "objdata.h"
#include "setwindow.h"
#include "ObjectUpdater.h"

class gamecontroller :public NonRenderableObject, public IU
{
	sphere* sp;
	objdata* ob;
	setwindow* sw;
	
	float ran = 0;
	float speed = -0.1f;
	bool gamestart = false;
public:
	gamecontroller(sphere* a, objdata* b, setwindow* c)
	{
		getunit(a, b, c);
		ObjectUpdater::instance()->addObject(this);
	}

	void gameControll();

	void getunit(sphere* a, objdata* b, setwindow* c);
	virtual void up() override { gameControll(); };
	virtual void deletebuffer() override {};
};