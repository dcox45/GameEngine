#pragma once
#include "ECS.h"
#include <iostream>
#include <SFML/Graphics.hpp>

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

struct Animator {
	ECS_DECLARE_TYPE;

	Animator(int width, int height, float timeBetweenFrames) {

		sprWidth = width;
		sprHeight = height;
		currCol = 0;
		currRow = 0;
		nextFrameTime = timeBetweenFrames;
		currTime = 0;
	}

	int sprWidth;
	int sprHeight;
	int currCol;
	int currRow;
	float currTime;
	float nextFrameTime;

		 

	}
};

ECS_DEFINE_TYPE(Animator); 

