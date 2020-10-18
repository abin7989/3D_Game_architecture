#pragma once
#include <vector>
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ICleanUp.h"

class FileManager :public ICleanUp
{
private:
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

public:

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	inline GLuint getVertexArrayID() const { return VertexArrayID; };
	inline GLuint getMatrixID() const { return MatrixID; };
	inline GLuint getViewMatrixID() const { return ViewMatrixID; };
	inline GLuint getModelMatrixID() const { return ModelMatrixID; };
	inline GLuint getLightID() const { return LightID; };
	inline GLuint getLightID2() const { return LightID2; };
	inline GLuint getTexture() const { return Texture; };
	inline GLuint getTextureID() const { return TextureID; };
	inline std::vector<glm::vec3> getvertices() const { return vertices; };
	inline std::vector<glm::vec2> getuvs() const { return uvs; };
	inline std::vector<glm::vec3> getnormals() const { return normals; };

	void setVertexArray();
	//쉐이더 로드, MVP생성
	void setprogramID(const char* a, const char* b);
	//obj로드
	void setobj(const char* a);
	//텍스트 로드
	void setTexture(const char* a);
	//정점정보, 텍스트, 쉐이더 delete
	virtual void deletebuffer() override;
};