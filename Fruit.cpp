#include "Fruit.h"

Fruit::Fruit(Board* _pGameBoard) : GameObject(_pGameBoard)
{
	// Rand a number betwwen 5 to 9
	value = ((rand() % 5) + 5);
	symbol = '0' + value;

	// Rand the duration of the fruit (50-80 steps)
	duration = ((rand() % 30) + 50);

	// Rand the step that the fruit will appearance (10 - 1500 steps)
	appearance = ((rand() % 1500) + 10);

	// Set movement
	setMovement(MovementStrategy::Movment::NOVICE);

	// The fruit isnt apears on the board yet
	isAppear = false;
}

bool Fruit::updateDuration()
{
	duration--;

	if (duration == 0)
	{
		pos.draw(pGameBoard->get(pos));
		return true;
	}

	return false;
}

void Fruit::init(bool isPause)
{
	if (isAppear)
	{
		if (!isPause)
		{
			// Rand position until get one that isnt a wall
			do
			{
				pos.init(rand() % pGameBoard->getWidth(), rand() % pGameBoard->getHeight());
			} while (!movement->isValidMove(pos));
		}

		pos.draw(symbol);
	}
}

void Fruit::appear(int steps)
{
	if (appearance == steps)
	{
		isAppear = true;
		init();
	}
}