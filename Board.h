#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Position.h"

class Board 
{
    // Consts
    const enum class Size { WIDTH = 80, HEIGHT = 24 };

public:
    const enum class Objects {PACMAN, GHOST, BREADCRUMBS_LOG, BREADCRUMBS_PHS, WALL, EMPTY_LOG, EMPTY_PHS};
    const static std::string objectSymbol;

private:

    // Data members
    char board[(int(Size::WIDTH) + 1) * int(Size::HEIGHT) + 1];
    std::vector<Position> initPos;
    int numBreadcrumbs;

    // Functions 
    
    // Insert to the board the given object in the given position
    void insert(char obj, const Position&& pos);

public:

    // C-tor
    Board() : initPos(1){}

   // Clean the window and print the board
   void print() const
    {
       // Clean window
       clear_screen();

       // Print board
       std::cout << board;
       std::cout << std::flush;
    }

   // Get the char in the given position in this board
   char get(const Position& pos) const
   {
        return board[(int(Size::WIDTH) + 1)* pos.getY() + pos.getX()];
   }

   // Set the char in the given position in this board
   void set(const Position& pos, char ch)
   {
      board[(int(Size::WIDTH) + 1) * pos.getY() + pos.getX()] = ch;
   }

   // Get the const width
   int getWidth()const
   {
        return int(Size::WIDTH);
   }

   // Get the const height
   int getHeight()const
   {
       return int(Size::HEIGHT);
   }

   // Get the init position in the given index
   Position getInitPos(int index) const
   {
       return initPos[index];
   }

   // Get the data member points
   int getNumBreadcrumbs() const
   {
       return numBreadcrumbs;
   }

   // Get the number of objects that are init in the board
   int getNumObjects()const
   {
       return initPos.size();
   }

   // Check if the given position in this board is wall
   bool isWall(const Position& pos) const
   {
       return(get(pos) == objectSymbol[(int)Objects::WALL]);
   }

   // Check if the given position in this board is tunnel
   bool isTunnel(const Position& pos) const
   {
       return(get(pos) == objectSymbol[(int)Objects::EMPTY_PHS] && (pos.getX() == 0 || pos.getX() == ((int)Size::WIDTH - 1) || pos.getY() == 0 || pos.getY() == (int)Size::HEIGHT - 1));
   }

   // Check if the given position in this board is breadcrumbs
   bool isBreadcrumbs(const Position& pos) const
   {
       return(get(pos) == objectSymbol[(int)Objects::BREADCRUMBS_PHS]);
   }

   // Init the board acordding to the given file
   void init(std::ifstream& fp);


};

#endif
