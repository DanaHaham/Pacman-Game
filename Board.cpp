#include "Board.h"

const std::string Board::objectSymbol = "@$ *#% ";

void Board::insert(char obj, const Position&& pos)
{
    char ch;

    // Find the current char to the board and init the position of the objects
    if (obj == objectSymbol[(int)Objects::PACMAN])
    {
        initPos[(int)Objects::PACMAN] = pos;
        ch = objectSymbol[(int)Objects::EMPTY_PHS];
    }

    else if (obj == objectSymbol[(int)Objects::GHOST])
    {
        initPos.push_back(pos);
        ch = objectSymbol[(int)Objects::EMPTY_PHS];
    }

    else if (obj == objectSymbol[(int)Objects::WALL])
    {
        ch = obj;
    }

    else if (obj == objectSymbol[(int)Objects::BREADCRUMBS_LOG])
    {
        ch = objectSymbol[(int)Objects::BREADCRUMBS_PHS];
        numBreadcrumbs++;
    }

    else if (obj == objectSymbol[(int)Objects::EMPTY_LOG])
    {
        ch = objectSymbol[(int)Objects::EMPTY_PHS];
    }

    // Insert the current ch to the board
    set(pos, ch);
}

void Board::init(std::ifstream& fp)
{
    std::string line;

    numBreadcrumbs = 0;

    // If there are already ghosts, earae them
    initPos.erase(initPos.begin() + 1, initPos.end());

    // while (!fp.eof())
    for (int i = 0; i < int(Size::HEIGHT); i++)
    {
        getline(fp, line);

        for (int j = 0; j < int(Size::WIDTH); j++)
        {
            // Insert the current char in the file to the board
            insert(line[j], Position(j, i));
        }

        set(Position(int(Size::WIDTH), i), '\n');
    }
}
