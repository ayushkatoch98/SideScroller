#include "Enemy.h"
#include <iostream>
#include "Global.h"
#include "Player.h"

Enemy::Enemy(sf::RenderWindow& window, sf::Texture* texture, Player& target, sf::Vector2f initialPos) {

	this->window = &window;

	this->initialPos = initialPos;

	this->target = &target;

	this->health = 100.f;

	this->speed = ENEMY_SPEED;
	this->jumpForce = PLAYER_JUMP_FORCE;
	this->gravity = sf::Vector2f(0.f, GRAVITY);
	this->velocity = sf::Vector2f(0.f, 0.f);

	this->texture = texture;

	this->enemy.setTexture(*this->texture);
	this->enemy.setPosition(this->initialPos);
	this->enemy.setTextureRect(sf::IntRect(0, 0, 41, 65));
	this->enemy.scale(PLAYER_SCALE, PLAYER_SCALE);
	this->enemy.setOrigin(this->enemy.getGlobalBounds().width / 2, this->enemy.getGlobalBounds().height / 2);
	this->enemy.setColor(sf::Color::Red);

	this->grounded = false;
	this->attack = false;
	this->isActive = false;
	this->receviedHit = false;
	this->moveX = 0.f;
	this->moveY = 0.f;

	this->idleAnim = new Animation(texture, true, PLAYER_JUMP_ANIM_SPEED, { 56,56 }, { 6, 0 });
	this->runningAnim = new Animation(texture, true, PLAYER_RUN_ANIM_SPEED, { 56,56 }, { 7, 2 });
	this->attackAnim = new Animation(texture, true, PLAYER_ATTACK_ANIM_SPEED, { 56,56 }, { 5, 1 });
	this->jumpAnim = new Animation(texture, false, PLAYER_JUMP_ANIM_SPEED, { 56,56 }, { 7, 3 });
	this->fallAnim = new Animation(texture, false, PLAYER_FALL_ANIM_SPEED, { 56,56 }, { 5, 4 });

	this->lastAttack = sf::Clock();
}

void Enemy::update(float deltaTime) {
	if (this->health <= 0.f) return;


	float a = this->window->getView().getCenter().x - SCREEN_WIDTH;
	float b = this->window->getView().getCenter().y - SCREEN_HEIGHT;
	sf::FloatRect viewArea(a, b, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (viewArea.contains(this->enemy.getPosition())) {
		this->isActive = true;
	}


	if (!this->isActive) return;


	
	

	// vertical movement

	if (this->moveY < 0.f) {
		this->velocity.y += this->moveY * this->gravity.y * this->jumpForce;
		this->jumpForce -= 0.1f;
		if (this->jumpForce <= 0.f) {
			this->moveY = 0.f;
		}
		this->grounded = false;
	}
	else if (this->grounded) {
		this->velocity.y = 0.f;
		this->jumpForce = PLAYER_JUMP_FORCE;
	}
	else {
		this->velocity.y += this->gravity.y;
	}


	// horizontal movement
	this->velocity.x = moveX * this->speed;

	this->collisionTarget();

	if (this->target->getPlayer().getPosition().x < this->enemy.getPosition().x) {
		this->enemy.setScale(-PLAYER_SCALE, PLAYER_SCALE);
		if (this->isActive && !this->attack) {
			this->moveX = -1.0f;
		}

	}
	else{
		this->enemy.setScale(PLAYER_SCALE, PLAYER_SCALE);
		if (this->isActive && !this->attack) {
			this->moveX = 1.0f;
		}

	}

	


	// animation state
	if (this->attackAnim->animationFinished) {
		this->attack = false;
		this->attackAnim->animationFinished = false;
		this->target->hit();
		this->lastAttack.restart();
	}

	if (this->attack && this->lastAttack.getElapsedTime().asSeconds() >= ENEMY_ATTACK_SPEED) {
		
		this->attackAnim->update(deltaTime, this->enemy);
	}
	else if (velocity.y != 0.f) {
		if (velocity.y < 0.f) {
			this->jumpAnim->update(deltaTime, this->enemy);
		}
		else {
			this->fallAnim->update(deltaTime, this->enemy);
		}
	}
	else if (this->moveX != 0.f) {
		this->runningAnim->update(deltaTime, this->enemy);
	}

	else if (this->velocity.x == 0.f && this->velocity.y == 0.f) {
		this->idleAnim->update(deltaTime, this->enemy);
	}
	//Animation::update(deltaTime, this->enemy);

	if (this->receviedHit) {
		this->receviedHit = false;
		this->velocity.x += 1000.f;
	}

	this->enemy.move(this->velocity * deltaTime);

	this->window->draw(this->enemy);

}

bool Enemy::hit() {
	this->receviedHit = true;
	this->isActive = false;
	this->health = -10.f;

	return this->health <= 0.f;
}


void Enemy::collisionTarget() {
	sf::FloatRect enemyBound = this->enemy.getGlobalBounds();
	float x = enemyBound.width / 2.0;
	enemyBound.left += x;
	enemyBound.width = abs(enemyBound.width - ((1.9 * x)));

	if (enemyBound.intersects(this->target->getPlayer().getGlobalBounds())) {
		this->moveX = 0.f;
		this->attack = true;
	}
	else {
		this->attack = false;
	}
}

void Enemy::collisionGround(std::vector<std::vector<Tile>> tiles) {

	float x = floor(this->enemy.getPosition().x / (TILE_SIZE * TILE_SCALE));

	float floorStart = tiles.size() - 3;


	sf::FloatRect enemyBound = this->enemy.getGlobalBounds();

	for (int y = 0; y < floorStart; y++) {

		if (tiles[y][x].sprite != nullptr) {
			if (tiles[y][x].sprite->getGlobalBounds().intersects(enemyBound)) {
				this->grounded = true;
				return;
			}

		}
	}

	this->grounded = false;

}