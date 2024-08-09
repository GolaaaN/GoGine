#pragma once



extern GOG::Application* GOG::CreateApplication();

int main(int argc, char** argv) {

	GOG::Logger::Init();
	GOG::Logger::GetClientLogger()->debug("hi");


	auto app = GOG::CreateApplication();

	app->run();
	
	delete app; //Todo: use RAII instead of this implementation.
}
