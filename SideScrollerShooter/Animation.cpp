#include "Animation.h"
#include <iostream>
#include "Random.h"

Animation::Animation(sf::Texture * spriteTexture, bool loop, float spriteTimeLength, sf::Vector2u spriteSize, const sf::Vector2u numSprites) {

	this->SPRITE_LENGTH_TIME = spriteTimeLength;
	this->currentTime = 0.f;
	this->currentFrame = 0;
	this->animationFinished = false;
	this->loop = loop;

	this->spriteSize = spriteSize;

	
	for (int x = 0; x < numSprites.x; x++) {
		this->spriteCords.push_back(sf::IntRect(
			(this->spriteSize.x * x), 
			(this->spriteSize.y * numSprites.y), 
			this->spriteSize.x, 
			this->spriteSize.y)
		);

	}
	

}

void Animation::update(float deltaTime, sf::Sprite &object) {
	this->currentTime = clock.getElapsedTime().asSeconds();


	if (this->currentTime >= this->SPRITE_LENGTH_TIME) {
		this->currentTime -= this->SPRITE_LENGTH_TIME;
		clock.restart();

		//std::cout << "CURRENT TIME " << this->currentTime << std::endl;
		if (this->currentTime > this->SPRITE_LENGTH_TIME) {
			this->currentFrame = 0;
			this->animationFinished = false;
		}
		else if (this->currentFrame + 1 >= this->spriteCords.size()){
			if (this->loop) {
				this->currentFrame = 0;
				this->animationFinished = true;
			}
		}	
		
		else {
			this->currentFrame++;
			this->animationFinished = false;
		}
		
	}

	object.setTextureRect(this->spriteCords[this->currentFrame]);

}
