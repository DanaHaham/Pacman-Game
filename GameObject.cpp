#include "GameObject.h"
#include "Novice.h"
#include "Keyboard.h"
#include "Best.h"
#include "Good.h"

void GameObject::setMovement(const MovementStrategy::Movment& movementKind, Position* pacPos)
{
	// Create a new movment acording to the given kind of movment
	switch (movementKind)
	{
	case MovementStrategy::Movment::NOVICE:
	{
		movement = new Novice(this);
		break;
	}
	case MovementStrategy::Movment::GOOD:
	{
		movement = new Good(this, pacPos);
		break;
	}
	case MovementStrategy::Movment::BEST:
	{
		movement = new Best(this, pacPos);
		break;
	}
	case MovementStrategy::Movment::KEYBOARD:
	{
		movement = new Keyboard(this);
		break;
	}
	}
}

void GameObject::move()
{
	movement->move();
}

void GameObject::init(bool isPause)
{
	// If the game isnt paused, reset the object
	if (!isPause)
	{
		// Delete the last position
		pos.draw(pGameBoard->get(pos));

		// Init the position
		pos = initPos;
	}

	// Draw the object in the init position
	pos.draw(symbol);
}

GameObject& GameObject::operator= (const GameObject& object)
{
	// To avoid destructive self assignment
	if (&object != this)
	{
		pos = object.pos;
		symbol = object.symbol;
		initPos = object.initPos;
		pGameBoard = object.pGameBoard;

		delete movement;
		movement = object.movement->clone(this);
		*movement = *object.movement;
	}
	return *this;
}



