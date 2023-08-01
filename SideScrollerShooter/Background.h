#pragma once
#include <SFML/Graphics.hpp>


class Background {

private:


	bool pause;

	float speed;

	int activeBg;
	sf::Texture *bgTex;

	sf::RenderWindow* window;
	sf::Sprite bg[2];

public:

	Background(sf::RenderWindow& window, sf::Texture* texture, float screenPercent, float bgSpeed);
	~Background() {
		
	}
	void render();
	void update(float deltaTime, sf::Vector2f velocity);

	sf::Sprite* getBg() { return this->bg; }

	void setPause(bool pause) { this->pause = pause; }

private:


};