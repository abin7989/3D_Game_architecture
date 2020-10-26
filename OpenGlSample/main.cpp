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
#include "gamecontroller.h"

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
	cubeobj->setMVP(glm::vec3(25, 0, 0));
	cubeobj->setLight(glm::vec3(0, 0, 10));
	cubeobj->setLight2(glm::vec3(0, 0, 10));	
	float speed = -0.1f;
	cubeobj->settrans(speed, glm::vec3(0.0f, 10.0f, 0.0f));


	//sphere의 정점 정보만을 입력하기 위해 렌더러 오브젝트와 파일매니저 생성.
	FileManager* file2 = new FileManager;
	RenderableObject* sp = new RenderableObject;
	render->addObject(sp);
	sphere* sphere1 = new sphere(sp, file2);

	//spher를 제외한 다른 오브젝트 설정 불가.
	sphere1->setsphere();

	//화면에 안보이는 컨트롤
	gamecontroller* ann = new gamecontroller;
	//컨트롤 대상,회피할 오브젝트
	ann->getunit(sphere1, cubeobj, sw);
	//업데이트에 추가
	render->addupdate(ann);
	
	do {
		render->render();
		//화면에 보이진 않지만 실행 가능.
		render->update();
		sw->Swapbuffers();
	} 
	while (sw->checkwindow());

	render->deletebuffer();

	delete sp;
	delete cube1;
	delete file;
	delete file2;
	delete render;
	delete ann;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}