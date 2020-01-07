#include <SFML/Graphics.hpp>
#include <Engine.h>


int main()
{
	Engine& gameEngine = Engine::getInstance();
	sf::RenderWindow win(sf::VideoMode(800, 600), "Game Engine");

	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* ent;
	ECS::Entity* background; 

	gameEngine.addSystem(new RenderingSystem());
	gameEngine.addSystem(new AnimationSystem());
	gameEngine.addSystem(new MovementSystem());

	background = gameEngine.world->create();
	background->assign<Transform>(0, 0);
	background->assign<Sprite>("../Debug/background.png");

	for (int j = 0; j < 10; j++) {
		ent = gameEngine.world->create();
		ent->assign<Transform>(25, 32);
		ent->assign<Sprite>("../Debug/herosheet.png");
		ent->assign<Animator>(32, 32, 200.f);
		ent->assign<InputController>();
	}

	
	
	gameEngine.start(&win);
	return 0;
}