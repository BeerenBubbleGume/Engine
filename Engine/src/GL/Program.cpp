#include "Program.h"
#include <iterator>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

GL::Program::Program(const std::string& name) {
	mProgram = glCreateProgram();
	mVertexShader = loadSheder("/res/glsl/" + name + ".vert", GL_VERTEX_SHADER);
	mFragmentShader = loadSheder("/res/glsl/" + name + ".frag", GL_VERTEX_SHADER);
}

GL::Program::~Program() {
	
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
	glDeleteProgram(mProgram);
}

void GL::Program::link() {
	glAttachShader(mProgram, mVertexShader);
	glAttachShader(mProgram, mFragmentShader);

	glLinkProgram(mProgram);
}

void GL::Program::bindAttribute(GLuint index, const std::string& name) {
	glBindAttribLocation(mProgram, index, name.c_str());
}

void GL::Program::use() {
	glUseProgram(mProgram);
}

void GL::Program::setFloat(const std::string& name, float value) {
	glUniform1f(getLocation(name), value);
}

GLuint GL::Program::getLocation(const std::string& name) {
	return glGetUniformLocation(mProgram, name.c_str());
}

GLuint GL::Program::loadSheder(const std::string& path, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);

	std::ifstream fis(path);
	std::string shaderCode = { std::istream_iterator<char>(fis), std::istream_iterator<char>() };
	const char* c = shaderCode.c_str();
	glShaderSource(shader, 1, &c, nullptr);

	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);
	if (len > 0) {
		cout << path << ":" << endl << buf;

	}
	if (!status) {
		throw runtime_error("could not compile shader: " + path);
	}

	return shader;
}