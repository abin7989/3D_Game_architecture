#pragma once
#include "Object.h"
#include "RenderableObject.h"
class Renderer:public RenderableObject
{
private:
	RenderableObject* RB;
public:
	Renderer(RenderableObject* a) { RB = a; };
	//화면에 그리기
	void render();
	void clear();
	virtual void deletebuffer() override;
	
};