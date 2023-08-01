#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "LevelGenerator.h"

class Player;

class Enemy {

private:

	float speed;
	float jumpForce;

	Player* target;

	sf::Vector2f gravity;
	sf::Vector2f velocity;
	sf::Vector2f initialPos;

	sf::Texture* texture;
	sf::Sprite enemy;

	sf::RenderWindow* window;

	sf::Clock lastAttack;

	bool grounded;
	bool attack;
	bool isActive;
	bool receviedHit;
	float moveX;
	float moveY;
	float health;

	Animation* idleAnim;
	Animation* runningAnim;
	Animation* attackAnim;
	Animation* jumpAnim;
	Animation* fallAnim;

public:

	Enemy(sf::RenderWindow& window, sf::Texture* texture, Player &target, sf::Vector2f initialPos);

	//~Enemy() {
	//	delete idleAnim;
	//	delete runningAnim;
	//	delete attackAnim;
	//	delete jumpAnim;
	//	delete fallAnim;
	//}

	void update(float deltaTime);

	bool hit();

	void collisionTarget();

	void collisionGround(std::vector<std::vector<Tile>> tiles);


	bool isEnabled() { return this->isActive;  }

	sf::Sprite getEnemy() { return this->enemy; }
	sf::Vector2f getVelocity() { return this->velocity; }
};