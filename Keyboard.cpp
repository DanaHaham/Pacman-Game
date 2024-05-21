#include "Keyboard.h"
#include "GameObject.h"

void Keyboard::setDirection() 
{
	bool isFound = false;

	// If the pressed key is an arrow, change the direction of the object
	for (int i = 0; i < sizeof(arrowKeys) / sizeof(arrowKeys[0]) && !isFound; i++)
	{
		if (key == arrowKeys[i])
		{
			direction = Direction(i % (sizeof(arrowKeys) / 2));
			isFound = true;
		}
	}
}

void Keyboard::move() 
{
	// Move the object (in case it is not need to stop)
	if (direction != Direction::STOP)
	{
		draw(object->getBoard()->get(object->getPosition()));

		if (!object->getPosition().move(direction, this, object->getBoard()))
		{
			direction = Direction::STOP;
		}

		draw(object->getSymbol());
	}
}

