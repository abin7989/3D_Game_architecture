#include "setwindow.h"

setwindow::setwindow(int a, int b)
{
	width = a;
	length = b;
}
void setwindow::Createwindow(const char* windowname)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, length, windowname, NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}
}
void setwindow::windowcolor(float a, float b, float c, float d)
{
	glClearColor(a, b, c, d);
}
void setwindow::setmiddlemouse()
{
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwPollEvents();
	glfwSetCursorPos(window, width / 2, length / 2);
}
void setwindow::setdepth(GLenum cap, GLenum func, GLenum endc)
{
	glEnable(cap);
	glDepthFunc(func);
	glEnable(endc);
}
void setwindow::Swapbuffers()
{
	// Swap buffers
	glfwSwapBuffers(this->window);
	glfwPollEvents();
}

bool setwindow::checkwindow()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0)
	{
		return true;
	}
	return false;
}