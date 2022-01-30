#include <iostream>
#include <GLFW/glfw3.h>
#include "graphics/glfw.h"
#include "graphics/window.h"

int main()
{
	try {
		const char* WINDOW_TITLE = "Title";
		const int WINDOW_WIDTH = 800;
		const int WINDOW_HEIGHT = 600;

		std::cout << "Hello World!\n";

		glfw glfw;
		window win(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
		win.loop();
	}
	catch(std::runtime_error e) {
		std::cout << "FATAL ERROR:" << e.what() << std::endl;
		return -1;
	}
	return 0;
}

