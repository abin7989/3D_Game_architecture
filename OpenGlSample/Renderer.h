#pragma once
#include "Object.h"
#include "RenderableObject.h"
#include "gamecontroller.h"
#include "ICleanUp.h"
#include "IRenderer.h"
#include <vector>

class Renderer :public ICleanUp
{
private:
	std::vector<RenderableObject*> RenderList;
	std::vector<IU*> NonRenderList;
public:
	void render();
	void addObject(IRenderer* render_obj);
	void update();
	void addupdate(IU* nonrender_obj);
	virtual void deletebuffer() override;

};