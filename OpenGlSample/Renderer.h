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
	//ȭ�鿡 �׸���
	void render();
	void addObject(RenderableObject* render_obj);
	virtual void deletebuffer() override;
	
};