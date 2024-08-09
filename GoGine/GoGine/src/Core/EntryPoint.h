#pragma once

#include "Application.h"

extern GOG::Application* GOG::CreateApplication();

int main(int argc, char** argv) {
	auto app = GOG::CreateApplication();

	app->run();
	
	delete app; //Todo: use RAII instead of this implementation.
}
