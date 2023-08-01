#include "Background.h"
#include <iostream>
#include "Global.h"


Background::Background(sf::RenderWindow& window, sf::Texture *texture, float screenPercent, float bgSpeed) {


	this->pause = false;

	this->speed = bgSpeed;
	this->bgTex = texture;
	this->window = &window;


	for (int i = 0; i < PRE_LOAD_BG; i++) {

		this->bg[i] = sf::Sprite();
		this->bg[i].setTexture(*this->bgTex);


		this->bg[i].setScale(SCREEN_WIDTH / (float)this->bg[i].getTexture()->getSize().x, ((screenPercent * SCREEN_HEIGHT) / 100) / this->bg[i].getTexture()->getSize().y);

		this->bg[i].setPosition(sf::Vector2f(SCREEN_WIDTH * i, 0.f));


	}


}


void Background::render() {

	for (int i = 0; i < PRE_LOAD_BG; i++) {
		this->window->draw(this->bg[i]);
	}
	
}


void Background::update(float deltaTime, sf::Vector2f velocity) {


	if (this->pause) {
		this->render();
		return;
	}
	for (int i = PRE_LOAD_BG - 1; i >= 0; i--) {

		// reset bg position
		if (this->bg[i].getPosition().x + this->bg[i].getGlobalBounds().width <= 0.f) {
			int x = i - 1;
			if (x < 0) {
				x = PRE_LOAD_BG - 1;
			}
			this->bg[i].setPosition(this->bg[x].getPosition().x + this->bg[x].getGlobalBounds().width, this->bg[i].getPosition().y);
		}
		// move 

		float newX = -(this->speed * deltaTime * velocity.x);
		this->bg[i].move(newX, 0.f);
	}


	this->render();

}