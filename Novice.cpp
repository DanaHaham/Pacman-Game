#include "Novice.h"
#include "GameObject.h"
#include "GameManager.h"

void Novice::move()
{
	draw(object->getBoard()->get(object->getPosition()));

	// After 20 steps, change direction
	if (steps % 20 == 0)
	{
		setDirection();
	}

	// As long as the movment is in colliding with a wall, rand another direction
	while (!object->getPosition().move(direction, this, object->getBoard()))
	{
		setDirection();
	}

	draw(object->getSymbol());

	steps++;
}