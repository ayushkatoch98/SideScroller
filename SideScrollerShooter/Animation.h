#pragma once
#include <SFML/Graphics.hpp>

class Animation {
public:

	/**
	*@param textureFileName: The file name for the spritesheet
	*@param spriteTimeLength: Time in seconds a singe sprite will stay on the screen.
	*@param numSprites: vector detailing how many sprites are on the spritesheet horizontally (x), and vertically (y).
	*/
	//Animation(const std::string& textureFileName, float spriteTimeLength, const sf::Vector2u& numSprites);
	//Animation(sf::Texture* spriteTexture, bool loop, float spriteTimeLength, const sf::Vector2u numSprites);
	Animation(sf::Texture* spriteTexture, bool loop, float spriteTimeLength, sf::Vector2u spriteSize, const sf::Vector2u numSprites);
	void update(float deltaTime, sf::Sprite& object);

	sf::Texture spriteTexture;
	std::vector<sf::IntRect> spriteCords;
	sf::Vector2u spriteSize;
	int currentFrame;
	float currentTime;
	bool loop;
	bool animationFinished;
	sf::Clock clock;


	//Time in seconds a singe sprite will stay on the screen.
	float SPRITE_LENGTH_TIME;
};