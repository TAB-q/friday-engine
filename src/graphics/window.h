#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

class window
{
private:
	GLFWwindow* mainWindow;
public:
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const char* WINDOW_TITLE = "Title";
	window(const char* title, const int width, const int height);
	void loop();
	~window();
};

