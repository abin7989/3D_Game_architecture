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
	int Distinction;
	float y_point = 0;
	float z_point = 0;
	sphere(RenderableObject* c, FileManager* d)
	{
		RB = c;
		FM = d;
	}

	void settrans(glm::vec3 t);
	void setsphere();
	virtual void deletebuffer() override;
};