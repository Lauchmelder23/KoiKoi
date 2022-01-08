#include <spdlog/spdlog.h>
#include "Application.hpp"

int main(int argc, char** argv)
{
	spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");

#ifndef NDEBUG
	spdlog::set_level(spdlog::level::debug);
#endif

	Application::GetInstance().Run();
	return 0;
}