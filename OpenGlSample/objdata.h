#pragma once

#include "CompositeObj.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class objdata :public CompositeObj
{

public:

	int Distinction;

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
	virtual void init() override;
	virtual void deletebuffer() override;
	virtual void up() override ;
	virtual void render() override { Renderer::instance()->render(this); };
};