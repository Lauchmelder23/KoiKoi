#pragma once

#include <vector>
#include <lol/lol.hpp>


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

	lol::ObjectManager manager;
	std::vector<lol::Layer*> layerStack;

private:
	Application();
	~Application();
};