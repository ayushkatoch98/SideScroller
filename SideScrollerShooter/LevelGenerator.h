#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"


class DefaultTiles {
	
public:
	sf::Vector2i cords; // index
	sf::Vector2i size;
	std::string type;

	DefaultTiles() {
		std::cout << "IDK WHY THIS IS RUNNING" << std::endl;
	}
	DefaultTiles(sf::Vector2i cords, sf::Vector2i size, std::string type) {
		this->cords = cords;
		this->size = size;
		this->type = type;
	}

	DefaultTiles(int x, int y, int width, int height, std::string type) {
		this->cords.x = x;
		this->cords.y = y;
		this->size.x = width;
		this->size.y = height;
		this->type = type;
	}

	sf::IntRect getIntRect() {
		return sf::IntRect(this->cords.x * this->size.x, this->cords.y * this->size.y, this->size.x, this->size.y);
	}
};

class Tile {

public:
	std::string type;
	sf::Sprite *sprite;

	Tile(std::string type, sf::Sprite *sprite) {
		this->type = type;
		this->sprite = sprite;
	}
};

class LevelGenerator{

private:

	std::map<std::string, DefaultTiles> tileProperties = {
		{ "FLOOR_1" , DefaultTiles(1,0,TILE_SIZE, TILE_SIZE, "floor")},
		{ "FLOOR_2" , DefaultTiles(6,0,TILE_SIZE, TILE_SIZE, "floor")},
		{ "FLOOR_1_BORDER_LEFT" , DefaultTiles(0,0,TILE_SIZE, TILE_SIZE, "floor")},
		{ "FLOOR_1_BORDER_RIGHT" , DefaultTiles(3,0,TILE_SIZE, TILE_SIZE, "floor")},
		{ "DIRT" , DefaultTiles(1,1,TILE_SIZE, TILE_SIZE, "floor")},


	};

	unsigned short level;
	
	
	sf::Texture *floorTex;
	sf::RenderWindow* window;
	sf::View* camera;

public:

	std::vector<std::vector<Tile>> map;

public:

	void update(float deltaTime);

	LevelGenerator(sf::RenderWindow& window, sf::Texture* floorTexture);

private:


	void loadMap();
};

