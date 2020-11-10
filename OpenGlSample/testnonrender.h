#pragma once

#include "NonRenderableObject.h"
#include "RenderableObject.h"
class testnonrender:public RenderableObject
{
	int i = 0;
	int j = 0;
	virtual void init() override { printf("init\n"); }
	virtual void up() override { 
		i++;
		if (i >= 60)
		{
			printf("update\n");
			i = 0;
		}
	}
	virtual void render() override {
		j++;
		if (j >=60)
		{
			printf("render\n");

			j = 0;
		}
	}
};