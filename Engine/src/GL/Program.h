#pragma once
#include <string>
#include "gl.h"

namespace GL {
	class Program
	{
	private:
		GLuint mProgram;
		GLuint mVertexShader;
		GLuint mFragmentShader;

		GLuint getLocation(const std::string& name);
		GLuint loadSheder(const std::string& path, GLenum shaderType);
	public:
		Program(const std::string& name);
		void link();
		void use();
		void bindAttribute(GLuint index, const std::string& name);

		void setFloat(const std::string& name, float value);
		~Program();
	};
}
