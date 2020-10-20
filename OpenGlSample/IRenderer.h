#pragma once

class IRenderer
{
public:
	virtual RenderableObject* render() = 0;
};