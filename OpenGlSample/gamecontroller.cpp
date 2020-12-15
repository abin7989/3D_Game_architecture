
#include "gamecontroller.h"
#include <cmath>
#include <iostream>
void gamecontroller::gameControll() {
	if (glfwGetKey(setwindow::instance()->getwindow(), GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		gamestart = true;
	}
	if (gamestart)
	{
		if (glfwGetKey(sw->getwindow(), GLFW_KEY_A) == GLFW_PRESS)
		{
			sp->settrans(glm::vec3(0.0f, 0.0f, -speed));
		}
		if (glfwGetKey(sw->getwindow(), GLFW_KEY_D) == GLFW_PRESS)
		{
			sp->settrans(glm::vec3(0.0f, 0.0f, speed));
		}
		if (glfwGetKey(sw->getwindow(), GLFW_KEY_W) == GLFW_PRESS)
		{
			sp->settrans(glm::vec3(0.0f, -speed, 0.0f));
		}
		if (glfwGetKey(sw->getwindow(), GLFW_KEY_S) == GLFW_PRESS)
		{
			sp->settrans(glm::vec3(0.0f, speed,0.0f));
		}
		if (
			ob->pointz >sp->pointz - 2&&
			ob->pointz < sp->pointz + 2
			)
		{
			if (			
				ob->pointy <sp->pointy +2 &&
				ob->pointy>sp->pointy -2
				)
			{
				float a = ob->pointz;
				if (
					sp->pointz + 1.0f > ob->pointz &&
					sp->pointz - 1.0f < ob->pointz
					)
				{
					ran = rand() % 50;
					ran = ran - 10 - ob->pointz;
					printf("%f", ran);
					ob->settrans(speed, glm::vec3(0.0f, 40.0f, ran));
					speed += -0.02f;
				}
			}
		}
		if (ob->pointy < -30.0f)
		{
			glfwSetWindowShouldClose(sw->getwindow(), true);
		}
		ob->settrans(speed, glm::vec3(0.0f, speed, 0.0f));
		ob->setCubeRot(0.5f, glm::vec3(0.0f, 1.0f, 0.0f));
	}
}

void gamecontroller::getunit(sphere* a, objdata* b, setwindow* c)
{ 
	sp = a;
	ob = b; 
	sw = c; 
}