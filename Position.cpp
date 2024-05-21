#include "Position.h"
#include "MovementStrategy.h"
#include "Board.h"

bool Position::move(MovementStrategy::Direction dir, MovementStrategy* pMovement, Board* pGameBoard)
{
	// Change the temporary position acorrding to the given direction
	Position temp = createNew(dir);

	// Check if the new position is legal
	if (pMovement->isValidMove(temp))
	{
		*this = temp;
		passTunnel(pGameBoard);

		return true;
	}

	return false;
} 

Position Position::createNew(MovementStrategy::Direction dir)
{
	Position newPos(*this);

	switch (dir)
	{
	case MovementStrategy::Direction::UP:
		newPos.y--;
		break;

	case MovementStrategy::Direction::DOWN:
		newPos.y++;
		break;

	case MovementStrategy::Direction::LEFT:
		newPos.x--;
		break;

	case MovementStrategy::Direction::RIGTH:
		newPos.x++;
		break;
	}

	return newPos;
}

void Position::passTunnel(Board* pGameBoard)
{
	// Up borders
	if (y < 0)
	{
		y = pGameBoard->getHeight() - 1;
	}

	// Down borders
	else if (y > pGameBoard->getHeight() - 1)
	{
		y = 0;
	}

	// Right borders
	if (x < 0)
	{
		x = pGameBoard->getWidth() - 1;
	}

	// Left borders
	else if (x > pGameBoard->getWidth() - 1)
	{
		x = 0;
	}
}

bool Position::operator<(const Position& other) const
{
	if (x < other.x)
		return true;

	if (x > other.x)
		return false;

	return y < other.y;
}



