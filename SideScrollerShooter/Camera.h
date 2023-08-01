#pragma once
#include <SFML/Graphics.hpp>
#include "Global.h"

class Camera{

private:
	sf::View *camera;

public:

	Camera();
	void update(float deltaTime, sf::Sprite object);
	~Camera() {
		delete this->camera;
	}
	sf::View get() { return *this->camera; }
	

};

