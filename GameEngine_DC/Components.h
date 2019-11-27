#pragma once
#include "ECS.h"
#include <iostream>
class Components
{
	struct Transform {
		ECS_DECLARE_TYPE;  
		Transform(float x, float y) {
			X = x;   
			Y = y;   
			rotation = 0.f;
		}

		float X;  
		float Y;  
		float rotation;
	};

	ECS_DEFINE_TYPE(Transform);


struct Sprite {
	ECS_DECLARE_TYPE;

	Sprite(std::string name) {
		texture = name;
	}
	sf::Sprite sprite;   
	std::string texture;   
	int width;   
	int height;
};  

ECS_DEFINE_TYPE(Sprite);


};