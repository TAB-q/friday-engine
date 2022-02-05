#include "ShaderSystem.h"

GL::ShaderSystem::ShaderSystem(const std::string& name)
{
	mProgram = glCreateProgram();
	mVertex = loadShader("res/" + name + ".vert", GL_VERTEX_SHADER);
	mFragment = loadShader("res/" + name + ".frag", GL_FRAGMENT_SHADER);
	// TODO: возможно ошибка считывания шейдеров здесь (в путях файлов)
}

GLuint GL::ShaderSystem::loadShader(const std::string& path, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	std::ifstream fis(path);
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };

	const char* c = shaderCode.c_str();
	glShaderSource(shader, 1, &c, nullptr);


	glCompileShader(shader);

	// это наверное надо будет в отдельную переключаемую функцию вывести
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);

	if (len > 0) {
		std::cout << "WARNING: Can't compile shader:" << path << std::endl << buf << std::endl;
	}
	/*else {
		std::cout << "Everything works fine\n"; // чисто для проверки
	}*/

	return shader;
}


void GL::ShaderSystem::link()
{
	glAttachShader(mProgram, mVertex);
	glAttachShader(mProgram, mFragment);
	glLinkProgram(mProgram);
}

void GL::ShaderSystem::bindAttribute(GLuint index, const std::string& name)
{
	glBindAttribLocation(mProgram, index, name.c_str());
}

void GL::ShaderSystem::use()
{
	glUseProgram(mProgram);
}

GL::ShaderSystem::~ShaderSystem()
{
	glDeleteProgram(mProgram);
}
