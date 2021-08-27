/* Daniel Harper
 * CS2430-001
 * Knight's Tour
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "knight.h"

class ChessBoard
{
private:
    int board[8][8]; //0 means open space, anything else means the knight is or was there.
    
public:
    ChessBoard();
    virtual ~ChessBoard();
    bool checkSolved();
    void printBoard(knight k);
    void takeSpace(int x, int y);
    int checkSpace(int x, int y);
    
};

#endif // CHESSBOARD_H
