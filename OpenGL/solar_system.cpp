#include "solar_system.h"
#define _USE_MATH_DEFINES
#include <math.h>

void solar_system::drawCircle(float red, float green, float blue) {
	float radius = 1.0f;
	const float angle = 2.0f * M_PI / segments;
	float oldX = 0.0f, oldY = 1.0f;

	for (int i = 0; i <= segments; i++) {
		float newX = cosf(angle * i) * radius;
		float newY = sinf(angle * i) * radius;

		glBegin(GL_TRIANGLES);
		glColor3f(red, green, blue);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(oldX, oldY, 0.0f);
		glVertex3f(newX, newY, 0.0f);
		glEnd();

		oldX = newX;
		oldY = newY;
	}
}

void solar_system::draw() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(0.2f, 0.2f, 1.f);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.1f, 0.1f, 0.1f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);

		drawCircle(1.0f, 0.75f, 0.0f);

		glPushMatrix();
		glRotatef(angle1, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, 3.0f, 0.0f);
		glScalef(0.3f, 0.3f, 1.0f);
		drawCircle(0.0f, 0.5f, 0.5f);

		angle1 += (360.0f / 365.0f) / 10.0f;

		glPushMatrix();
		glRotatef(angle2, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, 3.0f, 0.0f);
		glScalef(0.5f, 0.5f, 1.0f);
		drawCircle(0.5f, 0.5f, 0.5f);

		glPopMatrix();

		angle2 += (360.0f / 28.0f) / 10.0f;

		glPopMatrix();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

solar_system::solar_system(GLFWwindow* window) {
	this->window = window;
}
