#pragma once

#include "ICleanUp.h"
#include <vector>
class ObjectDelete
{
public:
	static ObjectDelete* instance()
	{
		static ObjectDelete deleter;
		return &deleter;
	}
private:
	std::vector<ICleanUp*> RenderList;
public:
	void addObject(ICleanUp* target_obj)
	{
		RenderList.push_back(target_obj);
	}

	void deleter()
	{
		for (int i = 0; i < RenderList.size(); i++)
		{
			RenderList[i]->deletebuffer();
		}
	}
};