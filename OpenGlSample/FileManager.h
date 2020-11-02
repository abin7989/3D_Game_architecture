#pragma once
#include <vector>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ICleanUp.h"

class RenderableObject;

class FileManager :public ICleanUp
{
public:
	RenderableObject* target_RB;
	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	void gettarget(RenderableObject* a) { target_RB = a; };
	void loadObj(
		const char* obj_path,
		const char* texture_path,
		const char* vs_shader_path,
		const char* fs_shader_path
	);
	//정점정보, 텍스트, 쉐이더 delete
	virtual void deletebuffer() override;


};