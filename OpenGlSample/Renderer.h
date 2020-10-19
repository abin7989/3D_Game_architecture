#pragma once
#include "Object.h"
#include "RenderableObject.h"
#include <vector>
class Renderer:public RenderableObject
{
private:
	//RenderableObject* RBO;
	std::vector<RenderableObject*> RenderList;
public:
	//Renderer(RenderableObject* a) { RBO = a; };
	//화면에 그리기
	void render();
	void addObject(RenderableObject* render_obj);
	virtual void deletebuffer() override;
	
};