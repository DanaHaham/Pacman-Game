#include "Best.h"
#include "Board.h"
#include "Pacman.h"
#include "GameObject.h"

void Best::setDirection() 
{
	// Position to check (in the way to the pacman)
	std::queue<Position> queue;

	// Position that were visited
	std::vector<bool> visited(object->getBoard()->getWidth() * object->getBoard()->getHeight());

	// Map that contain the poistion that led to the key position (gave the data position as neighbor)
	std::map<Position, Position> parent;

	bool isPacmanFound = false;

	// Init the strat position 
	queue.push(object->getPosition());

	// As long as there is a position that dosent check
	while (!queue.empty() && !isPacmanFound)
	{
		// Access the first element
		Position current = queue.front();

		// Remove the first element from the queue
		queue.pop();

		// Found the pacman position
		if (pacPos->isEqual(current))
		{
			isPacmanFound = true;
		}
		else
		{
			// Get the neighboring positions
			std::vector<Position> neighbors = getValidNeighbors(current);

			for (const Position& neighbor : neighbors)
			{
				int indexNeighbor = neighbor.getY() * object->getBoard()->getWidth() + neighbor.getX();

				// Add neighbor to the search
				if (!visited[indexNeighbor])
				{
					queue.push(neighbor);
					visited[indexNeighbor] = true;
					parent[neighbor] = current;
				}
			}
		}
	}

	// Find the closet position to pacman
	nextPos = *pacPos;
	while (!parent[nextPos].isEqual(object->getPosition()))
	{
		nextPos = parent[nextPos];
	}
}

std::vector<Position> Best::getValidNeighbors(Position pos)
{
	int xNeighbors[4] = { 0 , 0 , -1, 1 };
	int yNeighbors[4] = { 1 , -1 , 0, 0};

	std::vector<Position> neighbors;
	
	for (int i = 0; i < 4; i++)
	{
		Position newNeighbors(pos.getX() + xNeighbors[i], pos.getY() + yNeighbors[i]);

		if (isValidMove(newNeighbors) || newNeighbors.isEqual(*pacPos))
		{
			neighbors.push_back(newNeighbors);
		}
	}
	
	return neighbors;
}

void Best::move()
{
	draw(object->getBoard()->get(object->getPosition()));

	setDirection();
	object->getPosition() = nextPos;

	draw(object->getSymbol());
}