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
	//윈도우 생성
	void Createwindow(const char* windowname);
	//마우스위치 조정
	void setmiddlemouse();
	//윈도우 창 색상
	void windowcolor(float a, float b, float c, float d);
	//버퍼 깊이,투명도
	void setdepth(GLenum cap, GLenum func, GLenum endc);
	//버퍼 교환
	void Swapbuffers();
	// Check if the ESC key was pressed or the window was closed
	bool checkwindow();
};