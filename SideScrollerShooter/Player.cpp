#include <iostream>
#include "Player.h"
#include "Global.h"
#include "Enemy.h"
#include "LevelGenerator.h"




Player::Player(sf::RenderWindow &window, sf::Texture *texture, sf::Font *font){

	this->window = &window;

	this->font = font;

	this->speed = PLAYER_SPEED;
	this->jumpForce = PLAYER_JUMP_FORCE;
	this->gravity = sf::Vector2f(0.f, GRAVITY);
	this->velocity = sf::Vector2f(0.f, 0.f);

	this->texture = texture;


	this->player.setTexture(*this->texture);
	this->player.setPosition(sf::Vector2f(300.f, 300.f));
	this->player.setTextureRect(sf::IntRect(0, 0, 41, 65));
	this->player.scale(PLAYER_SCALE, PLAYER_SCALE);
	this->player.setOrigin( this->player.getGlobalBounds().width / 2 , this->player.getGlobalBounds().height / 2 );

	this->grounded = false;
	this->attack = false;
	this->receviedHit = false;
	this->health = 100.f;
	this->moveX = 0.f;
	this->moveY = 0.f;

	this->idleAnim = new Animation(texture, true, PLAYER_JUMP_ANIM_SPEED, {56,56}, {6, 0});
	this->runningAnim = new Animation(texture, true, PLAYER_RUN_ANIM_SPEED, {56,56}, {7, 2});
	this->attackAnim = new Animation(texture, true, PLAYER_ATTACK_ANIM_SPEED, {56,56}, {5, 1});
	this->jumpAnim = new Animation(texture, false , PLAYER_JUMP_ANIM_SPEED, {56,56}, { 7, 3 });
	this->fallAnim = new Animation(texture, false, PLAYER_FALL_ANIM_SPEED, {56,56}, { 5, 4 });

}

void Player::update(float deltaTime, std::vector<Enemy*> &enemies) {

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

	//this->velocity.x = this->velocity.x * this->speed;
	if (this->moveX < 0.f){
		this->player.setScale(-PLAYER_SCALE, PLAYER_SCALE);
	}
	else if (this->moveX > 0.f) {
		this->player.setScale(PLAYER_SCALE, PLAYER_SCALE);
	}



	// animation state
	if (this->attackAnim->animationFinished) {
		this->attack = false;
		this->attackAnim->animationFinished = false;
		this->collisionAttack(enemies);
	}

	if (this->attack) {
		this->attackAnim->update(deltaTime, this->player);
	}
	else if (velocity.y != 0.f) {
		if (velocity.y < 0.f) {
			this->jumpAnim->update(deltaTime, this->player);
		}
		else {
			this->fallAnim->update(deltaTime, this->player);
		}
	}
	else if (this->moveX != 0.f) {
		this->runningAnim->update(deltaTime, this->player);
	}

	else if (this->velocity.x == 0.f && this->velocity.y == 0.f) {
		this->idleAnim->update(deltaTime, this->player);
	}
	//Animation::update(deltaTime, this->player);
	this->player.move(this->velocity * deltaTime);

	this->window->draw(this->player);

}

void Player::handleInput(sf::Event event) {

	if (event.type == sf::Event::KeyPressed) {

		switch (event.key.code) {


		case sf::Keyboard::Space: {
			if (this->grounded) {
				this->moveY = -1.0f;
				this->attack = false;
			}

			break;
		}

		case sf::Keyboard::D: {
			this->moveX = 1.0f;
			this->attack = false;
			break;
		}


		case sf::Keyboard::A: {
			this->moveX = -1.0;
			this->attack = false;
			break;
		}


		}

	}



	if (event.type == sf::Event::KeyReleased) {

		switch (event.key.code) {


		case sf::Keyboard::Space: {
			this->moveY = 0.0f;
			break;
		}


			case sf::Keyboard::D: {
				this->moveX = 0.f;
				break;
			}


			case sf::Keyboard::A: {
				this->moveX = 0.f;
				break;
			}

		}

	}

	if (event.type == sf::Event::MouseButtonReleased) {
		this->attack = false;
	}
	
	if (event.type == sf::Event::MouseButtonPressed) {
		if(this->grounded)
			this->attack = true;
	}
	
}


void Player::collisionGround(std::vector<std::vector<Tile>> tiles) {

	float x = floor(this->player.getPosition().x / (TILE_SIZE * TILE_SCALE));
	//float y = floor(this->player.getPosition().y / (TILE_SIZE * TILE_SCALE));
	/*y = (tiles.size() - y);*/
	//std::cout << "not modifi " << y << std::endl;

	float floorStart = tiles.size() - 3;


	sf::FloatRect playerBound = this->player.getGlobalBounds();

	for (int y = 0; y < floorStart; y++) {

		if (tiles[y][x].sprite != nullptr) {
			if (tiles[y][x].sprite->getGlobalBounds().intersects(playerBound)) {
				this->grounded = true;
				return;
			}
		
		}
	}

	this->grounded = false;

}


void Player::collisionAttack(std::vector<Enemy*> enemies) {


	for (int i = 0; i < enemies.size(); i++) {
		if (!enemies[i]->isEnabled()) continue;

		sf::FloatRect playerBound = this->player.getGlobalBounds();

		

		float x = playerBound.width / 2.0;
		playerBound.left += x;
		playerBound.width = abs(playerBound.width - ((1.9 * x)));

		if (playerBound.intersects(enemies[i]->getEnemy().getGlobalBounds())) {
			//if (this->attack) {
			if (enemies[i]->hit()) {
				enemies.erase(enemies.begin() + i, enemies.begin() + i);
				enemies[i]->getEnemy().setColor(sf::Color::Black);
				std::cout << "Enemy killed";
			}
			return;
		}
		
	}


}


bool Player::hit() {
	this->receviedHit = true;
	this->health -= 20.f;
	std::cout << "Player Health " << this->health << std::endl;
	return this->health <= 0.f;
}
