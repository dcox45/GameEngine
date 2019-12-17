#include <Engine.h>
#include <ECS.h>
#include <Components.h>

int main()
{
	Engine& gameEngine = Engine::getInstance();
	sf::RenderWindow win(sf::VideoMode(800, 600), "Game Engine");

	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* ent;

	gameEngine.addSystem(new RenderingSystem());
	gameEngine.addSystem(new AnimationSystem());

	for (int j = 0; j < 10; j++) {
		ent = gameEngine.world->create();
		ent->assign<Transform>(i * 25, j * 32);
		ent->assign <Sprite>("../Debug/herosheet.png");
		ent->assign<Animator>(32, 32, 200.f);
	}
	
	gameEngine.start(&win);
}