#ifndef NOVICE_H
#define NOVICE_H

#include "MovementStrategy.h"

// Forward declaration
class GameObject;

class Novice : public MovementStrategy
{
public:

	// Functions

	// C-tor
	Novice(GameObject* _object) : MovementStrategy(_object)
	{
		setDirection();
	}

	// Set the direction acordding to random
	void setDirection() override
	{
		direction = Direction(rand() % 4);
	}

	// Move the object 
	void move() override;

	// Create and return a clone of the Novice
	Novice* clone(GameObject* _object) const override
	{
		return new Novice(_object);
	}
};

#endif // !NOVICE_H
