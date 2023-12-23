#version 460 core

in vec4 inColor;
in vec4 inPosition;
uniform mat4 matrix;
out vec4 outColor;

void main()
{
	outColor = inColor;
	gl_Position = inPosition * matrix;
}