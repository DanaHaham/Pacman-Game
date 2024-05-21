#include "Menu.h"

void Menu::run()
{
    // Remove cursor
    hideCursor();

    // Print the menu
    print();

    // Until the user press exit, wait for a key
    while (pressKey());
}

bool Menu::pressKey()const
{
    char key = 0;

    // Check if the user press any key
    if (_kbhit())
    {
        // Get the user key
        key = _getch();

        // Check if the key is a menu option
        switch (key - '0')
        {
        case START:
            startGame(false);
            break;

        case SPESCIFIC_SCREEN:
            startGame(true);
            break;

        case INSTRUCTIONS:
            instructionsAndKeys();
            break;

        case EXIT:
            return false;
            break;
        }
    }

    return true;
}

void Menu::instructionsAndKeys()const
{
    // Print instructions
    printInstructionsAndKeys();

    // Get back to the menu
    char key = 0;

    while ((key - '0') != BACK)
    {
        // Check if the user press any key
        if (_kbhit())
        {
            // Get the user key
            key = _getch();
        }
    }

    // Print the menu
    print();
}

void Menu::startGame(bool isSpescific)const
{
    // Create new game
    Game game(chooseLevel(), isSpescific);

    // Start the game 
    game.run();
    
    // The game is over, as long as the user dont press any key, wait
    while (!_kbhit());

    // Print the menu
    print();
}

MovementStrategy::Movment Menu::chooseLevel()const
{
    MovementStrategy::Movment scan;

    // Clean window
    clear_screen();

    // Print levels
    std::cout << "Choose the level of the game: \n";
    std::cout << "Novice: press " << (int)(MovementStrategy::Movment::NOVICE) << "\n";
    std::cout << "Good: press " << (int)(MovementStrategy::Movment::GOOD) << "\n";
    std::cout << "Best: press " << (int)(MovementStrategy::Movment::BEST) << "\n";

    std::cout << std::flush;

    // Scan the wanted level from the user
    while (scanLevel(scan));

    return scan;
}

bool Menu::scanLevel(MovementStrategy::Movment& scan)const
{
    char key = 0;

    // Check if the user press any key
    if (_kbhit())
    {
        // Get the user key
        key = _getch();

        // Check if the key is a menu option
        switch (key - '0')
        {
            case (int)(MovementStrategy::Movment::NOVICE) :
                scan = MovementStrategy::Movment::NOVICE;
                return false;
            break;

            case (int)(MovementStrategy::Movment::GOOD) :
                scan = MovementStrategy::Movment::GOOD;
                return false;
            break;

            case (int)(MovementStrategy::Movment::BEST) :
                scan = MovementStrategy::Movment::BEST;  
                return false;
            break;
        }
    }

    return true;
}

void Menu::print() const
{
    // Clean window
    clear_screen();

    // Print menu
    std::cout << "Welcome to the Pacman Game! \n    By Dana & Nitzan \n\n\n";
    std::cout << "(" << START << ") Start a new game\n";
    std::cout << "(" << SPESCIFIC_SCREEN << ") Start a new game with spescific screen\n";
    std::cout << "(" << INSTRUCTIONS << ") Present instructions and keys\n";
    std::cout << "(" << EXIT << ") EXIT\n";

    std::cout << std::flush;
}

void Menu::printInstructionsAndKeys()const
{
    // Clean window
    clear_screen();

    // Print menu
    std::cout << "Instructions: \n";
    std::cout << "The objective of the game is to eat all of the breadcrumbs placed in the maze while avoiding two ghosts. \n";
    std::cout << "When Pac-Man eats all of the breadcrumbs, the player wins the game\n\n";
    std::cout << "Keys: \n";
    std::cout << "Up - W or w \n";
    std::cout << "Down - X or x \n";
    std::cout << "Left - A or a \n";
    std::cout << "Right - D or d \n";
    std::cout << "Stay - S or s \n\n\n";

    std::cout << "Press " << BACK << " to go back to the menu";

    std::cout << std::flush;
}
