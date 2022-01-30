#include "glfw.h"

glfw::glfw()
{
	if (!glfwInit()) {
		throw std::runtime_error("Cannot init GLFW");
	}
}


glfw::~glfw()
{
	glfwTerminate();
}
