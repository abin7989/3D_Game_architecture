#include"objdata.h"

void objdata::buildvertices(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
{
	glGenBuffers(1, &RB->vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, RB->vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &RB->uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, RB->uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &RB->normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, RB->normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
}
void objdata::deletebuffer()
{
	glDeleteBuffers(1, &RB->vertexbuffer);
	glDeleteBuffers(1, &RB->uvbuffer);
	glDeleteBuffers(1, &RB->normalbuffer);
}
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
}
void objdata::settrans(glm::vec3 t)
{
	RB->trans = glm::translate(RB->trans, t);
}
void objdata::getMVP()
{
	RB->MVP = RB->ProjectionMatrix * RB->ViewMatrix * RB->trans * RB->Rot * RB->ModelMatrix;
}
void objdata::setLight(GLuint LightID, glm::vec3 lightPos)
{
	glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
}