#pragma once
#include <iostream>

#include <stdio.h>
#include "Object.h"
#include "IRenderer.h"


class RenderableObject : public Object,public IRenderer
{
public:

	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint ModelMatrixID2;
	GLuint LightID;
	GLuint LightID2;
	GLuint Texture;
	GLuint TextureID;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	RenderableObject();

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;

	glm::mat4 MVP;
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ModelMatrix;
	glm::mat4 Rot;
	glm::mat4 trans;

	const GLfloat* addressViewMatrix() { return &ViewMatrix[0][0]; };
	const GLfloat* addressMVPa() { return &MVP[0][0]; };
	const GLfloat* addressModelMatrix() { return &ModelMatrix[0][0]; };

	////정점정보 delete
	virtual void deletebuffer() override;
	virtual RenderableObject* render() override { return this; };
};