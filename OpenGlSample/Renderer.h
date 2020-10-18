#pragma once
#include "Object.h"
#include "RenderableObject.h"
class Renderer:public RenderableObject
{
private:
	RenderableObject* RB;
public:
	Renderer(RenderableObject* a) { RB = a; };
	void clearNtext(GLuint Texture, GLuint TextureID);
	//MVP ���̴����� ���
	void MVPuniform(GLuint MatrixID, GLuint ModelMatrixID, GLuint ViewMatrixID);
	//ȭ�鿡 �׸���
	void render(std::vector<glm::vec3> vertices);

	virtual void deletebuffer() override;
	
};