#ifndef GOOD_H
#define GOOD_H

#include "MovementStrategy.h"
#include "Best.h"
#include "Novice.h"

// Forward declaration
class GameObject;

class Good : public Best
{
	// Data members
	bool isBest;
	int randSteps, changeMove;

	Novice noviceMovement = {object};

public:

	// Functions

	// C-tor
	Good(GameObject* _object, Position* _pacPos) : Best(_object, _pacPos)
	{
		init();
	}

	// Move the object 
	void move() override;

	// Create and return a clone of the Good
	Good* clone(GameObject* _object) const override
	{
		return new Good(_object, pacPos);
	}

	// Set the direction acordding to random
	void setRandDirection()
	{
		direction = Direction(rand() % 4);
	}

	// Init the data members to best movment
	void init()
	{
		isBest = true;
		steps = 0;

		// Rand the number of steps utill random (~20)
		changeMove = ((rand() % 10) + 20);
	}
};

#endif 
