#include "Pacman.h"

void Pacman::init(bool isPause)
{
	GameObject::init(isPause);

	if (!isPause)
	{
		dynamic_cast<Keyboard*>(movement)->init();
	}
}

void Pacman::setDirection(char key)
{
	dynamic_cast<Keyboard*>(movement)->setKey(key);
	dynamic_cast<Keyboard*>(movement)->setDirection();
}

