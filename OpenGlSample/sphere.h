#pragma once

#include"CompositeObj.h"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class sphere :public CompositeObj
{
private:
public:

	int Distinction;
	float y_point = 0;
	float z_point = 0;

	void settrans(glm::vec3 t);
	void setsphere();
	virtual void deletebuffer() override;
	virtual void up() override;
	virtual void init() override;
	virtual void render() override { Renderer::instance()->render(this); };
};