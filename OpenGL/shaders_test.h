
#include <GL/glew.h>
#include <glfw3.h>

class shaders_test
{
	public:
		shaders_test(GLFWwindow* window);
		void draw();

	private:
		GLFWwindow* window;
		GLfloat vertices[18] = {
			-1.0f, -1.0f, 0.0f,
			 1.0f, -1.0f, 0.0f,
			 1.0f,  1.0f, 0.0f,
			 1.0f,  1.0f, 0.0f,
			-1.0f,  1.0f, 0.0f,
			-1.0f, -1.0f, 0.0f,
		};
		GLfloat colors[18] = {
			0.0f, 0.0f, 1.0f,
			0.0f, 1.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 0.0f
		};
		GLfloat uvs[12] = {
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 0.0f,
			1.0f, 0.0f,
			0.0f, 1.0f,
			0.0f, 0.0f
		};
};

