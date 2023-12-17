#include <iostream>
#include <GLFW\glfw3.h>
#include "solar_system.h"

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

	solar_system solar_system(window);
	solar_system.draw();

	glfwTerminate();
	return 0;
}