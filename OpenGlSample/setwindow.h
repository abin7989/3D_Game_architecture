#pragma once

#include <Windows.h>
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
	static setwindow* instance()
	{
		static setwindow instance;
		return &instance;
	}
	void setwindowsize(int a, int b);
	inline GLFWwindow* getwindow() const { return window; };
	//������ ����
	void Createwindow(const char* windowname);
	//���콺��ġ ����
	void setmiddlemouse();
	//������ â ����
	void windowcolor(float a, float b, float c, float d);
	//���� ����,����
	void setdepth(GLenum cap, GLenum func, GLenum endc);
	//���� ��ȯ
	void Swapbuffers();
	// Check if the ESC key was pressed or the window was closed
	bool checkwindow();
};