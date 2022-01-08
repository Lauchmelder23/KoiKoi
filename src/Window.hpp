#pragma once

#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	inline bool IsValid() { return valid; }
	inline bool ShouldClose() { return glfwWindowShouldClose(window); }

	void Display();

private:
	bool valid;
	GLFWwindow* window;
};
