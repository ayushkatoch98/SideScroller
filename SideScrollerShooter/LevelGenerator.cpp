#include "LevelGenerator.h"
#include "Global.h"
#include <iostream>
// 0 = blank
// 1 = floor

std::vector<std::vector<std::string>> level1  {
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	{ "BLANK", "BLANK", "BLANK", "BLANK",  "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "FLOOR_2", "FLOOR_2", "FLOOR_2", "FLOOR_2", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", "BLANK", },
	
	{ "FLOOR_1","FLOOR_1","FLOOR_2","FLOOR_2","FLOOR_2","FLOOR_2","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","BLANK","BLANK","BLANK","BLANK","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1","FLOOR_1_BORDER_RIGHT"},
	{ "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "BLANK", "BLANK", "BLANK", "BLANK", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" },
	{ "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "BLANK", "BLANK", "BLANK", "BLANK", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" },
	{ "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "BLANK", "BLANK", "BLANK", "BLANK", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT", "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" , "DIRT" },
};




LevelGenerator::LevelGenerator(sf::RenderWindow &window, sf::Texture *floorTexture) {

	this->level = 0;
	this->window = &window;
	
	this->floorTex = floorTexture;
	this->map.resize(level1.size());
	this->loadMap();
}




void LevelGenerator::loadMap() {
	
	for (int i = level1.size() - 1; i >= 0; i--) {
		
		std::vector<Tile> cols;
		this->map[i] = cols;

		for (int j = 0; j < level1[i].size(); j++) {
			
			int x = j * TILE_SIZE * TILE_SCALE;
			//int y = SCREEN_HEIGHT - (level1.size() - i) * TILE_SIZE * TILE_SCALE;
			int y = TILE_SIZE * TILE_SCALE * i;

			sf::Sprite* sprite;
			
			if (this->tileProperties.find(level1[i][j]) != this->tileProperties.end()) {
				sprite = new sf::Sprite();
				sprite->setTexture(*this->floorTex);
				sprite->setPosition(sf::Vector2f(x, y));
				sprite->setScale(TILE_SCALE, TILE_SCALE);
				sprite->setTextureRect(this->tileProperties[level1[i][j]].getIntRect());

			}
			
			else {
				sprite = nullptr;
			}

			this->map[i].push_back(Tile(level1[i][j], sprite));

		}
	}

}

void LevelGenerator::update(float deltaTime) {

	int rows = level1.size();
	int count = 0;

	float xx;
	float yy;

	sf::Vector2f check;
	sf::Vector2f check2;
	sf::FloatRect visibleArea;

	for (int i = 0; i < this->map.size(); i++) {
		

		for (int j = 0; j < this->map[i].size(); j++) {

			if (this->map[i][j].sprite == nullptr) continue;
		
			xx = this->window->getView().getCenter().x - (SCREEN_WIDTH / 2.0);
			yy = this->window->getView().getCenter().y - (SCREEN_HEIGHT / 2.0);
			
			visibleArea = { xx, yy, SCREEN_WIDTH, SCREEN_HEIGHT };
			
			check = { this->map[i][j].sprite->getPosition().x + (TILE_SCALE * TILE_SIZE) , this->map[i][j].sprite->getPosition().y};

			check2 = { this->map[i][j].sprite->getPosition().x - (TILE_SCALE * TILE_SIZE) , this->map[i][j].sprite->getPosition().y };
			
			if (!visibleArea.contains(check) && !visibleArea.contains(check2)) {
				continue;
			}


			this->window->draw(*this->map[i][j].sprite);
		
		}

	}

}