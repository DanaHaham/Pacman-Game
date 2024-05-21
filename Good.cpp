#include "Good.h"
#include "GameManager.h"

void Good::move() 
{
	// Every ~20 step, change the movment to random
	if (steps % changeMove == 0 && isBest)
	{
		randSteps = 0;
		isBest = false;
		setRandDirection();
	}

	// Move the object
	if (isBest)
	{
		Best::move();
	}

	else
	{
		noviceMovement.move();

		// After 5 steps, back to best movemebt
		if (++randSteps == 5)
		{
			init();
		}
	}

	steps++;
}
