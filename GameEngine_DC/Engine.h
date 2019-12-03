#pragma once
#include <SFML/Graphics.hpp>
#include "ECS.h"
class Engine
{

private:
	Engine(void);
	~Engine(void);

	//Engine(Engine& copy);		// Hide Copy Constructor
	//Engine(Engine&& other);		// Hide Move Constructor
	//Engine& operator = (Engine& copy);	// Hide Assignment Operator
	bool quit;
	void update();

public:
	
	static Engine& getInstance(void);
	void start(sf::RenderWindow* win);
	sf::RenderWindow* window;

	ECS::World* world;
	
	void addSystem(ECS::EntitySystem* newSys)
	{
		world->registerSystem(newSys);
		world->enableSystem(newSys);
	}
	

};

