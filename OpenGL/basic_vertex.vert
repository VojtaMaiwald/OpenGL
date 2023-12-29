#version 460 core

in vec3 inColor;
in vec3 inPosition;
in vec2 inUV;

uniform mat4 matrix;

out vec4 outColor;
out vec2 outUV;

void main()
{
	outColor = vec4(inColor, 1.0f);
	gl_Position = vec4(inPosition, 1.0f) * matrix;
	outUV = inUV * mat2(4f, 0.0f, 0.0f, 0.0f);
}