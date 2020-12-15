#pragma once

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "interface/ICleanUp.h"
#include "FileManager.h"
#include "ObjectDelete.h"
#include "ObjectInit.h"
#include "interface/IInit.h"
#include "ObjectUpdater.h"
#include "interface/IU.h"

class Object : public ICleanUp, public IInit, public IU
{
public:
	Object()
	{
		ObjectDelete::instance()->addObject(this);
		ObjectInit::instance()->addObject(this);
		ObjectUpdater::instance()->addObject(this);
	}
	virtual ~Object() {}
};


