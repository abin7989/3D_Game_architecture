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
	

	//������ ������ �ʿ��� ����
	Time* time = new Time;

	FileManager* fil = FileManager::instance();
	Renderer* render = Renderer::instance();
	ObjectUpdater* objupdater = ObjectUpdater::instance();

	objdata* cubeobj = new objdata();
	render->addObject(cubeobj);


	sphere* sphere1 = new sphere;
	render->addObject(sphere1);
	//spher�� ������ �ٸ� ������Ʈ ���� �Ұ�.
	//sphere1->setsphere();

	//ȭ�鿡 �Ⱥ��̴� ��Ʈ��
	//��Ʈ�� ���,ȸ���� ������Ʈ
	gamecontroller* ann = new gamecontroller(sphere1, cubeobj, sw);
	
	//ann->getunit(sphere1, cubeobj, sw);
	//������Ʈ�� �߰�
	//render->addupdate(ann);
	
	do {
		//���� ������
		if (time->isRenderTiming())
		{
			objupdater->update();
			//ȭ�鿡 ������ ������ ���� ����.
			//render->update();
		}

		//���� ������
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