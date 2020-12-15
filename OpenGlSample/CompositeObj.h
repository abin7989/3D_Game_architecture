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
		//dfs±×·¡ÇÁ 
		std::vector<RenderableObject*>::const_iterator is= table_->begin()+a;

		for (
			std::vector<RenderableObject*>::const_iterator it = table_->begin()+a+1;
			it != table_->end();
			++it
			)
		{
			(*it)->Rot = glm::rotate((*it)->Rot, glm::radians(rot_angle), glm::vec3(1.0f, 1.0f,1.0f));
			(*it)->PreviousRot = glm::rotate((*it)->PreviousRot, glm::radians(rot_angle), glm::vec3(0.0f, 0.0f, 1.0f));
			
			(*it)->trans = glm::translate((*is)->trans, glm::vec3((*it)->pointx, (*it)->pointy, (*it)->pointz));
			(*it)->Previoustrans = glm::mat4(1.0f);
			settransform(a + 1);
		}
	}
	virtual void up() override { settransform(0); };
private:
	std::vector<RenderableObject*>* table_;
	glm::mat4 transform;
	float rot_angle = 1.0f;
};