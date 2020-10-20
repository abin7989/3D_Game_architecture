#pragma once
#include "Object.h"
#include "RenderableObject.h"
#include "ICleanUp.h"
#include "IRenderer.h"
#include "IUpdater.h"
#include <vector>
class IUpdater;
class Renderer :public ICleanUp
{
private:
	std::vector<RenderableObject*> RenderList;
public:
	void render();
	void addObject(IRenderer* render_obj);
	void update(IUpdater* nonrender_obj);
	virtual void deletebuffer() override;

};