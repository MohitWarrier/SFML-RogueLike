#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H
class GameTile
{
    public:
        bool isPassable;
        bool isExit;
        sf::Vector2f position;
        sf::Texture texture;
        std::optional<sf::Sprite> sprite;

        GameTile(std::string, float, float, bool, bool);
        bool setUpSprite(std::string);

};
#endif 