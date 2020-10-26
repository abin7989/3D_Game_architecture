#pragma once

#include"RenderableObject.h"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class objdata :public RenderableObject
{
private:
	RenderableObject* RB;

public:
	int Distinction;
	objdata(RenderableObject* a)
	{
		RB = a;
	}

	float arrive= 20;
	float z_point = 0;

	//���� ���� obj���� �ޱ�.

	//������ǥ, ī�޶� ��ǥ, ���� ��ǥ ����. world_view�� ���� ī�޶� ��ġ ����
	void setMVP(glm::vec3 world_view);
	//ť�� ȸ��
	void setCubeRot(float rot_angle, glm::vec3 rot);
	//ť�� ��ġ	
	void settrans(float speed ,glm::vec3 t);
	//���� * ī�޶� * ��ġ * ȸ�� * ����
	//�� ���
	void setLight(glm::vec3 lightPos);
	void setLight2(glm::vec3 lightPos);
	virtual void deletebuffer() override;
	virtual RenderableObject* render() override { return this; };
};