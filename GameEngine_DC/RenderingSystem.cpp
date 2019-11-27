#include "RenderingSystem.h"
#include <iostream>
#include "ECS.h"
#include "Components.h" 


void RenderingSystem::tick(ECS::World* world, float deltaTime) {
	world->each<Transform, Sprite>(
		[&](ECS::Entity* ent, 
			ECS::ComponentHandle<Transform> transform, 
			ECS::ComponentHandle<Sprite> sprite) -> void {  
				//Do stuff here   
		}; 
}

sf::Texture* RenderingSystem::_loadTexture(std::string Texture)
{
	sf::Texture* tex = new sf::Texture();
	if (!tex->loadFromFile(Texture)) {
		std::cerr << "Unable to load image." << Texture << ".\nIs this image in the correct directory? " << std::endl;
		std::cerr << "Error:  " << std::endl;
		system("pause"); 
		exit(EXIT_FAILURE);
	}
	return tex;
}
