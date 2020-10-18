#pragma once

#include<iostream>
#include<string>
#include <vector>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ICleanUp.h"
#include "FileManager.h"

class Object : public ICleanUp
{
public:
	virtual ~Object() {}
};


