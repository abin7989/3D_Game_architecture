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

	//정점 정보 obj통해 받기.

	//월드좌표, 카메라 좌표, 로컬 좌표 생성. world_view를 통한 카메라 위치 조정
	void setMVP(glm::vec3 world_view);
	//큐브 회전
	void setCubeRot(float rot_angle, glm::vec3 rot);
	//큐브 위치	
	void settrans(float speed ,glm::vec3 t);
	//월드 * 카메라 * 위치 * 회전 * 로컬
	//빛 사용
	void setLight(glm::vec3 lightPos);
	void setLight2(glm::vec3 lightPos);
	virtual void deletebuffer() override;
	virtual RenderableObject* render() override { return this; };
};