#pragma once

class Window;

class Application
{
public:
	static Application& GetInstance()
	{
		static Application app;
		return app;
	}

public:
	void Run();

private:
	bool valid;
	Window* window;

private:
	Application();
	~Application();
};