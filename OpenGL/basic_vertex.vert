#version 460 core

in vec3 inColor;
in vec3 inPosition;
uniform mat4 matrix;
out vec4 outColor;

void main()
{
	outColor = vec4(inColor, 1.0f);
	gl_Position = vec4(inPosition, 1.0f) * matrix;
}