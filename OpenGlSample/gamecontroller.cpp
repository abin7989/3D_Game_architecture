#include "gamecontroller.h"

void gamecontroller::gameControll() {
	if (glfwGetKey(sw->getwindow(), GLFW_KEY_ENTER) == GLFW_PRESS)
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
		if (ob->arrive < 2)
		{
			float a = ob->z_point;
			if (
				a - 2.0f < sp->z_point &&
				a + 2.0f > sp->z_point
				)
			{
				ran = rand() % 21;
				ran = ran - 10 - ob->z_point;
				ob->settrans(speed, glm::vec3(0.0f, 22.0f - ob->arrive, ran));
				ob->arrive = 22;
				speed += -0.02f;
			}

		}
		if (ob->arrive < -2.0)
		{
			glfwSetWindowShouldClose(sw->getwindow(), true);

		}
		ob->settrans(speed, glm::vec3(0.0f, speed, 0.0f));
		ob->setCubeRot(0.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
}

void gamecontroller::getunit(sphere* a, objdata* b, setwindow* c)
{ 
	sp = a;
	ob = b; 
	sw = c; 
}