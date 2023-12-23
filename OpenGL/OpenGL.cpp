

//#include "solar_system.h"
#include "shaders_test.h"
#include <iostream>

int main()
{
	GLFWwindow* window;

	if (!glfwInit()) {
		std::cout << "Error";
		exit(-1);
	}

	window = glfwCreateWindow(640, 640, "OpenGL", NULL, NULL);

	if (!window) {
		std::cout << "Error";
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(window);

	//solar_system solar_system(window);
	//solar_system.draw();

	shaders_test shaders_test(window);
	shaders_test.draw();

	glfwTerminate();
	return 0;
}