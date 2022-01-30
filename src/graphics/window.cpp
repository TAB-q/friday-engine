#include "window.h"


window::window(const char* title, const int width, const int height)
{
	mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(mainWindow);
}

void window::loop()
{
	while (!glfwWindowShouldClose(mainWindow)) {
		glClearColor(0.0f, 0.7f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}
}


window::~window()
{
	glfwDestroyWindow(mainWindow);
}
