#include "GameManager.h"
#include "Game.h"

GameManager::GameManager(Game* _pGame) : pacman(&_pGame->getBoard())
{
	// Init the data members
	pGame = _pGame;
	breadcrumbs = steps = 0;
	isPause = false;

	// Handle the creation and initial setting of the objects
	createObjects();

	// Print the current board
	pGame->printGameInfo();
	pGame->getBoard().print();
}

void GameManager::createObjects()
{
	// Craete ghosts acordding to the current board
	ghosts.resize(pGame->getBoard().getNumObjects() - 1, { pGame->getMovment(), &pGame->getBoard(), &pacman.getPosition() });

	// Craete rand number of fruits betwwen 4 to 15
	int randFruits = (rand() % 11) + 4;
	for (int i = 0; i < randFruits; i++)
	{
		fruits.push_back(Fruit(&pGame->getBoard()));
	}

	// Init the pos init of the pacman and the ghosts
	pacman.setInitPos(pGame->getBoard().getInitPos((int)(Board::Objects::PACMAN)));

	for (int i = 0; i < ghosts.size(); i++)
	{
		ghosts[i].setInitPos(pGame->getBoard().getInitPos((int)(Board::Objects::GHOST)+i));
	}
}

void GameManager::init()
{
	// In case of pause, print the current board
	if (isPause)
	{
		pGame->getBoard().print();
	}

	// Print game info
	pGame->printGameInfo();

	// Init the positon of the objects 
	for (int i = 0; i < ghosts.size(); i++)
	{
		ghosts[i].init(isPause);
	}

	for (int i = 0; i < fruits.size(); i++)
	{
		fruits[i].init(isPause);
	}

	pacman.init(isPause);

}

void GameManager::play()
{
	// As long as the game isnt over, play another step
	while (!pGame->isEndLives() && breadcrumbs < pGame->getBoard().getNumBreadcrumbs())
	{
		// Handle key press
		pressKey();

		if (!isPause)
		{
			// Make a move for all the objects in the game
			step();
		}
	}
}

void GameManager::pressKey()
{
	char key = 0;

	// Check if the user press any key
	if (_kbhit())
	{
		// Get the user key
		key = _getch();

		// ESC was pressed
		if (key == int(Keys::ESC))
		{
			// Init game if the game is already paused
			if (isPause)
			{
				init();
			}

			// Pause game
			else
			{
				pGame->printMassage("Game paused, press ESC again to continue");
			}

			isPause = !isPause;
		}

		// Check if the key is a direction of the pacman, and set the direction if it is
		else
		{
			pacman.setDirection(key);
		}
	}
}

void GameManager::step()
{
	// Move objects
	pacman.move();

	if (steps % int(Speeds::GOHST) == 0)
	{
		for (int i = 0; i < ghosts.size(); i++)
		{
			ghosts[i].move();
		}
	}

	for (int i = 0; i < fruits.size(); i++)
	{
		fruits[i].appear(steps);

		if (fruits[i].getIsAppear())
		{
			if (steps % int(Speeds::FRUIT) == 0)
			{
				fruits[i].move();
			}

			if (fruits[i].updateDuration())
			{
				removeFruit(i);
			}
		}
	}

	// Update the game acording to the rules
	updateGame();

	// Update steps
	steps++;

	Sleep(100);
}

void GameManager::updateGame()
{
	isPacmanEatBreadcrumbs();
	isPacmanEatFruit();
	isPacmanGhostCollide();
	isFruitGhostCollide();
}

void GameManager::isPacmanGhostCollide()
{
	for (int i = 0; i < ghosts.size(); i++)
	{
		if (pacman.getPosition().isEqual(ghosts[i].getPosition()))
		{
			pGame->reduceLives();

			// If the lives arent over
			if (!pGame->isEndLives())
			{
				init();
			}
		}
	}
}

void GameManager::isFruitGhostCollide()
{
	for (int i = 0; i < ghosts.size(); i++)
	{
		for (int j = 0; j < fruits.size(); j++)
		{
			if (fruits[j].getPosition().isEqual(ghosts[i].getPosition()) && fruits[i].getIsAppear())
			{
				removeFruit(j);
			}
		}
		
	}
}

void GameManager::isPacmanEatBreadcrumbs()
{
	if (pGame->getBoard().isBreadcrumbs(pacman.getPosition()))
	{
		// Update score
		breadcrumbs++;
		pGame->setScore(1);

		// Delete the breadcrumb
		pGame->getBoard().set(pacman.getPosition(), ' ');
	}
}

void GameManager::isPacmanEatFruit()
{
	for (int i = 0; i < fruits.size(); i++)
	{
		if (pacman.getPosition().isEqual(fruits[i].getPosition()) && fruits[i].getIsAppear())
		{
			{
				// Update score
				pGame->setScore(fruits[i].getValue());

				// Delete the fruit
				removeFruit(i);
			}
		}
	}
		
}

	