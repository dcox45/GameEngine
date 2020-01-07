
#include "include/Engine.h"

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

void Engine::start(sf::RenderWindow* win) {
	
	window = win;
	quit = false; 
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
		world->tick(1.0f);
	}
}

void Engine::addSystem(ECS::EntitySystem* newSys)
{
	world->registerSystem(newSys);
	world->enableSystem(newSys);
}

Engine::~Engine(void) {

}

