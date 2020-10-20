#pragma once
#include "Object.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "ICleanUp.h"
#include "IRenderer.h"
#include "IUpdater.h"
#include <vector>

class Renderer :public ICleanUp
{
private:
	std::vector<RenderableObject*> RenderList;
	std::vector<int> NonRenderList;
public:
	void render();
	void addObject(IRenderer* render_obj);
	void update();
	void addupdate(IUpdater* nonrender_obj);
	virtual void deletebuffer() override;

};