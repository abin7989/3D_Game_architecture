#pragma once
#include <iostream>

#include <stdio.h>
#include "Object.h"
#include "IUpdater.h"
class NonRenderableObject : public Object, public IUpdater
{
public:
	virtual void deletebuffer() override {};
	virtual void update() override {};
};