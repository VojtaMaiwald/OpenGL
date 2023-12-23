#pragma once

#include <string>
#include <vector>
#include <winerror.h>
#include <GL/glew.h>
#include <glfw3.h>

int LoadShader(const std::string& file_name, std::vector<char>& shader);
long long GetFileSize64(const char* file_name);
GLint CheckShader(const GLenum shader);
GLuint GetVertexShader(const std::string& file_name);
GLuint GetFragmentShader(const std::string& file_name);