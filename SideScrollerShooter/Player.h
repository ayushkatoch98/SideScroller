#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "LevelGenerator.h"

class Enemy;

class Player{

private:

	float speed;
	float jumpForce;


	sf::Vector2f gravity;
	sf::Vector2f velocity;

	sf::Texture *texture;
	sf::Sprite player;

	sf::RenderWindow* window;

	sf::Font *font;

	bool grounded;
	bool attack;
	float moveX;
	float moveY;
	float health;
	float receviedHit;

	Animation *idleAnim;
	Animation *runningAnim;
	Animation *attackAnim;
	Animation *jumpAnim;
	Animation *fallAnim;

public:
	Player(sf::RenderWindow& window, sf::Texture* texture, sf::Font *font);

	void update(float deltaTime, std::vector<Enemy*>& enemies);

	~Player() {
		delete idleAnim;
		delete runningAnim;
		delete attackAnim;
		delete jumpAnim;
		delete fallAnim;
	}


	void handleInput(sf::Event event);

	void collisionGround(std::vector<std::vector<Tile>> tiles);

	void collisionAttack(std::vector<Enemy*> enemies);

	bool hit();


	int getHealth() { return (int) this->health; }


	sf::Sprite getPlayer() { return this->player; }
	sf::Vector2f getVelocity() { return this->velocity; }
};