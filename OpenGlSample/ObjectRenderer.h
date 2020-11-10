#pragma once
#include "IRenderer.h"
#include "setwindow.h"
#include <vector>
class ObjectRenderer
{
public:
	static ObjectRenderer* instance()
	{
		static ObjectRenderer render;
		return &render;
	}
private:
	std::vector<IRenderer*> RenderList;
public:
	void addObject(IRenderer* render_obj)
	{
		RenderList.push_back(render_obj);
	}
	void render()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (int i = 0; i < RenderList.size(); i++)
		{
			RenderList[i]->render();
		}
		setwindow::instance()->Swapbuffers();
	}
};