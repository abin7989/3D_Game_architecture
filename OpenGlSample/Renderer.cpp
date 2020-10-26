#include "Renderer.h"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")
void Renderer::render()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, Texture);
	//glUniform1i(TextureID, 0);
	for (int i = 0; i < RenderList.size();i++)
	{
		RenderableObject* RB = RenderList.at(i);
		glUniformMatrix4fv(RB->MatrixID, 1, GL_FALSE, RB->addressMVPa());
		glUniformMatrix4fv(RB->ModelMatrixID, 1, GL_FALSE, RB->addressModelMatrix());
		glUniformMatrix4fv(RB->ViewMatrixID, 1, GL_FALSE, RB->addressViewMatrix());

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


		glDrawArrays(GL_TRIANGLES, 0, RB->vertices.size());


		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
	}

}

void Renderer::addObject(IRenderer* render_obj)
{
	RenderList.push_back(render_obj->render());
}

void Renderer::deletebuffer()
{


	for (int i = 0; i < RenderList.size(); i++)
	{
		RenderableObject* RB = RenderList.at(i);
		RB->deletebuffer();
	}
}

void Renderer::update()
{
	for (int i = 0; i < NonRenderList.size(); i++)
	{
		NonRenderList[i]->up();
	}
}
void Renderer::addupdate(IU* nonrender_obj)
{
	NonRenderList.push_back(nonrender_obj);

}

