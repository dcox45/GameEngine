#include "RenderingSystem.h"
#include <iostream>
#include "ECS.h"
#include "Components.h" 


RenderingSystem::RenderingSystem(void)
{
}

RenderingSystem::~RenderingSystem(void)
{
}

void RenderingSystem::tick(ECS::World* world, float deltaTime) {

	Engine::getInstance().window->clear();

	world->each<Transform, Sprite>(
		[&](ECS::Entity* ent,
			ECS::ComponentHandle<Transform> transform,
			ECS::ComponentHandle<Sprite> sprite) -> void {

				

			//Add texture to map 
				if (_textureMap.count(sprite->texture) < 1) { 
					_textureMap[sprite->texture] = _loadTexture(sprite->texture);
				} 
				//If there's not texture, add it 
				if (sprite->sprite.getTexture() == NULL) {  
					sprite->sprite.setTexture(*_textureMap[sprite->texture]); 
					sprite->width = sprite->sprite.getGlobalBounds().width;  
					sprite->height = sprite->sprite.getGlobalBounds().height; 
				} 
				//Update position and draw to screen 
				sprite->sprite.setPosition(transform->X, transform->Y);
				Engine::getInstance().window->draw(sprite->sprite);
				
				
		});
	Engine::getInstance().window->display();
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



