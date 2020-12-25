#include "VAO.h"
#include <gl.h>
#include <glm/glm.hpp>

GL::VAO::VAO() {
	glGenVertexArrays(1, &mVAO);
	bind();
}
void GL::VAO::bind()
{
	glBindVertexArray(mVAO);
}

void GL::VAO::draw(GLsizei count) {
	bind();
	for (size_t i = 0; i < mBuffers.size(); i++) {
		glEnableVertexAttribArray(i);
	}
	glDrawArrays(GL_TRIANGLES, 0, count);

	for (size_t i = 0; i < mBuffers.size(); i++) {
		glDisableVertexAttribArray(i);
	}
}

void GL::VAO::addVertexBufferObject(const std::vector<float>& data) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 1, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

void GL::VAO::addVertexBufferObject(const std::vector<glm::vec2>& data) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

void GL::VAO::addVertexBufferObject(const std::vector<glm::vec3>& data) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

void GL::VAO::addVertexBufferObject(const std::vector<glm::vec4>& data) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

GL::VAO::~VAO() {
	glDeleteBuffers(mBuffers.size(), mBuffers.data());
	glDeleteVertexArrays(1, &mVAO);
}