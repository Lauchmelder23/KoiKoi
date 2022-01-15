#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <lol/lol.hpp>

class Application;

struct UserData
{
	lol::OrthogonalCamera* camera;
	Application* app;
};

class Window
{
public:
	Window(Application* app, int width, int height, const std::string& title);
	~Window();

	inline bool IsValid() { return valid; }
	inline bool ShouldClose() { return glfwWindowShouldClose(window); }
	inline GLFWwindow* GetNativeWindow() { return window; }

	void Clear();
	void Draw(lol::Layer& layer);
	void Display();

private:
	bool valid;
	GLFWwindow* window;
	Application* app;
	UserData data;

	lol::OrthogonalCamera camera;
};
