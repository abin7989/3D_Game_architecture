#pragma once

#include"RenderableObject.h"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
class sphere :public RenderableObject
{
private:
	RenderableObject* RB;
	FileManager* FM;

public:

	sphere(RenderableObject* c, FileManager* d)
	{
		RB = c;
		FM = d;
	}
	void setsphere();
	virtual void deletebuffer() override;
};