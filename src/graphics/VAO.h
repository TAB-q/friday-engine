#pragma once
#include <glad/glad.h>
#include <vector>

namespace GL {
	class VAO
	{
	private:
		GLuint mVao;
		std::vector<GLuint> mBuffers;
	public:
		VAO();
		void bind();
		void draw(GLsizei count);
		void addVBO(const std::vector<float> data);
		VAO(const VAO&) = delete;
		~VAO();
	};
}


