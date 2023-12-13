
#include <iostream>
#include <GLFW\glfw3.h>
#define _USE_MATH_DEFINES
#include <math.h>

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

	float x = 0.0f, y = 0.0f, radius = 1.0f, steps = 300;

    while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		float prevX = x, prevY = y - radius;

		for (int i = 0; i <= steps; i++) {
			float newX = radius * sin((M_PI * 2.f / steps) * i);
			float newY = -radius * cos((M_PI * 2.f / steps) * i);

			glBegin(GL_TRIANGLES);
			glColor3f(0.f, 0.5f, 0.f);
			glVertex3f(0.f, 0.f, 0.f);
			glVertex3f(prevX, prevY, 0.f);
			glVertex3f(newX, newY, 0.f);
			glEnd();

			prevX = newX;
			prevY = newY;

		}


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}