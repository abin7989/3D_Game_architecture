#pragma once

#include "IU.h"
#include <vector>
class ObjectUpdater
{
public:
	static ObjectUpdater* instance()
	{
		static ObjectUpdater updater;
		return &updater;
	 }
private:
	std::vector<IU*> NonRenderList;
public :
	void addObject(IU* target_obj)
	{
		NonRenderList.push_back(target_obj);
	}
	void update()
	{
		for (int i = 0; i < NonRenderList.size(); i++)
		{
			NonRenderList[i]->up();
		}
	}
};