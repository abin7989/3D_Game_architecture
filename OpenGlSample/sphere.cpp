#include"sphere.h"

void sphere::setsphere()
{
	FM->gettarget(RB);
	FM->loadObj(
		"sphere.obj",
		"uvtemplate.DDS",
		"20161364_vs.shader",
		"20161364_fs.shader"
	);
	RB->ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	RB->ViewMatrix = glm::lookAt(
		glm::vec3(10, 6, 6), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	RB->ModelMatrix = glm::mat4(1.0);

	glm::vec3 lightPos = glm::vec3(0, 0, 10);
	glm::vec3 lightPos2 = glm::vec3(0, 0, 10);
	glUniform3f(RB->LightID, lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(RB->LightID2, lightPos2.x, lightPos2.y, lightPos2.z);
	RB->trans = glm::translate(RB->trans, glm::vec3(-5.0f, 0.0f, 0.0f));
	RB->MVP = RB->ProjectionMatrix * RB->ViewMatrix * RB->trans * RB->ModelMatrix;

}

void sphere::deletebuffer()
{
	RB->deletebuffer();
}