#pragma once

#include "Object.h"
class NonRenderableObject : public Object
{
public:
	virtual void deletebuffer() override {};
};