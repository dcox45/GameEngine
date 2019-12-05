#include "AnimationSystem.h"
#include "RenderingSystem.h"
#include <iostream>
#include "ECS.h"
#include "Components.h"

void AnimationSystem::tick(ECS::World* world, float dTime) {
	world->each<Animator, Sprite>(
		[&](ECS::Entity* ent,
			ECS::ComponentHandle<Animator> animator,
			ECS::ComponentHandle <Sprite> sprite) -> void {

				sprite->sprite.setTextureRect(
					sf::IntRect(animator->currCol * animator->sprWidth,
						animator->currRow * animator->sprHeight,
						animator->sprWidth,
						animator->sprHeight));

				animator->currTime += dTime;
				if (animator->currTime >= animator->nextFrameTime) {
					animator->currTime = 0;
					animator->currCol = (animator->currCol + 1) % 4;
				}
		});

	

		
}
