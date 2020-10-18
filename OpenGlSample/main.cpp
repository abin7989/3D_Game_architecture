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



	//shader setting,Use 
	//load obj,texture
	FileManager* fm = new FileManager;
	fm->setVertexArray();
	fm->setprogramID("20161364_vs.shader","20161364_fs.shader");
	fm->setobj("cube.obj");
	fm->setTexture("uvtemplate.DDS");

	// MVP setting
	RenderableObject* cube1 = new RenderableObject;
	objdata* cubeobj = new objdata(cube1);
	cubeobj->buildvertices(fm->getvertices(), fm->getuvs(), fm->getnormals());
	cubeobj->setMVP(glm::vec3(8, 6, 6));
	cubeobj->setLight(fm->getLightID(), glm::vec3(0, 0, 10));
	cubeobj->setLight(fm->getLightID2(), glm::vec3(0, 0, 10));
	cubeobj->settrans(glm::vec3(0.0f, 0.0f, 0.0f));


	//sphere의 정점 정보만을 입력하기 위해 렌더러 오브젝트와 파일매니저 생성.
	RenderableObject* sp = new RenderableObject;
	FileManager* fm2 = new FileManager;
	sphere* sphere1 = new sphere(sp, fm2);

	//spher를 제외한 다른 오브젝트 설정 불가.
	sphere1->setsphere();

	
	Renderer* drawcube1 = new Renderer(cube1);
	Renderer* drawsphere = new Renderer(sp);


	do {
		cubeobj->setCubeRot(0.5f, glm::vec3(0.0f, 0.0f, 1.0f));
		cubeobj->getMVP();

		drawcube1->clearNtext(fm->getTexture(), fm->getTextureID());
		drawcube1->MVPuniform(fm->getMatrixID(), fm->getModelMatrixID(), fm->getViewMatrixID());
		drawcube1->render(fm->getvertices());
		
		drawsphere->MVPuniform(fm2->getMatrixID(), fm2->getModelMatrixID(), fm2->getViewMatrixID());
		drawsphere->render(fm2->getvertices());

		sw->Swapbuffers();
	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(sw->getwindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(sw->getwindow()) == 0);

	// Cleanup VBO and shader
	cube1->deletebuffer();
	sp->deletebuffer();
	fm->deletebuffer();
	fm2->deletebuffer();

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}