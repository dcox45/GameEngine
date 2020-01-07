#pragma once 
#include "MovementSystem.h"


MovementSystem::MovementSystem(void)
{
}

MovementSystem::~MovementSystem(void)
{
}

void MovementSystem::tick(ECS::World* world, float dTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		world->each<InputController, Transform>(
			[&](ECS::Entity* ent,
				ECS::ComponentHandle<InputController> input,
				ECS::ComponentHandle<Transform> transform) -> void {
			transform->Y -= 10;
		});
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		world->each<InputController, Transform>(
			[&](ECS::Entity* ent,
				ECS::ComponentHandle<InputController> input,
				ECS::ComponentHandle<Transform> transform) -> void {
			transform->Y += 10;
		});
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		world->each<InputController, Transform>(
			[&](ECS::Entity* ent,
				ECS::ComponentHandle<InputController> input,
				ECS::ComponentHandle<Transform> transform) -> void {
			transform->X -= 10;
		});
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		world->each<InputController, Transform>(
			[&](ECS::Entity* ent,
				ECS::ComponentHandle<InputController> input,
				ECS::ComponentHandle<Transform> transform) -> void {
			transform->X += 10;
		});
	}
}