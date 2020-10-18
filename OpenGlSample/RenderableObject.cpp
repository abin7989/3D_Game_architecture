
#include "RenderableObject.h"

RenderableObject::RenderableObject()
{
	Rot = glm::mat4(1.0f);
	trans = glm::mat4(1.0f);
}
void RenderableObject::deletebuffer()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
}