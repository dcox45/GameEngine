// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include "include/Engine.h"
#include "include/Components.h"
#include "include/RenderingSystem.h"
#include "include/AnimationSystem.h"


int main()
{

	Engine& gameEngine = Engine::getInstance();
	sf::RenderWindow win(sf::VideoMode(800, 600), "Game Engine");

	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* ent;

	gameEngine.addSystem(new RenderingSystem());
	gameEngine.addSystem(new AnimationSystem());


	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 10; j++) {
			ent = gameEngine.world->create();
			ent->assign<Transform>(i * 25, j * 32);
			ent->assign <Sprite>("../Debug/herosheet.png");
			ent->assign<Animator>(32, 32, 200.f);
		}
	}
	gameEngine.start(&win);

   // std::cout << "Hello World!\n";
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
