#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include "Position.h"
#include "Board.h"
#include "MovementStrategy.h"

class GameObject
{
protected: 

	// Data members
	Position pos, initPos;
	char symbol;

	MovementStrategy* movement;
	Board* pGameBoard;

public:

	// Functions

	// C-tor
	GameObject(Board* _pGameBoard)
	{
		movement = nullptr;
		pGameBoard = _pGameBoard;
	}

	// Copy constructor
	GameObject(const GameObject& other)
	{
		movement = nullptr;
		*this = other;
	}

	// Get the data member pos ByRef
	Position& getPosition()
	{
		return pos;
	}

	// Get the data member pGameBoard
	Board* getBoard() const 
	{
		return pGameBoard;
	}

	// Get the data member symbol
	char getSymbol()const 
	{
		return symbol;
	}

	// Set the data member pGameBoard
	void setBoard(Board* _pGameBoard)
	{
		pGameBoard = _pGameBoard;
	}

	// Set the data member initPos
	void setInitPos(Position _initPos)
	{
		initPos = _initPos;
	}

	// Get the data member movment
	void setMovement(const MovementStrategy::Movment& movementKind, Position* pacPos = nullptr);

	// Move the object acordding to its strategy
	virtual void move();

	// Init the position of the object in the board
	virtual void init(bool isPause);

	// Operator comparison
	GameObject& operator= (const GameObject& object);

	// Destructor
	~GameObject()
	{
		delete movement;
	}

};

#endif

