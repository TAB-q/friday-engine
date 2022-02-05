#include "window.h"
#include "VAO.h"

window::window(const char* title, const int width, const int height)
{
	mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(mainWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Cannot init GLAD");
	}

	glViewport(0, 0, width, height);
}

void window::loop()
{

	GL::VAO vao;
	vao.addVBO({
		0, 1, 0,
	   -1, -1, 0,
		1, -1, 0
	});

	while (!glfwWindowShouldClose(mainWindow)) {
		glClearColor(0.0f, 0.7f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		vao.draw(3);
		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}
}


window::~window()
{
	glfwDestroyWindow(mainWindow);
}
