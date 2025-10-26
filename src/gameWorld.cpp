#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "gameWorld.h"
#include "gameTile.h"

GameWorld::GameWorld()
{
    //hardcode grid size
    gridLength = 8;
    setUpInitialState();
}

// hardcode initial positions
void GameWorld::setUpInitialState()
{

    exitPosition = sf::Vector2i(1,0);
    // set intitial player position to bottom most right position of grid
    playerPosition = sf::Vector2i(gridLength-1,gridLength-1);
    setUpEnemyPositions();
    setUpTiles();
}

void GameWorld::setUpEnemyPositions()
{
    // clear any previous data in vector
    enemyPositions.clear();
    // hardcode enemy positions
    enemyPositions.push_back(sf::Vector2i(0,2));
    enemyPositions.push_back(sf::Vector2i(6,0));
    enemyPositions.push_back(sf::Vector2i(2,7));
}


void GameWorld::setUpTiles()
{
    std::string wall = "Assets/wall.png";
    std::string door = "Assets/door.png";
    std::string ground = "Assets/ground.png";
    std::string player = "Assets/player.png";
    std::string enemy = "Assets/enemy.png";

    tiles.clear();

    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile(wall, 0, 0, false, false));
    firstRow.push_back(new GameTile(door, 100, 0, true, true));
    firstRow.push_back(new GameTile(wall, 200, 0, false, false));
    firstRow.push_back(new GameTile(wall, 300, 0, false, false));
    firstRow.push_back(new GameTile(wall, 400, 0, false, false));
    firstRow.push_back(new GameTile(wall, 500, 0, false, false));
    firstRow.push_back(new GameTile(enemy, 600, 0, true, false));
    firstRow.push_back(new GameTile(wall, 700, 0, false, false));

    tiles.push_back(firstRow);


    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile(wall, 0, 100, false, false));
    secondRow.push_back(new GameTile(ground, 100, 100, true, false));
    secondRow.push_back(new GameTile(ground, 200, 100, true, false));
    secondRow.push_back(new GameTile(ground, 300, 100, true, false));
    secondRow.push_back(new GameTile(ground, 400, 100, true, false));
    secondRow.push_back(new GameTile(ground, 500, 100, true, false));
    secondRow.push_back(new GameTile(ground, 600, 100, true, false));
    secondRow.push_back(new GameTile(ground, 700, 100, true, false));

    tiles.push_back(secondRow);


    std::vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile(enemy, 0, 200, true, false));
    thirdRow.push_back(new GameTile(ground, 100, 200, true, false));
    thirdRow.push_back(new GameTile(ground, 200, 200, true, false));
    thirdRow.push_back(new GameTile(wall, 300, 200, false, false));
    thirdRow.push_back(new GameTile(ground, 400, 200, true, false));
    thirdRow.push_back(new GameTile(ground, 500, 200, true, false));
    thirdRow.push_back(new GameTile(wall, 600, 200, false, false));
    thirdRow.push_back(new GameTile(wall, 700, 200, false, false));

    tiles.push_back(thirdRow);
    

    std::vector<GameTile *> fourthRow;
    fourthRow.push_back(new GameTile(wall, 0, 300, false, false));
    fourthRow.push_back(new GameTile(ground, 100, 300, true, false));
    fourthRow.push_back(new GameTile(ground, 200, 300, true, false));
    fourthRow.push_back(new GameTile(wall, 300, 300, false, false));
    fourthRow.push_back(new GameTile(ground, 400, 300, true, false));
    fourthRow.push_back(new GameTile(ground, 500, 300, true, false));
    fourthRow.push_back(new GameTile(ground, 600, 300, true, false));
    fourthRow.push_back(new GameTile(wall, 700, 300, false, false));

    tiles.push_back(fourthRow);


    std::vector<GameTile *> fifthRow;
    fifthRow.push_back(new GameTile(wall, 0, 400, false, false));
    fifthRow.push_back(new GameTile(ground, 100, 400, true, false));
    fifthRow.push_back(new GameTile(ground, 200, 400, true, false));
    fifthRow.push_back(new GameTile(wall, 300, 400, false, false));
    fifthRow.push_back(new GameTile(wall, 400, 400, false, false));
    fifthRow.push_back(new GameTile(ground, 500, 400, true, false));
    fifthRow.push_back(new GameTile(ground, 600, 400, true, false));
    fifthRow.push_back(new GameTile(ground, 700, 400, true, false));

    tiles.push_back(fifthRow);


    std::vector<GameTile *> sixthRow;
    sixthRow.push_back(new GameTile(ground, 0, 500, true, false));
    sixthRow.push_back(new GameTile(ground, 100, 500, true, false));
    sixthRow.push_back(new GameTile(ground, 200, 500, true, false));
    sixthRow.push_back(new GameTile(wall, 300, 500, false, false));
    sixthRow.push_back(new GameTile(wall, 400, 500, false, false));
    sixthRow.push_back(new GameTile(ground, 500, 500, true, false));
    sixthRow.push_back(new GameTile(ground, 600, 500, true, false));
    sixthRow.push_back(new GameTile(ground, 700, 500, true, false));

    tiles.push_back(sixthRow);
    

    std::vector<GameTile *> seventhRow;
    seventhRow.push_back(new GameTile(wall, 0, 600, false, false));
    seventhRow.push_back(new GameTile(wall, 100, 600, false, false));
    seventhRow.push_back(new GameTile(ground, 200, 600, true, false));
    seventhRow.push_back(new GameTile(ground, 300, 600, true, false));
    seventhRow.push_back(new GameTile(ground, 400, 600, true, false));
    seventhRow.push_back(new GameTile(ground, 500, 600, true, false));
    seventhRow.push_back(new GameTile(wall, 600, 600, false, false));
    seventhRow.push_back(new GameTile(wall, 700, 600, false, false));

    tiles.push_back(seventhRow);

    
    std::vector<GameTile *> eighthRow;
    eighthRow.push_back(new GameTile(wall, 0, 700, false, false));
    eighthRow.push_back(new GameTile(wall, 100, 700, false, false));
    eighthRow.push_back(new GameTile(enemy, 200, 700, true, false));
    eighthRow.push_back(new GameTile(wall, 300, 700, false, false));
    eighthRow.push_back(new GameTile(wall, 400, 700, false, false));
    eighthRow.push_back(new GameTile(ground, 500, 700, true, false));
    eighthRow.push_back(new GameTile(ground, 600, 700, true, false));
    eighthRow.push_back(new GameTile(player, 700, 700, true, false));

    tiles.push_back(eighthRow);

}

void GameWorld::moveLeft()
{
    if (state != GameState::Playing)
    {
        return;
    }
    if(playerPosition.x == 0)
    {
        return;
    }
    if (!tiles[playerPosition.y][playerPosition.x-1] -> isPassable)
    {
        return;
    }

    tiles[playerPosition.y][playerPosition.x] -> setUpSprite("Assets/ground.png");
    playerPosition.x -= 1;
    checkCollisionsAndMoveEnemies();
}

void GameWorld::moveRight()
{
    if (state != GameState::Playing)
    {
        return;
    }
    if(playerPosition.x == gridLength-1)
    {
        return;
    }
    if (!tiles[playerPosition.y][playerPosition.x+1]->isPassable)
    {
        return;
    }

    tiles[playerPosition.y][playerPosition.x]->setUpSprite("Assets/ground.png");
    playerPosition.x += 1;
    checkCollisionsAndMoveEnemies();
}

void GameWorld::moveUp()
{
    if (state != GameState::Playing)
    {
        return;
    }
    if(playerPosition.y == 0)
    {
        return;
    }
    if (!tiles[playerPosition.y-1][playerPosition.x]->isPassable)
    {
        return;
    }

    tiles[playerPosition.y][playerPosition.x]->setUpSprite("Assets/ground.png");
    playerPosition.y -= 1;
    checkCollisionsAndMoveEnemies();
}

void GameWorld::moveDown()
{
    if (state != GameState::Playing)
    {
        return;
    }
    if(playerPosition.y == gridLength-1)
    {
        return;
    }
    if (!tiles[playerPosition.y+1][playerPosition.x]->isPassable)
    {
        return;
    }

    tiles[playerPosition.y][playerPosition.x]->setUpSprite("Assets/ground.png");
    playerPosition.y += 1;
    checkCollisionsAndMoveEnemies();
}


void GameWorld::redrawSprites()
{
    tiles[playerPosition.y][playerPosition.x] -> setUpSprite("Assets/player.png");
    for (int i = 0; i < enemyPositions.size(); i++)
    {
        sf::Vector2i currentEnemyPosition = enemyPositions[i];
        tiles[currentEnemyPosition.y][currentEnemyPosition.x] -> setUpSprite("Assets/enemy.png");
    }
}

bool GameWorld::checkIfPositionFree(sf::Vector2i pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x > gridLength-1 || pos.y > gridLength-1)
    {
        return false;
    }
    if (!tiles[pos.y][pos.x] -> isPassable)
    {
        return false;
    }
    if (tiles[pos.y][pos.x] -> isExit)
    {
        return false;
    }

    return true;
}

std::vector<sf::Vector2i> GameWorld::getFreeCoords(sf::Vector2i currentPosition)
{
    std::vector<sf::Vector2i> freePositions;
    std::vector<sf::Vector2i> allPositions;

    allPositions.push_back(sf::Vector2i(currentPosition.x-1,currentPosition.y));
    allPositions.push_back(sf::Vector2i(currentPosition.x-1,currentPosition.y-1));
    allPositions.push_back(sf::Vector2i(currentPosition.x,currentPosition.y-1));
    allPositions.push_back(sf::Vector2i(currentPosition.x+1,currentPosition.y-1));
    allPositions.push_back(sf::Vector2i(currentPosition.x+1,currentPosition.y));
    allPositions.push_back(sf::Vector2i(currentPosition.x+1,currentPosition.y+1));
    allPositions.push_back(sf::Vector2i(currentPosition.x,currentPosition.y+1));
    allPositions.push_back(sf::Vector2i(currentPosition.x-1,currentPosition.y+1));


    for (int i = 0; i < 8; i ++)
    {
        if (checkIfPositionFree(allPositions[i]))
        {
            freePositions.push_back(allPositions[i]);
        }
    }
    return freePositions;
}

void GameWorld::moveEnemies()
{
    // loop through every enemy and get its coords
    for (int i = 0; i < enemyPositions.size(); i++)
    {
        sf::Vector2i currentEnemyPosition = enemyPositions[i];
        std::vector<sf::Vector2i> freePositions = getFreeCoords(currentEnemyPosition);  
        // randomly select a free position and move enemy to that position
        int randomIndex = rand() % freePositions.size();
        sf::Vector2i newPosition = freePositions[randomIndex];
        tiles[currentEnemyPosition.y][currentEnemyPosition.x]->setUpSprite("Assets/ground.png");
        enemyPositions[i] = newPosition;

    }
}

bool GameWorld::checkIfReachedExit()
{
    return playerPosition.x == exitPosition.x && playerPosition.y == exitPosition.y;
}

bool GameWorld::checkIfHitEnemy()
{
    for (int i = 0; i < enemyPositions.size(); i++)
    {
        sf::Vector2i currentEnemyPos = enemyPositions[i];
        if (playerPosition.x == currentEnemyPos.x && playerPosition.y == currentEnemyPos.y)
        {
            return true;
        }
    }
    return false;
}

// function to call collision checks and sprite redrawing
void GameWorld::checkCollisionsAndMoveEnemies()
{
    if (checkIfReachedExit())
    {
        state = GameState::Victory; // instead of setUpInitialState()
        return;
    }
    moveEnemies();
    if (checkIfHitEnemy())
    {
        state = GameState::Defeat; // instead of setUpInitialState()
        return;
    }
    redrawSprites();
}