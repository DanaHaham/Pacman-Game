#include "MovementStrategy.h"
#include "GameObject.h"

bool MovementStrategy::isValidMove(const Position& pos)
{
	bool isValid = true;

	if (!object->getBoard()->isWall(pos))
	{
		// Is tunnel and the movment dont allow pass tunnels
		if (object->getBoard()->isTunnel(pos) && !passTunnel)
		{
			isValid = false;
		}
	}

	// Is wall
	else
	{
		isValid = false;
	}

	return isValid;
}

MovementStrategy& MovementStrategy::operator= (const MovementStrategy& other)
{
	// To avoid destructive self assignment
	if (&other != this)
	{
		passTunnel = other.passTunnel;
		direction = other.direction;
	}

	return *this;
}

void MovementStrategy::draw(char ch)
{
	object->getPosition().draw(ch);
}