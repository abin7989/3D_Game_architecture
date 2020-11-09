#include"objdata.h"


void objdata::setMVP(glm::vec3 world_view)
{
	ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix = glm::lookAt(
		world_view, // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	ModelMatrix = glm::mat4(1.0);
}
void objdata::setCubeRot(float rot_angle, glm::vec3 rot)
{
	Rot = glm::rotate(Rot, glm::radians(rot_angle), rot);
	MVP = ProjectionMatrix * ViewMatrix *trans * Rot * ModelMatrix;
}

void objdata::setLight(glm::vec3 lightPos)
{
	glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
}
void objdata::setLight2(glm::vec3 lightPos)
{
	glUniform3f(LightID2, lightPos.x, lightPos.y, lightPos.z);
}

void objdata::settrans(float speed, glm::vec3 t)
{
	arrive += speed;
	z_point += t.z;
	trans = glm::translate(trans, t);
	MVP = ProjectionMatrix *ViewMatrix *trans * Rot *ModelMatrix;
}
void objdata::deletebuffer()
{
	RenderableObject::deletebuffer();
}

void objdata::init()
{
	FileManager::instance()->gettarget(this);
	FileManager::instance()->loadObj(
		"cube.obj",
		"uvtemplate.DDS",
		"20161364_vs.shader",
		"20161364_fs.shader"
	);
	setMVP(glm::vec3(25, 0, 0));
	setLight(glm::vec3(0, 0, 10));
	setLight2(glm::vec3(0, 0, 10));
	float speed = -0.1f;
	settrans(speed, glm::vec3(0.0f, 10.0f, 0.0f));
}