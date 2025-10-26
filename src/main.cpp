
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameWorld.h"

int main()
{
    unsigned int windowHeight = 800;
    unsigned int windowWidth = 800;
    std::string gameTitle = "Roguelike!";

    // SFML 3.x requires this syntax:
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(windowWidth, windowHeight)), gameTitle);
    sf::Texture texture;

    GameWorld gameWorld = GameWorld();

    if (!texture.loadFromFile("Assets/enemy.png"))
    {
        std::cerr << "Texture failed to load" << std::endl;
        return 0;
    }

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        // Poll events (returns std::optional<sf::Event>)
        // auto lets compiler decide what type event is
        // simplifies code - instead of std::optional<sf::Event> event = window.pollEvent();
        while (auto event = window.pollEvent())
        {
            // Check if event is a Close event
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyEvent->scancode) 
                {
                    case sf::Keyboard::Scan::Left:
                        gameWorld.moveLeft();
                        break;
                    case sf::Keyboard::Scan::Right:
                        gameWorld.moveRight();
                        break;
                    case sf::Keyboard::Scan::Up:
                        gameWorld.moveUp();
                        break;
                    case sf::Keyboard::Scan::Down:
                        gameWorld.moveDown();
                        break;
                    default:
                        break;
                }
            }

        }

        window.clear();
        
        for (int i = 0; i < gameWorld.gridLength; i++)
        {
            for (int j = 0; j < gameWorld.gridLength; j++)
            {
                if (gameWorld.tiles[i][j] && gameWorld.tiles[i][j]->sprite.has_value()) 
                {
                    window.draw(*(gameWorld.tiles[i][j]->sprite));
                }
                else
                {
                    std :: cerr <<"Error"<< std::endl;
                }
            }
        }

        window.display();
    }
    return 0;
}