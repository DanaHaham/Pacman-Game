#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
#include "GameObject.h"
#include "Keyboard.h"

// Forward declaration
class GameManager; 

class Pacman : public GameObject
{
public:

	// Functions

	// C-tor
	Pacman(Board* _pGameBoard) : GameObject(_pGameBoard)
	{
		symbol = Board::objectSymbol[(int)Board::Objects::PACMAN];
		setMovement(MovementStrategy::Movment::KEYBOARD);
	}

	// Init the pacman position and start movment
	void init(bool isPause);

	// Set the direction of the pacman acording to the given key
	void setDirection(char key);

};

#endif