/* Daniel Harper
 * CS2430-001
 * Knight's Tour
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "knight.h"

using namespace std;

knight::knight()
{
    //initialize the class variables
    xPos = 0;
    yPos = 0;
    iPreviousQuadrant = 0;
    relativeXPos = 0;
    relativeYPos = 0;
}

knight::~knight()
{
    
}

//Returns the x position
int knight::getXPos()
{
    return xPos;
}

//Returns the y position
int knight::getYPos()
{
    return yPos;
}

//Returns the x position
int knight::getRelativeXPos()
{
    return relativeXPos;
}

//Returns the y position
int knight::getRelativeYPos()
{
    return relativeXPos;
}

//Returns the previous quadrant
int knight::getPreviousQuadrant()
{
    return iPreviousQuadrant;
}

//Sets the previous quadrant
void knight::setPreviousQuadrant(int iPrevQuad)
{
    iPreviousQuadrant = iPrevQuad;
}

//Returns the current solving system
// 1 = RSquare, 2 = LSquare, 3 = RDiamond, 4 = LDiamond
int knight::getCurrentSolvingSystem()
{
    if((relativeXPos == 2 && relativeYPos == 0) || (relativeXPos == 0 && relativeYPos == 1) || (relativeXPos == 3 && relativeYPos == 2) || (relativeXPos == 1 && relativeYPos == 3))
    {
        return 1;
    }
    if((relativeXPos == 1 && relativeYPos == 0) || (relativeXPos == 3 && relativeYPos == 1) || (relativeXPos == 0 && relativeYPos == 2) || (relativeXPos == 2 && relativeYPos == 3))
    {
        return 2;
    }
    if((relativeXPos == 3 && relativeYPos == 0) || (relativeXPos == 1 && relativeYPos == 1) || (relativeXPos == 2 && relativeYPos == 2) || (relativeXPos == 0 && relativeYPos == 3))
    {
        return 3;
    }
    if((relativeXPos == 0 && relativeYPos == 0) || (relativeXPos == 2 && relativeYPos == 1) || (relativeXPos == 1 && relativeYPos == 2) || (relativeXPos == 3 && relativeYPos == 3))
    {
        return 4;
    } 
    return 0;
}

//Updates the position of the knight and also updates the relative position in the quadrant
void knight::updatePosition(int iNewX, int iNewY)
{
    xPos = iNewX;
    yPos = iNewY;
    updateRelativePos();
}

// Returns the current quadrant the knight is in
/* --------------
 * |  1  |   4  |
 * --------------
 * |  2  |   3  |
 * --------------
 */
int knight::getQuadrant()
{
    if(xPos <= 3 && yPos <= 3)
    {
        return 1;
    }
    else if (xPos <= 3 && yPos >= 4)
    {
        return 2;
    }
    else if (xPos >= 3 && yPos >= 4)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}


/* Updates the relative X Pos and Y Pos whenever the knight is moved.
 * 
 */
void knight::updateRelativePos()
{
    if (xPos >= 4)
    {
        relativeXPos = xPos - 4;
    }
    else
    {
        relativeXPos = xPos;
    }
    
    if (yPos >= 4)
    {
        relativeYPos = yPos - 4;
    }
    else
    {
        relativeYPos = yPos;
    }
}
