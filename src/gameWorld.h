#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


enum class GameState { Playing, Victory, Defeat };
class GameWorld
{
    private:
        sf::Vector2i exitPosition;
        sf::Vector2i playerPosition;
        std::vector <sf::Vector2i> enemyPositions;
        void setUpEnemyPositions();
        void setUpTiles();
        void redrawSprites();
        bool checkIfPositionFree(sf::Vector2i);
        std::vector<sf::Vector2i> getFreeCoords(sf::Vector2i);
        void moveEnemies();
        bool checkIfReachedExit();
        bool checkIfHitEnemy();
        void checkCollisionsAndMoveEnemies();

    public:
        GameState state = GameState::Playing;
        std::vector <std::vector<GameTile *>> tiles;
        int gridLength;
        GameWorld();
        void setUpInitialState();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
};

#endif