#ifndef GHOST_H
#define GHOST_H

#include <iostream>
#include "GameObject.h"

class Ghost : public GameObject
{
public:

	// Functions

	// C-tor
	Ghost(MovementStrategy::Movment _movement, Board* _pGameBoard, Position* _pacPos) : GameObject(_pGameBoard)
	{
		symbol = Board::objectSymbol[(int)Board::Objects::GHOST];
		setMovement(_movement, _pacPos);
	}

};

#endif