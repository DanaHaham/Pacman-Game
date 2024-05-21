 #ifndef MENU_H
#define MENU_H

#include <iostream>
#include "io_utils.h"
#include "Game.h"
#include "MovementStrategy.h"

class Menu
{
    // Consts  
    const enum {START = 1, SPESCIFIC_SCREEN = 2, INSTRUCTIONS = 8, EXIT = 9, BACK = 2};

    // Functions

    // Handle user input. Acordding to it, active the menu
    bool pressKey()const;

    // Present the instructions and keys and after go back to the menu
    void instructionsAndKeys()const;

    // Start the pacman game. When its over, go back to the menu
    void startGame(bool isSpescific)const;

    // Clean the window and print the menu
    void print() const;

    // Clean the window and print the 
    void printInstructionsAndKeys()const;

    // Present the possible levels of the game and return the one thar the user chose  
    MovementStrategy::Movment chooseLevel()const;

    // Check if the user choose the wanted level of the game and return whether or not it was choosen and the scaned value (ByRef)
    bool scanLevel(MovementStrategy::Movment& scan)const;

public:

    // Run menu: print and handle the user input
    void run();
};

#endif
