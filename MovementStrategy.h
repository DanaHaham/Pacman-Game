#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

#include <iostream>

// Forward declaration
class GameObject;
class Position;

class MovementStrategy
{
public:

	// Consts
	const enum class Direction { UP, DOWN, LEFT, RIGTH, STOP };
	const enum class Movment{NOVICE, GOOD, BEST, KEYBOARD};

protected:

	// Data members
	bool passTunnel;
	int steps;
	Direction direction;
	GameObject* object;

public:

	// Functions

	// C-tor
	MovementStrategy(GameObject* _object)
	{
		object = _object;
		passTunnel = false;
		steps = 0;
	}

	// Check if the given position is valid acording to the current board
	bool isValidMove(const Position& pos);

	// Draw in the position of the current object the given char
	void draw(char ch);

	// Operator comparison
	MovementStrategy& operator= (const MovementStrategy& other);

	// Move the object member
	virtual void move() = 0;

	// Set the direction acording to the relevent algorithm
	virtual void setDirection() = 0;

	// Create and return a clone of the movment
	virtual MovementStrategy* clone(GameObject* _object) const = 0;	
};


#endif

