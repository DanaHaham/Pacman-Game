#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
#include "GameObject.h"

class Fruit : public GameObject
{
	// Data members
	int value, duration, appearance;
	bool isAppear;

public:

	// Functions
	
	// C-tor
	Fruit(Board* _pGameBoard);

	// Get the data member value
	int getValue()const
	{
		return value;
	}

	// Get the data member isAppear
	bool getIsAppear()const
	{
		return isAppear;
	}

	void init(bool isPause = false);

	// Reduce the duration of the fruit. If the duration over, delete the fruit.
	bool updateDuration();

	// Acordding to the given steps, check if it is time to appear and in case that yes, init the fruit
	void appear(int steps);

};

#endif

