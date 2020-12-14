#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "RenderableObject.h"

class CompositeObj : public RenderableObject
{
public:
	CompositeObj()
	{
		table_ = new std::vector<RenderableObject*>();
	}

	~CompositeObj()
	{
		for (
			std::vector<RenderableObject*>::const_iterator it = table_->begin();
			it != table_->end();
			++it
			)
		{
			delete (*it);
		}

		table_->clear();

		delete table_;
	}

	void add(RenderableObject* obj)
	{
		table_->push_back(obj);
	}
	void settransform(int a)
	{
		//for (
		//	std::vector<RenderableObject*>::const_iterator is = table_->begin();
		//	is != table_->end();
		//	++is
		//	)
		//{
		//		for (
		//			std::vector<RenderableObject*>::const_iterator it = table_->begin() + 1;
		//			it != table_->end();
		//			++it
		//			)
		//		{
		//			(*it)->trans = glm::translate((*is)->trans, glm::vec3(0, (*it)->pointy, 1));
		//		}
		//}
		std::vector<RenderableObject*>::const_iterator is= table_->begin()+a;

		for (
			std::vector<RenderableObject*>::const_iterator it = table_->begin()+a+1;
			it != table_->end();
			++it
			)
		{
			(*it)->trans = glm::translate((*is)->trans, glm::vec3(0, (*it)->pointy, 1));
			settransform(a + 1);
		}
	}

private:
	std::vector<RenderableObject*>* table_;
	glm::mat4 transform;
};