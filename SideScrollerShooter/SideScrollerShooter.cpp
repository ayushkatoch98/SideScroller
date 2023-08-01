#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.h"
#include "Camera.h"
#include "LevelGenerator.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"

sf::Texture* loadTexture(std::string filename) {
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile(filename)) {
        std::cout << "Unable to load texture " << filename << std::endl;
    }
    return texture;
}

sf::Font* loadFont(std::string filename) {
    sf::Font* font = new sf::Font();
    if (!font->loadFromFile(filename)) {
        std::cout << "Unable to load font " << filename << std::endl;
    }
    return font;
}


int main() {


    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
    window.setPosition(sf::Vector2i(0.f, 0.f));

    bool gameOver = false;

    // loading textures
    sf::Texture* floorTex = loadTexture("./Images/oak_woods_tileset.png");
    sf::Texture* playerTex = loadTexture("./Images/character/char_blue.png");
    sf::Texture* bgCloseTex = loadTexture("./Images/background/background_layer_3.png");
    sf::Texture* bgMiddleTex = loadTexture("./Images/background/background_layer_2.png");
    sf::Texture* bgFarTex = loadTexture("./Images/background/background_layer_1.png");
    sf::Texture* lampTex = loadTexture("./Images/decorations/lamp.png");
    sf::Texture* signTex = loadTexture("./Images/decorations/sign.png");

    std::vector<sf::Texture*> decorationTex = { lampTex, signTex };
    
    // loading font
    sf::Font* font = loadFont("./valorax.otf");

    // enemies 
    std::vector<Enemy*> enemies;

    // initalizing objects
    Camera camera;
    LevelGenerator levelGenerator(window, floorTex);
    Player player(window, playerTex, font);
    Background bgClose(window, bgCloseTex, 90.f, 0.f);
    Background bgMiddle(window, bgMiddleTex, 90.f, 0.f);
    Background bgFar(window, bgFarTex, 90.f, 0.f);
    


    enemies.push_back(new Enemy(window, playerTex, player, { SCREEN_WIDTH / 2.f, 10.f }));
   /* enemies.push_back(new Enemy(window, playerTex, player, { 400.f, 100.f }));
    enemies.push_back(new Enemy(window, playerTex, player, { 500.f, 100.f }));
    enemies.push_back(new Enemy(window, playerTex, player, { 600.f, 100.f }));
    enemies.push_back(new Enemy(window, playerTex, player, { 700.f, 100.f }));*/

    // text
    sf::Text text;
    text.setFont(*font);
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::Red);


    sf::Clock clock;
    float dt;

    window.setFramerateLimit(60u);

    while (window.isOpen()){

        dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();

            player.handleInput(event);

        }

        

        window.clear();

        if (gameOver) {
            window.setView(window.getDefaultView());
            text.setString("Game Over!");
            text.setCharacterSize(40);
            //text.setPosition(300.f, 300.f);
            window.draw(text);

            window.display();
            continue;
        }

        window.setView(camera.get());


        camera.update(dt, player.getPlayer());
        bgFar.update(dt, player.getVelocity());
        bgMiddle.update(dt, player.getVelocity());
        bgClose.update(dt, player.getVelocity());
        levelGenerator.update(dt);
        
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->collisionGround(levelGenerator.map);
            enemies[i]->update(dt);
        }
        
        player.collisionGround(levelGenerator.map);
        player.update(dt, enemies);

        
        window.setView(window.getDefaultView());
        text.setString("Health: " + std::to_string(player.getHealth()));
        window.draw(text);

        if (player.getHealth() <= 0) gameOver = true;

        window.setView(camera.get());
        window.display();
    }

    // freeing all resources
    camera.~Camera();
    levelGenerator.~LevelGenerator();
    bgFar.~Background();
    bgMiddle.~Background();
    bgClose.~Background();
    player.~Player();

    for (int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    delete floorTex;
    delete playerTex;
    delete bgCloseTex;
    delete bgMiddleTex;
    delete bgFarTex;

    return 0;
}