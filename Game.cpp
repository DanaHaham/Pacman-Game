#include "Game.h"

Game::Game(MovementStrategy::Movment _ghostMovment, bool isSpescific)
{
    // Init the game info
    lives = (int)(Lives::MAX_LIVES);
    score = (int)(Score::INIT_SCORE);

    ghostMovment = _ghostMovment;
    initFilesNames(isSpescific);
}

void Game::run()
{
    std::ifstream fp;

    // Play till end of the borads or lives
    for (int i = 0; i < filesNames.size() && !isEndLives(); i++)
    {
        // Load the current board
        fp.open(filesNames[i], std::ios_base::in);

        if (fp.is_open() && fp.good())
        {
            // Play the game with the current board 
            gameBoard.init(fp);

            GameManager game(this);
            game.init();
            game.play();
        }

        // Close file
        fp.close();
    }

    // End the game with the relavent massage
    endGame();
}

void Game::endGame()const
{
    if (isEndLives())
    {
        printMassage("GAME OVER");
    }
    else if (score > (int)(Score::INIT_SCORE))
    {
        printMassage("YOU WON");
    }
    else
    {
        printMassage("There are no screens for play");
    }
}

void Game::printMassage(std::string massage)const
{
    // Clean window
    clear_screen();

    // Print the given massage
    gotoxy(20, 12);
    std::cout << massage;
    std::cout << std::flush;
}

void Game::printGameInfo()const
{
    // Go to the line that handel the game's information 
    gotoxy(0, gameBoard.getHeight());
    std::cout << "Score: " << "                                                                 " << "Lives: " << lives;
    std::cout << std::flush;

    // Print the current score
    printScore();
}

void Game::printScore()const
{
    // Go to the line that handel the game's information 
    gotoxy(int(Score::SCORE_X), gameBoard.getHeight());
    std::cout << score;
    std::cout << std::flush;
}

std::string Game::scanFileName()const
{
    std::string fileName;

    // Clean window
    clear_screen();

    // Scan the name of the screen
    std::cout << "Enter the name of the spescific screen: ";
    std::cin >> fileName;

    return fileName;
}

void Game::initFilesNames(bool isSpescific)
{
    // Check if the user want to run specific screen
    if (isSpescific)
    {
        // Init the scan file 
        filesNames.push_back(scanFileName());
    }
    else
    {
        // Init all the files with the names pacman_*.screen in lexicographical order 
        findFilesNameWorkingDir(".", "pacman_", ".screen");
        std::sort(filesNames.begin(), filesNames.end());
    }
}

void Game::findFilesNameWorkingDir(const std::string& path, const std::string& prefix, const std::string& suffix)
{
    // Pass all the files name in the working directory
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        // Check if the current file name has the valid suffix and prefix
        if (isValidSuffix(entry.path().string(), suffix) && isValidPrefix(entry.path().string(), prefix))
        {
            filesNames.push_back(entry.path().string());
        }
    }
}

bool Game::isValidSuffix(std::string const& fullString, std::string const& suffix)
{
    if (fullString.length() >= suffix.length())
    {
        return (0 == fullString.compare(fullString.length() - suffix.length(), suffix.length(), suffix));
    }
    else
    {
        return false;
    }
}

bool Game::isValidPrefix(std::string const& fullString, std::string const& prefix)
{
    if (fullString.length() >= prefix.length())
    {
        return (0 == fullString.compare(2, prefix.length(), prefix));
    }
    else
    {
        return false;
    }
}




