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
#include "sphere.h"
#include "objdata.h"
#include "gamecontroller.h"
#include "Time.h"
#include "ObjectUpdater.h"
#include "ObjectRenderer.h"
#include "ObjectDelete.h"
#include "ObjectInit.h"
#include "testnonrender.h"
#include "CompositeObj.h"
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
	
	
	//프레임 설정
	Time* time = new Time;

	Renderer* render = Renderer::instance();
	FileManager* file = FileManager::instance();
	ObjectUpdater* objupdater = ObjectUpdater::instance();
	ObjectDelete* objdelete = ObjectDelete::instance();
	ObjectInit* objinit = ObjectInit::instance();
	ObjectRenderer* objrender = ObjectRenderer::instance();
	CompositeObj* comp = new CompositeObj();
	//큐브 생성
	objdata* cubeobj = new objdata();
	objdata* cubeobj2 = new objdata();
	objdata* cubeobj3 = new objdata();
	cubeobj2->Point(0, -10, 0);
	cubeobj3->Point(0, -10, 0);
	//스피어 생성
	sphere* sphere1 = new sphere;
	comp->add(cubeobj);
	comp->add(cubeobj2);
	comp->add(cubeobj3);
	//화면에 안보이는 컨트롤
	//컨트롤 대상,회피할 오브젝트
	gamecontroller* ann = new gamecontroller(sphere1, cubeobj, sw);
	testnonrender* test = new testnonrender;
	objinit->init();
	do {
		//고정 프레임
		if (time->isRenderTiming())
		{

			comp->settransform(0);
			//화면에 보이진 않지만 실행 가능.
			objupdater->update();
		}

		//가변 프레임
		if (time->isvariableTiming())
		{
			objrender->render();
			sw->Swapbuffers();
		}
	} 
	while (sw->checkwindow());

	objdelete->deleter();
	delete cubeobj;
	delete ann;
	delete time;
	delete test;
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}