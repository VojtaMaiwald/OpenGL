#include "utils.h"

#define SAFE_DELETE_ARRAY( p ) { \
	if ( p != NULL ) \
	{ \
		delete [] p; \
		p = NULL; \
	} \
}

int LoadShader(const std::string& file_name, std::vector<char>& shader)
{
	FILE* file = fopen(file_name.c_str(), "rt");

	if (!file) {
		printf("IO error: File '%s' not found.\n", file_name.c_str());
		return S_FALSE;
	}

	int result = S_FALSE;
	const size_t file_size = static_cast<size_t>(GetFileSize64(file_name.c_str()));

	if (file_size < 1) {
		printf("Shader error: File '%s' is empty.\n", file_name.c_str());
	}
	else {
		shader.clear();
		shader.resize(file_size + 1);
		size_t bytes = 0; 

		do {
			bytes += fread(shader.data(), sizeof(char), file_size, file);
		} while (!feof(file) && (bytes < file_size));

		if (!feof(file) && (bytes != file_size)) {
			printf("IO error: Unexpected end of file '%s' encountered.\n", file_name.c_str());
		}
		else {
			printf("Shader file '%s' loaded successfully.\n", file_name.c_str());
			result = S_OK;
		}
	}

	fclose(file);
	file = nullptr;

	return result;
}

long long GetFileSize64(const char* file_name)
{
	FILE* file = fopen(file_name, "rb");

	if (file != NULL) {
		_fseeki64(file, 0, SEEK_END);
		long long file_size = _ftelli64(file);
		_fseeki64(file, 0, SEEK_SET);
		fclose(file);
		file = NULL;

		return file_size;
	}

	return 0;
}

GLint CheckShader(const GLenum shader)
{
	GLint status = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	printf("Shader compilation %s.\n", (status == GL_TRUE) ? "was successful" : "FAILED");

	if (status == GL_FALSE) {
		int info_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_length);
		char* info_log = new char[info_length];
		memset(info_log, 0, sizeof(*info_log) * info_length);
		glGetShaderInfoLog(shader, info_length, &info_length, info_log);

		printf("Error log: %s\n", info_log);

		SAFE_DELETE_ARRAY(info_log);
	}

	return status;
}

GLuint GetVertexShader(const std::string& file_name)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::vector<char> shader_source;
	if (LoadShader(file_name, shader_source) == S_OK)
	{
		const char* tmp = static_cast<const char*>(&shader_source[0]);
		glShaderSource(vertexShader, 1, &tmp, nullptr);
		glCompileShader(vertexShader);
	}
	CheckShader(vertexShader);

	return vertexShader;
}

GLuint GetFragmentShader(const std::string& file_name)
{
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::vector<char> shader_source;
	if (LoadShader(file_name, shader_source) == S_OK)
	{
		const char* tmp = static_cast<const char*>(&shader_source[0]);
		glShaderSource(fragmentShader, 1, &tmp, nullptr);
		glCompileShader(fragmentShader);
	}
	CheckShader(fragmentShader);

	return fragmentShader;
}