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
	//MVP 쉐이더에서 사용
	void MVPuniform(GLuint MatrixID, GLuint ModelMatrixID, GLuint ViewMatrixID);
	//화면에 그리기
	void render(std::vector<glm::vec3> vertices);

	virtual void deletebuffer() override;
	
};