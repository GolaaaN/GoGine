#pragma once



extern GOG::Application* GOG::CreateApplication();

int main(int argc, char** argv) {

	GOG::Logger::Init();
	GOG::Logger::GetClientLogger()->debug("hi");

	std::unique_ptr<GOG::Application*> app = std::make_unique<GOG::Application*>(GOG::CreateApplication());

	(*app)->run();
}
