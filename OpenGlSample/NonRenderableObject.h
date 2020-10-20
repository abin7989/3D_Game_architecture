#pragma once

#include "Object.h"
#include "IUpdater.h"
class NonRenderableObject : public Object, public IUpdater
{
private:
	int a = 0;
public:
	NonRenderableObject() {  };
	~NonRenderableObject() {  };
	virtual void deletebuffer() override {};
	virtual int update() override { return a; };
};