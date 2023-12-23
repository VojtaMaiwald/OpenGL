#include "shaders_test.h"

shaders_test::shaders_test(GLFWwindow* window) {
	this->window = window;
}

void shaders_test::draw() {
	if (glewInit() != GLEW_OK) {
		// Handle initialization failure
	}

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.1f, 0.1f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}