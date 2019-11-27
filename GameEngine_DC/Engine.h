#include <SFML/Graphics.hpp>
#include "ECS.h"
class Engine
{

private:
	bool quit;
	Engine(void);
	~Engine(void);
	void update();

	Engine(Engine& copy);
	Engine(Engine&& other);
	Engine& operator= (Engine& copy);



public:
	static Engine& getInstance(void);
	void start(int width, int height, std::string name);
	sf::RenderWindow* window;

	ECS::World* world;
	void addSystem(ECS::EntitySystem* newSys);


};

