#include <glad/glad.h>
#include <string>
#include <string>
#include <fstream>
#include <iostream>
#pragma once

namespace GL {
	class ShaderSystem
	{
	private:
		GLuint mProgram;
		GLuint loadShader(const std::string& path, GLenum shaderType);
		GLint setFloat(const std::string& name, float value);
		GLint getLocation(const std::string& name);
		GLuint mVertex;
		GLuint mFragment;
	public:
		ShaderSystem(const std::string& name);
		~ShaderSystem();
		void link();
		void bindAttribute(GLuint index, const std::string& name);
		void use();
	};
}

