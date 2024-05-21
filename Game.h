#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "io_utils.h"
#include "Board.h"
#include "MovementStrategy.h"
#include "GameManager.h"

class Game
{
   // Consts
   const enum class Lives { MAX_LIVES = 3, END_LIVES = 0 };
   const enum class Score { INIT_SCORE = 0, SCORE_X = 6 };

    // Data members
   int lives, score;
    Board gameBoard;

    MovementStrategy::Movment ghostMovment;
    std::vector<std::string> filesNames;

    // Functions

    // Print massage acordding to the current end game 
    void endGame()const;

    // Scan from the user name of a file and return it
    std::string scanFileName()const;

    // Init the data member fileNamea acordding to the given boolean - scan a name from the user or take all the valid names from the working directory
    void initFilesNames(bool isSpescific);

    // Add the file names with the given prefix and suffix to the vector in the working directory
    void findFilesNameWorkingDir(const std::string& path, const std::string& prefix, const std::string& suffix);
    
    // Return whether the given fullString has the given suffix or not
    bool isValidSuffix(std::string const& fullString, std::string const& suffix);

    // Return whether the given fullString has the given prefix or not
    bool isValidPrefix(std::string const& fullString, std::string const& prefix);
    
    // Print the current score in the information line
    void printScore()const;   

public:

    // C-tor
    Game(MovementStrategy::Movment _ghostMovment, bool isSpescific);

    // Run the game for all the boards
    void run();

    // Set the data member score acording to the given add of points to the current one and print the new score
    void setScore(int add)
    {
        score += add;
        printScore();
    }

    // Reduce the data member lives
    void reduceLives()
    {
        lives--;
    }

    // Get the data member ghostMovment
    MovementStrategy::Movment getMovment() const
    {
        return ghostMovment;
    }

    // Get the data member ghostMovment ByRef
    Board& getBoard()
    {
        return gameBoard;
    }

    // clean the window and print the given massage
    void printMassage(std::string massage)const;

    // Print the game information
    void printGameInfo()const;

    // Return whether the lives are ended or no
    bool isEndLives()const
    {
        return (lives == int(Lives::END_LIVES));
    }
};

#endif
 