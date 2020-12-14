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

	void settransform()
	{
		for (
			std::vector<RenderableObject*>::const_iterator it = table_->begin();
			it != table_->end();
			++it
			)
		{
			transform->push_back((*it)->trans);

		}
	}

private:
	std::vector<RenderableObject*>* table_;
	std::vector<glm::mat4>* transform;
};