#include "Camera.h"
#include <iostream>

#define GRAY_AREA 200

Camera::Camera() {
	this->camera = new sf::View(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));
}

template<typename T>
T clamp(T min, T current, T max){
	if (current > max) return max;
	if (current < min) return min;
	return current;
}

void Camera::update(float deltaTime, sf::Sprite object) {

	//sf::Vector2f newOrigin = sf::Vector2f(object.getPosition().x + (SCREEN_WIDTH / 2), object.getPosition().y + (SCREEN_HEIGHT / 2));
	float oneForth = SCREEN_WIDTH / 4.0f;
	
	// current screen
	sf::Vector2f objectPos = object.getPosition();
	
	// screen
	/*sf::Vector2f origin = this->camera->getCenter();
	float min = origin.x - (SCREEN_WIDTH / 2);
	float max = origin.x + (SCREEN_WIDTH / 2);

	float newX;

	newX = clamp(min, origin.x, max);

	if (objectPos.x > origin.x + GRAY_AREA || objectPos.x < origin.x - GRAY_AREA) {
		newX = objectPos.x;
	}
*/
	
	//std::cout << "Camera Viewport" << this->camera->getCenter().x << " | " << this->camera->getCenter().y << std::endl;
	sf::Vector2f newOrigin = {std::max(objectPos.x, SCREEN_WIDTH / 2.0f) , (SCREEN_HEIGHT / 2)};
	//this->camera->move(
	this->camera->setCenter(newOrigin);
}
