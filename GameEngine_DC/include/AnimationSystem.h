#pragma once

#include <iostream>
#include "ECS.h"
#include "Components.h"

class AnimationSystem : public ECS::EntitySystem
{

public:
	AnimationSystem(void);
	~AnimationSystem(void);
	void tick(ECS::World* world, float dTime); 

};


