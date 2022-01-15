#include "Application.hpp"

#include <chrono>
#include <random>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <stbi_image.h>

#include "Window.hpp"
#include "layers/CardStackLayer.hpp"
#include "layers/BoardLayer.hpp"

#include "resources.h"
#include "ObjectIDs.hpp"

void Application::Run()
{
	if (!valid)
	{
		spdlog::error("Application could not be launched");
		return;
	}

	spdlog::debug("Launched Application");
	while (!window->ShouldClose())
	{
		glfwPollEvents();

		for (lol::Layer* layer : layerStack)
			layer->OnUpdate();

		window->Clear();

		for (lol::Layer* layer : layerStack)
			window->Draw(*layer);

		window->Display();
	}
}

void Application::OnKeyPressed(unsigned int character)
{
	if (character == 'd' || character == 'D')
		game.GetBoard().RevealCard();
}

Application::Application() :
	valid(true), window(nullptr)
{
	int success = glfwInit();
	if (success != GLFW_TRUE)
	{
		const char* buffer;
		int result = glfwGetError(&buffer);
		spdlog::critical("Failed to initialize GLFW: ({}) {}", result, buffer);

		valid = false;
		return;
	}
	spdlog::debug("GLFW initialized");

	window = new Window(this, 1280, 720, "Koi Koi");
	valid = window->IsValid();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		spdlog::critical("Failed to load GL loader");
		valid = false;
		return;
	}
	spdlog::debug("Loaded GL loader");

	spdlog::debug("Loading resources...");

	lol::Image image((unsigned char*)card_atlas_png, card_atlas_png_size);
	manager.Create<lol::Texture2D>(TEXTURE_CARD_ATLAS, image, lol::TextureFormat::RGBA);

	lol::Image backsideImage((unsigned char*)card_backside_png, card_backside_png_size);
	manager.Create<lol::Texture2D>(TEXTURE_BACKSIDE, backsideImage, lol::TextureFormat::RGBA);

	manager.Create<lol::Shader>(SHADER_CARD, std::string((char*)card_vs, card_vs_size), std::string((char*)card_fs, card_fs_size));
	spdlog::debug("Done!");

	spdlog::debug("Setting up layers");
	layerStack.push_back(new CardStackLayer(manager, game.GetStack()));
	BoardLayer* boardLayer = new BoardLayer(manager, game.GetBoard());
	game.GetBoard().SetRevealCallback(std::bind(&BoardLayer::OnRevealCard, boardLayer, std::placeholders::_1));
	layerStack.push_back(boardLayer);

	spdlog::debug("Setting up game");
	game.Setup();

	glViewport(0, 0, 1280, 720);

	// Enable transparency
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Application::~Application()
{
	for (lol::Layer* layer : layerStack)
		delete layer;

	delete window;

	glfwTerminate();
	spdlog::debug("GLFW terminated");
}
