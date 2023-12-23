#include "shaders_test.h"
#include <iostream>
#include <vector>
#include "macros.h"
#include "utils.h"

shaders_test::shaders_test(GLFWwindow* window) {
	this->window = window;
}

void shaders_test::draw() {
	if (glewInit() != GLEW_OK) {
		std::cout << "glewInit Error";
		return;
	}

	GLuint vertexShader = GetVertexShader(BASIC_VERTEX);
	GLuint fragmentShader = GetFragmentShader(BASIC_FRAGMENT);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	GLint attribPosition = glGetAttribLocation(shaderProgram, "inPosition");
	glEnableVertexAttribArray(attribPosition);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

	GLint attribColor = glGetAttribLocation(shaderProgram, "inColor");
	glEnableVertexAttribArray(attribColor);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glVertexAttribPointer(attribColor, 3, GL_FLOAT, GL_FALSE, 0, 0);

	GLuint attributeMatrix = glGetUniformLocation(shaderProgram, "matrix");

	float alpha = 0.f;

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.1f, 0.1f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		float s = 0.5f * sinf(alpha);
		float c = 0.5f * cosf(alpha);

		alpha += 0.01f;

		const GLfloat matrix[] = {
			c,   -s,   0.f, 0.f,
			s,    c,   0.f, 0.f,
			0.f,  0.f, 1.f, 0.f,
			0.f,  0.f, 0.f, 1.f
		};

		glUniformMatrix4fv(attributeMatrix, 1, GL_FALSE, matrix);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}