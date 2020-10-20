#include"objdata.h"


void objdata::setMVP(glm::vec3 world_view)
{
	RB->ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	RB->ViewMatrix = glm::lookAt(
		world_view, // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	RB->ModelMatrix = glm::mat4(1.0);
}
void objdata::setCubeRot(float rot_angle, glm::vec3 rot)
{
	RB->Rot = glm::rotate(RB->Rot, glm::radians(rot_angle), rot);
	RB->MVP = RB->ProjectionMatrix * RB->ViewMatrix * RB->trans * RB->Rot * RB->ModelMatrix;
}
void objdata::settrans(glm::vec3 t)
{
	RB->trans = glm::translate(RB->trans, t);
}
void objdata::setLight(glm::vec3 lightPos)
{
	glUniform3f(RB->LightID, lightPos.x, lightPos.y, lightPos.z);
}
void objdata::setLight2(glm::vec3 lightPos)
{
	glUniform3f(RB->LightID2, lightPos.x, lightPos.y, lightPos.z);
}
void objdata::deletebuffer()
{
	RB->deletebuffer();
}