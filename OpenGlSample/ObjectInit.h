//#pragma once
//#include <vector>
//#include "IRenderer.h"
//#include "RenderableObject.h"
//class ObjectInit
//{
//public:
//	static ObjectInit* instance()
//	{
//		static ObjectInit init;
//		return &init;
//	}
//private:
//	std::vector<RenderableObject*> RenderList;
//public:
//	void addObject(IRenderer* render_obj)
//	{
//		RenderList.push_back(render_obj->render());
//	}
//	void update()
//	{
//		for (int i = 0; i < RenderList.size(); i++)
//		{
//			RenderList[i]->init();
//		}
//	}
//};