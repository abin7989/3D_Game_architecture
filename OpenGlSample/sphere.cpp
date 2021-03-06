#include"sphere.h"

void sphere::setsphere()
{
	FileManager::instance()->gettarget(this);
	FileManager::instance()->loadObj(
		"textFile/sphere.obj",
		"textFile/�ؿռ�.DDS",
		"shader/20161364_vs.shader",
		"shader/20161364_fs.shader"
	);
	ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix = glm::lookAt(
		glm::vec3(70,0,0), // Camera is at (4,3,3), in World Space
		glm::vec3(0,0,0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	ModelMatrix = glm::mat4(1.0);

	glm::vec3 lightPos = glm::vec3(0, 0, 10);
	glm::vec3 lightPos2 = glm::vec3(0, 0, 10);
	glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(LightID2, lightPos2.x, lightPos2.y, lightPos2.z);	
	settrans(glm::vec3(0.0f, -10.0f, 0.0f));
	MVP = ProjectionMatrix * ViewMatrix * trans * ModelMatrix;

}
void  sphere::settrans(glm::vec3 t)
{
	trans = glm::translate(trans, Point(t.x, t.y, t.z));
	MVP = ProjectionMatrix * ViewMatrix * trans * ModelMatrix;
}
void sphere::deletebuffer()
{
	RenderableObject::deletebuffer();
}
void sphere::init()
{
	setsphere();
}
void sphere::up()
{
}