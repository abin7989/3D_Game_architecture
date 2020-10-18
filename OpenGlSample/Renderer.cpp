#include "Renderer.h"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")
void Renderer::render(std::vector<glm::vec3> vertices)
{
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, RB->vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);


	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, RB->uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, RB->normalbuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);


	glDrawArrays(GL_TRIANGLES, 0, vertices.size());


	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);


}
void Renderer::MVPuniform(GLuint MatrixID, GLuint ModelMatrixID, GLuint ViewMatrixID)
{
	
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE,RB->addressMVPa());
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, RB->addressModelMatrix());
	glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, RB->addressViewMatrix());
}
void Renderer::clearNtext(GLuint Texture, GLuint TextureID)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,Texture);
	glUniform1i(TextureID, 0);
}
void Renderer::deletebuffer()
{
	
	glDeleteBuffers(1, &RB->vertexbuffer);
	glDeleteBuffers(1, &RB->uvbuffer);
	glDeleteBuffers(1, &RB->normalbuffer);
}
