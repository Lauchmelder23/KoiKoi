#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <lol/lol.hpp>

struct UserData
{
	lol::OrthogonalCamera* camera;
};

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	inline bool IsValid() { return valid; }
	inline bool ShouldClose() { return glfwWindowShouldClose(window); }

	void Clear();
	void Draw(lol::Layer& layer);
	void Display();

private:
	bool valid;
	GLFWwindow* window;
	UserData data;

	lol::OrthogonalCamera camera;
};
