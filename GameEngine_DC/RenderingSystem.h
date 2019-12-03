#pragma once
#include "ECS.h" 
#include "Engine.h" 
#include "Components.h" 

class RenderingSystem : public ECS::EntitySystem
{

private:

	std::unordered_map<std::string, sf::Texture*> _textureMap;
	sf::Texture* _loadTexture(std::string Texture);

public:
	RenderingSystem(void);
	~RenderingSystem(void);
	void tick(ECS::World* world, float dTime) override;

};


