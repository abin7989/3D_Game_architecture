#include "Renderer.h"
void Renderer::render(RenderableObject* RB)
{

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, RB->Texture);
	glUniform1i(RB->TextureID, 0);
	RB->MVP = RB->ProjectionMatrix * RB->ViewMatrix * RB->trans * RB->Rot * RB->PreviousRot * RB->Previoustrans * RB->ModelMatrix;

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