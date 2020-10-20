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
#include "NonRenderableObject.h"
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
	sw->Createwindow("report");
	//sw->setmiddlemouse();
	sw->windowcolor(0.0f, 0.0f, 0.4f, 0.0f);
	sw->setdepth(GL_DEPTH_TEST, GL_LESS, GL_CULL_FACE);


	Renderer* render = new Renderer;
	FileManager* file =new FileManager;
	RenderableObject* cube1 = new RenderableObject;
	render->addObject(cube1);

	//cube1의 obj
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


	//sphere의 정점 정보만을 입력하기 위해 렌더러 오브젝트와 파일매니저 생성.
	FileManager* file2 = new FileManager;
	RenderableObject* sp = new RenderableObject;
	render->addObject(sp);
	sphere* sphere1 = new sphere(sp, file2);

	//spher를 제외한 다른 오브젝트 설정 불가.
	sphere1->setsphere();

	NonRenderableObject* a = new NonRenderableObject;

	do {
		//큐브의 회전 설정
		cubeobj->setCubeRot(0.5f, glm::vec3(0.0f, 0.0f, 1.0f));

		render->update(a);
		render->render();

		sw->Swapbuffers();
	} 
	while (sw->checkwindow());

	render->deletebuffer();

	delete sp;
	delete cube1;
	delete file;
	delete file2;
	delete render;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}