#pragma once

#include <vector>
#include <chrono>
#include <lol/lol.hpp>

#include "CardStack.hpp"
#include "Game.hpp"


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
	void OnKeyPressed(unsigned int character);	// TODO: Remove later on

	inline double GetFrametime() { return frametime; }

private:
	bool valid;
	Window* window;

	Game game;

	lol::ObjectManager manager;
	std::vector<lol::Layer*> layerStack;

	double frametime;

private:
	Application();
	~Application();
};