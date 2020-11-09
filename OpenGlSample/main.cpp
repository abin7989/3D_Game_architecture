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
#include "Renderer.h"
#include "FileManager.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "sphere.h"
#include "objdata.h"
#include "gamecontroller.h"
#include "Time.h"
#include "ObjectUpdater.h";

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#define _CRT_SECURE_NO_WARNINGS

using namespace glm;
using namespace std;

int main(void)
{
	//window setting;
	setwindow* sw = setwindow::instance(); 
	sw->setwindowsize(1024, 768);
	sw->Createwindow("report");
	sw->windowcolor(0.0f, 0.0f, 0.4f, 0.0f);
	sw->setdepth(GL_DEPTH_TEST, GL_LESS, GL_CULL_FACE);
	

	//프레임 고정시 필요한 설정
	Time* time = new Time;

	FileManager* fil = FileManager::instance();
	Renderer* render = Renderer::instance();
	ObjectUpdater* objupdater = ObjectUpdater::instance();

	objdata* cubeobj = new objdata();
	render->addObject(cubeobj);


	sphere* sphere1 = new sphere;
	render->addObject(sphere1);
	//spher를 제외한 다른 오브젝트 설정 불가.
	//sphere1->setsphere();

	//화면에 안보이는 컨트롤
	//컨트롤 대상,회피할 오브젝트
	gamecontroller* ann = new gamecontroller(sphere1, cubeobj, sw);
	
	//ann->getunit(sphere1, cubeobj, sw);
	//업데이트에 추가
	//render->addupdate(ann);
	
	do {
		//고정 프레임
		if (time->isRenderTiming())
		{
			objupdater->update();
			//화면에 보이진 않지만 실행 가능.
			//render->update();
		}

		//가변 프레임
		if (time->isvariableTiming())
		{
			render->render();
			sw->Swapbuffers();
		}
	} 
	while (sw->checkwindow());

	render->deletebuffer();

	//delete render;
	delete cubeobj;
	delete ann;
	delete time;
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}