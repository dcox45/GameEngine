#pragma once
#include "ECS.h"
#include "Components.h"
#include "Engine.h"


class MovementSystem : public ECS::EntitySystem
{


public: 

	MovementSystem(void);
	~MovementSystem(void);
	void tick(ECS::World* world, float dTime) override;

};

