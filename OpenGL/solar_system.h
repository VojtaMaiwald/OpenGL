#pragma once
#include <glfw3.h>

class solar_system
{
	public:
		solar_system(GLFWwindow* window);
		void draw();

	private:
		GLFWwindow* window;
		void drawCircle(float red, float green, float blue);

		const int segments = 100;

		float angle1 = 0.0f;
		float angle2 = 0.0f;
};

