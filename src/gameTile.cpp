#include <iostream>
#include "gameTile.h"

GameTile :: GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
    if (!setUpSprite(textureName))
    {
        return;
    }
    position = sf::Vector2f(x,y);
    sprite->setPosition(position);
    isPassable = passable;
    isExit = exit;
}

bool GameTile::setUpSprite(std::string textureName)
{
    if (!texture.loadFromFile(textureName))
    {
        std::cerr << "Texture failed to load" << std::endl;
        return false;
    }
    texture.setSmooth(true);

    // Destroy any existing sprite 
    sprite.reset(); 

    // Create a new sprite, always fresh
    sprite.emplace(texture);

    sprite->setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(50, 50)));
    sprite->setScale(sf::Vector2f(2,2));
    sprite->setPosition(position);

    return true;
}
