#pragma once


#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class setwindow
{
private:
	int width;
	int length;
	GLFWwindow* window;

public:
	setwindow(int a, int b);
	inline GLFWwindow* getwindow() const { return window; };
	//������ ����
	void Createwindow(const char* windowname, GLFWmonitor* a, GLFWwindow* b);
	//���콺��ġ ����
	void setmiddlemouse();
	//������ â ����
	void windowcolor(float a, float b, float c, float d);
	//���� ����,����
	void setdepth(GLenum cap, GLenum func, GLenum endc);
	//���� ��ȯ
	void Swapbuffers();
};