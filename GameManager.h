#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <vector>
#include "Pacman.h"
#include "Ghost.h"
#include "Board.h"
#include "Fruit.h"

// Forward declaration
class Game;

class GameManager
{
    // Consts
    const enum class Keys { ESC = 27 };
    const enum class Speeds { GOHST = 2, FRUIT = 5 };
    
    // Data members
    int breadcrumbs, steps;
    bool isPause;

    Pacman pacman;
    std::vector <Ghost> ghosts;
    std::vector <Fruit> fruits;

    Game* pGame;

    // Functions

    // Handle the creation and initial setting of the objects (pacman, ghosts, fruits)
    void createObjects();

    // New step of the game start - make a move for all the objects in the game and update the game acordding to thats moves
    void step();

    // Update the game acording to the rules and the movments of the objects
    void updateGame();

    // In case of press key, update game (move of pacman or pause game)
    void pressKey();

    // If the pacman and one of the ghosts collides, the user lose life and reset game  
    void isPacmanGhostCollide();

    // If the pacman eat one of the fruits, increase the score and delete the fruit
    void isPacmanEatFruit();

    // If one of the fruits and one of the ghosts collides, the user lose life and reset game  
    void isFruitGhostCollide();

    // If the pacman eat breadcrumb, increase the score and delete the breadcrumb
    void isPacmanEatBreadcrumbs();

    // Remove the fruit in the given index
    void removeFruit(int index)
    {
        fruits.erase(fruits.begin() + index);
    }


public:

    // C-tor
    GameManager(Game* _pGame);

    // Init the game in case of collide or pause
    void init();

    // Play the game and make the moves until lose or win
    void play();

};

#endif 
