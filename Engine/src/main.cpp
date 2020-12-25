#include <iostream>
#include <GLFW/glfw3.h>
#include "GLFW/GLFW.h"
#include "GLFW/Window.h"

int main()
{
	try {
		GLFW glfw;
		Window w("Engine", 1280, 720);
		w.loop();
	}
	catch (std::runtime_error e) {
		std::cout << "EXCXEPTION: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
