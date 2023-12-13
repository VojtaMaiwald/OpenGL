
#include <iostream>
#include <GLFW\glfw3.h>

int main()
{
    GLFWwindow* window;

    if (!glfwInit()) {
        std::cout << "Error";
        exit(-1);
    }

    window = glfwCreateWindow(640, 480, "OpenGL", NULL, NULL);

    if (!window) {
		std::cout << "Error";
		glfwTerminate();
		exit(-1);
	}

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}