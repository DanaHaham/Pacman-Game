#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include "io_utils.h"
#include "MovementStrategy.h"

// Forward declaration
class Board;

class Position
{
private:

	// Data members
	int x, y;

	// Functions
	
	// Create new position acorrding to the given direction and this position and return it.
	Position createNew(MovementStrategy::Direction dir);

	// Update this position if it pass through one of the tunnels
	void passTunnel(Board* pGameBoard);

public:

	// C-tor
	Position(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}

	// Copy constructor
	Position(const Position& other)
	{
		*this = other;
	}

	// Init the position - set the x & y
	void init(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	
	// Get the data member x
	int getX() const
	{
		return x;
	}

	// Get the data member y
	int getY() const
	{
		return y;
	}

	// Check if the given position is equal to this position
	bool isEqual(const Position& pos) const
	{
		return (pos.getX() == x && pos.getY() == y);
	}

	// Print the given charecter in this position
	void draw(char ch) const
	{
		gotoxy(x, y);
		std::cout << ch;
		std::cout << std::flush;
	}

	// Change this position acordding to the given direction, if it is possible move. Return if it move.
	bool move(MovementStrategy::Direction dir, MovementStrategy* pMovement, Board* pGameBoard);

	// Operator <
	bool operator<(const Position& other) const;
};

#endif