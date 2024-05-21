#ifndef BEST_H
#define BEST_H

#include "MovementStrategy.h"
#include <queue>
#include <vector>
#include <map>
#include "Position.h"

// Forward declaration
class GameObject;
class Pacman;

class Best : public MovementStrategy
{
protected:

	// Data members
	Position* pacPos, nextPos;

private:

	// Functions

	// Get all the valid neighbors of the given position in the current board
	std::vector<Position> getValidNeighbors(Position pos);

public:

	// C-tor
	Best(GameObject* _object, Position* _pacPos) : MovementStrategy(_object), pacPos(_pacPos){}

	// Move the object 
	void move() override;

	// Set the direction acordding to bfs algorithm - chase the pacman
	void setDirection() override;

	// Create and return a clone of the Best
	Best* clone(GameObject* _object) const override
	{
		return new Best(_object, pacPos);
	}

};

#endif 
