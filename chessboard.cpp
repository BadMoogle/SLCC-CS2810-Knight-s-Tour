/* Daniel Harper
 * CS2430-001
 * Knight's Tour
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

using namespace std;

ChessBoard::ChessBoard()
{
    /* Initialize the board
     *  0 means open space, anything else means the knight is or was there.
     */
    int board[8][8] = {	{0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0} };
}

ChessBoard::~ChessBoard()
{
    
}

// Turns the specified x,y coordinates to occupied.
void ChessBoard::takeSpace(int x, int y)
{
    board[y][x] = 1;
}

int ChessBoard::checkSpace(int x, int y)
{
    return board[y][x];
}

// Verifies if any spots on the board are left to be solved
bool ChessBoard::checkSolved()
{
    for (int y = 0; y <= 7; y++)
    {
        for (int x = 0; x <= 7; x++)
        {
            if (board[y][x] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

//Prints the current board to the console then waits for user to press enter
void ChessBoard::printBoard(knight k)
{
    system("clear");
    cout << "  ";
    for (int i = 1; i <= 8; i++)
    {
        cout << "  " << char(i + 64) << " ";
    }
    cout << endl;
    for (int y = 0; y <= 7; y++)
    {
        cout << "  ";
        for (int i = 1; i <= 33; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << (y + 1) << " ";
        for (int x = 0; x <= 7; x++)
        {
            if (board[y][x] == 0)
            {
                cout << "|   ";
            }
            else if (x == k.getXPos() && y == k.getYPos())
            {
                cout << "| K ";
            }
            else
            {
                cout << "| X ";
            }
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int i = 1; i <= 33; i++)
    {
        cout << "-";
    }
    cout << endl << endl << "Press enter to continue" << endl;
    getchar();
    return;
}