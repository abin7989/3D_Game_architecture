#pragma once

#include <vector>
#include "RenderableObject.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")


class Renderer
{
public:
	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}

public:

	
	void render(RenderableObject* RB);
};