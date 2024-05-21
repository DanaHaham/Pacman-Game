#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "MovementStrategy.h"

// Forward declaration
class GameObject;

class Keyboard : public MovementStrategy
{
	// Consts
	const char arrowKeys[10] = { 'w', 'x', 'a', 'd', 's', 'W', 'X', 'A', 'D', 'S' };

	// Data members
	char key;

public:

	// Functions 
	
	// C-tor
	Keyboard(GameObject* _object) : MovementStrategy(_object)
	{
		passTunnel = true;
		init();
	}

	// Set the direction acordding to the key
	void setDirection() override;

	// Move the object 
	void move() override;

	// Create and return a clone of the Keyboard
	Keyboard* clone(GameObject* _object) const override
	{
		return new Keyboard(_object);
	}

	// Init the movment of the object
	void init()
	{
		direction = Direction::STOP;
	}

	// Set the data member key
	void setKey(char _key)
	{
		key = _key;
	}

};


#endif 
