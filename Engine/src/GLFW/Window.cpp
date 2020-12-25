#include <gl.h>
#include "Window.h"
#include <GL/Program.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "GL/VAO.h"
#include <stdexcept>
#include <GL/Program.h>


Window::Window(const std::string& title, int width, int height) {
	mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!mWindow) {
		throw std::runtime_error("Cloud not initialize window");
	}
	setContextCurrent();
	glewExperimental = true;
	
	if (glewInit() != GLEW_OK) {
		throw std::runtime_error("Cloud not initialize GLEW");
	}
}
void Window::setContextCurrent() {
	glfwMakeContextCurrent(mWindow);
}
void Window::loop() {

	GL::VAO vao;
	vao.addVertexBufferObject({
		{0.f, 0.5f, 0.f},
		{-0.5f, -0.5f, 0.f},
		{0.5f, 0.5f, 0.f},
	});

	vao.addVertexBufferObject({
		{1, 0, 0},
		{0, 0, 1},
		{0, 1, 0}
	});

	GL::Program first("first");

	first.bindAttribute(0, "position");
	first.bindAttribute(1, "color");
	first.link();
	first.use();

	float anim = 0.f;

	while (!glfwWindowShouldClose(mWindow))
	{
		anim += 0.01f;
		first.setFloat("animation", glm::sin(anim) * 0.5f + 0.5f);

		glClearColor(0.f, 0.f, 0.f, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		vao.draw(3);
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}
Window::~Window() {
	glfwDestroyWindow(mWindow);
}