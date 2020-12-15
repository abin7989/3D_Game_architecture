#pragma once
#include <vector>
#include "interface/IInit.h"
class ObjectInit
{
public:
	static ObjectInit* instance()
	{
		static ObjectInit init;
		return &init;
	}
private:
	std::vector<IInit*> RenderList;
public:
	void addObject(IInit* render_obj)
	{
		RenderList.push_back(render_obj);
	}
	void init()
	{
		for (int i = 0; i < RenderList.size(); i++)
		{
			RenderList[i]->init();
		}
	}
};