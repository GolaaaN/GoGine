#include <iostream>
#include "GoGine.h"

class SandBox : public GOG::Application {
public:
	SandBox() {

	}

	virtual ~SandBox() {

	}
};



GOG::Application* GOG::CreateApplication() {
	return new SandBox();
} 

