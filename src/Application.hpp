#pragma once

#include <lol/lol.hpp>

class Window;
class Card;

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
	Card* card;

private:
	Application();
	~Application();
};