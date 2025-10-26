# Roguelike Grid Game (SFML 3.x)

A simple tile-based roguelike game made in C++ using SFML 3.
Dodge the enemies and make it to the exit!

## 🎮 Gameplay Demo

**Defeat & Retry**
![Defeat GIF](Assets/defeat.gif)

---

**Victory**
![Victory GIF](Assets/victory.gif)

## Features

- Player movement on an 8x8 grid
- Randomized enemy movement
- Win by reaching the exit, lose if touched by an enemy
- Game over UI, press SPACE to restart

## Controls

- Arrow keys: Move
- SPACE: Restart after game over

## Build Instructions

1. Clone repo, make sure you have SFML 3.x installed. Install otherwise
2. Move to root of project directory
3. Run g++ src/main.cpp src/gameTile.cpp src/gameWorld.cpp -o main.exe -IC:\SFML\include -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system in terminal (windows)
4. Make sure assets are in correct folder
