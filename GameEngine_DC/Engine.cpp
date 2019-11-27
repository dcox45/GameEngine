
#include "Engine.h"

Engine::Engine(void) {
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");
	//
	//while (window.isOpen()) {
	//	sf::Event event;
	//	while (window.pollEvent(event)) {
	//		if (event.type == sf::Event::Closed || quit)
	//			window.close();
	//
	//
	//	}
	//	//return 0;
	//}
}

Engine& Engine::getInstance(void) {
	static Engine instance;
	return instance;
}

void Engine::start(int width, int height, std::string name) {
	sf::RenderWindow win(sf::VideoMode(width, height), name);
	window = &win;
	update();

	
}

void Engine::update() {
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || quit)
				window->close();


		}
		//return 0;
	}
}

Engine::~Engine(void) {

}


