#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <math.h>

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "setwindow.h"
#include "Object.h"
#include "Renderer.h"
#include "FileManager.h"
#include "RenderableObject.h"
#include "sphere.h"
#include "objdata.h"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#define _CRT_SECURE_NO_WARNINGS

using namespace glm;
using namespace std;

int main(void)
{
	//window setting;
	setwindow* sw = new setwindow(1024,768);
	sw->Createwindow("report", NULL, NULL);
	sw->setmiddlemouse();
	sw->windowcolor(0.0f, 0.0f, 0.4f, 0.0f);
	sw->setdepth(GL_DEPTH_TEST, GL_LESS, GL_CULL_FACE);

	FileManager* file =new FileManager;
	RenderableObject* cube1 = new RenderableObject;
	file->gettarget(cube1);
	file->loadObj(
		"cube.obj",
		"uvtemplate.DDS",
		"20161364_vs.shader",
		"20161364_fs.shader"
		);

	// MVP setting
	
	objdata* cubeobj = new objdata(cube1);
	cubeobj->setMVP(glm::vec3(8, 6, 6));
	cubeobj->setLight(glm::vec3(0, 0, 10));
	cubeobj->setLight2(glm::vec3(0, 0, 10));
	cubeobj->settrans(glm::vec3(0.0f, 0.0f, 0.0f));


	//sphere�� ���� �������� �Է��ϱ� ���� ������ ������Ʈ�� ���ϸŴ��� ����.
	FileManager* fm2 = new FileManager;
	RenderableObject* sp = new RenderableObject;
	sphere* sphere1 = new sphere(sp, fm2);

	//spher�� ������ �ٸ� ������Ʈ ���� �Ұ�.
	sphere1->setsphere();

	
	Renderer* drawcube1 = new Renderer(cube1);
	Renderer* drawsphere = new Renderer(sp);


	do {
		cubeobj->setCubeRot(0.5f, glm::vec3(0.0f, 0.0f, 1.0f));
		drawcube1->clear();

		drawcube1->render();
		drawsphere->render();

		sw->Swapbuffers();
	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(sw->getwindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(sw->getwindow()) == 0);

	// Cleanup VBO and shader
	cube1->deletebuffer();
	sp->deletebuffer();
	file->deletebuffer();

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}