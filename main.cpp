/* Daniel Harper
 * CS2430-001
 * Knight's Tour
 * 
 * Method of solving taken from http://www.youtube.com/watch?v=ChiOwpOjH_4
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "knight.h"
#include "chessboard.h"

using namespace std;

//Moves between solving methods.  Favors moving to a quadrant other than the one we're currently in.
void moveToNextSolvingMethod(ChessBoard * cb, knight * k)
{
    if(k->getQuadrant() < 3)
    {
        if ((k->getXPos() + 2 <= 7 && k->getYPos() + 1 <= 7) && (cb->checkSpace(k->getXPos() + 2, k->getYPos() + 1) == 0))
        {
            cb->takeSpace(k->getXPos() + 2, k->getYPos() + 1);
            k->updatePosition(k->getXPos() + 2, k->getYPos() + 1);
        }
        else if ((k->getXPos() + 2 <= 7 && k->getYPos() - 1 >= 0) && (cb->checkSpace(k->getXPos() + 2, k->getYPos() - 1) == 0))
        {
            cb->takeSpace(k->getXPos() + 2, k->getYPos() - 1);
            k->updatePosition(k->getXPos() + 2, k->getYPos() - 1);
        }
        else if ((k->getXPos() - 2 >= 0 && k->getYPos() - 1 >= 0) && (cb->checkSpace(k->getXPos() - 2, k->getYPos() - 1) == 0))
        {
            cb->takeSpace(k->getXPos() - 2, k->getYPos() - 1);
            k->updatePosition(k->getXPos() - 2, k->getYPos() - 1);
        }
        else if ((k->getXPos() - 2 <= 7 && k->getYPos() + 1 <= 7) && (cb->checkSpace(k->getXPos() - 2, k->getYPos() + 1) == 0))
        {
            cb->takeSpace(k->getXPos() - 2, k->getYPos() + 1);
            k->updatePosition(k->getXPos() - 2, k->getYPos() + 1);
        }
        else if ((k->getXPos() - 1 >= 0 && k->getYPos() - 2 >= 0) && (cb->checkSpace(k->getXPos() - 1, k->getYPos() - 2) == 0))
        {
            cb->takeSpace(k->getXPos() - 1, k->getYPos() - 2);
            k->updatePosition(k->getXPos() - 1, k->getYPos() - 2);
        }
        else if ((k->getXPos() - 1 >= 0 && k->getYPos() + 2 <= 7) && (cb->checkSpace(k->getXPos() - 1, k->getYPos() + 2) == 0))
        {
            cb->takeSpace(k->getXPos() - 1, k->getYPos() + 2);
            k->updatePosition(k->getXPos() - 1, k->getYPos() + 2);
        }
        else if ((k->getXPos() + 1 <= 7 && k->getYPos() + 2 <= 7) && (cb->checkSpace(k->getXPos() + 1, k->getYPos() + 2) == 0))
        {
            cb->takeSpace(k->getXPos() + 1, k->getYPos() + 2);
            k->updatePosition(k->getXPos() + 1, k->getYPos() + 2);
        }
    }
    else
    {
        if ((k->getXPos() - 2 >= 0 && k->getYPos() - 1 >= 0) && (cb->checkSpace(k->getXPos() - 2, k->getYPos() - 1) == 0) )
        {
            cb->takeSpace(k->getXPos() - 2, k->getYPos() - 1);
            k->updatePosition(k->getXPos() - 2, k->getYPos() - 1);
        }
        else if ((k->getXPos() - 2 <= 7 && k->getYPos() + 1 >= 0) && (cb->checkSpace(k->getXPos() - 2, k->getYPos() + 1) == 0))
        {
            cb->takeSpace(k->getXPos() - 2, k->getYPos() + 1);
            k->updatePosition(k->getXPos() - 2, k->getYPos() + 1);
        }
        else if ((k->getXPos() - 1 >= 0 && k->getYPos() - 2 >= 0) && (cb->checkSpace(k->getXPos() - 1, k->getYPos() - 2) == 0))
        {
            cb->takeSpace(k->getXPos() - 1, k->getYPos() - 2);
            k->updatePosition(k->getXPos() - 1, k->getYPos() - 2);
        }
        else if ((k->getXPos() - 1 <= 7 && k->getYPos() + 2 <= 7) && (cb->checkSpace(k->getXPos() - 1, k->getYPos() + 2) == 0))
        {
            cb->takeSpace(k->getXPos() - 1, k->getYPos() + 2);
            k->updatePosition(k->getXPos() - 1, k->getYPos() + 2);
        }
        else if ((k->getXPos() + 2 <= 7 && k->getYPos() + 1 <= 7) && (cb->checkSpace(k->getXPos() + 2, k->getYPos() + 1) == 0))
        {
            cb->takeSpace(k->getXPos() + 2, k->getYPos() + 1);
            k->updatePosition(k->getXPos() + 2, k->getYPos() + 1);
        }
        else if ((k->getXPos() + 2 <= 7 && k->getYPos() - 1 >= 0) && (cb->checkSpace(k->getXPos() + 2, k->getYPos() - 1) == 0))
        {
            cb->takeSpace(k->getXPos() + 2, k->getYPos() - 1);
            k->updatePosition(k->getXPos() + 2, k->getYPos() - 1);
        }
        else if ((k->getXPos() + 1 <= 7 && k->getYPos() + 2 <= 7) && (cb->checkSpace(k->getXPos() + 1, k->getYPos() + 2) == 0))
        {
            cb->takeSpace(k->getXPos() + 1, k->getYPos() + 2);
            k->updatePosition(k->getXPos() + 1, k->getYPos() + 2);
        }
    }
}

//Solves the current quadrant using the Right Square method
// (2,0), (0,1), (3,2), (1,3)
void solveQuadUsingRSquare(ChessBoard * cb, knight * k)
{
    int xoffset = 0, yoffset = 0; //offsets to help with relative to absolute x/y conversions based on quadrant
    bool movetaken = false; //flag if we need to change quadrants
    //calculate offsets.  Quadrant 1 is omitted because no offset is needed.
    switch (k->getQuadrant())
    {
        case 2:
            yoffset = 4;
            break;
        case 3:
            xoffset = 4;
            yoffset = 4;
            break;
        case 4:
            xoffset = 4;
            break;
    }
    if(k->getXPos() - xoffset == 2 && k->getYPos() - yoffset == 0)
    {
        if(cb->checkSpace(0 + xoffset, 1 + yoffset)  == 0)
        {
            k->updatePosition(0 + xoffset, 1 + yoffset);
            cb->takeSpace(0 + xoffset, 1 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 0 && k->getYPos() - yoffset == 1)
    {
        if(cb->checkSpace(1 + xoffset, 3 + yoffset)  == 0)
        {
            k->updatePosition(1 + xoffset, 3 + yoffset);
            cb->takeSpace(1 + xoffset, 3 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 1 && k->getYPos() - yoffset == 3)
    {
        if(cb->checkSpace(3 + xoffset, 2 + yoffset)  == 0)
        {
            k->updatePosition(3 + xoffset, 2 + yoffset);
            cb->takeSpace(3 + xoffset, 2 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 3 && k->getYPos() - yoffset == 2)
    {
        if(cb->checkSpace(2 + xoffset, 0 + yoffset)  == 0)
        {
            k->updatePosition(2 + xoffset, 0 + yoffset);
            cb->takeSpace(2 + xoffset, 0 + yoffset);
            movetaken = true;
        }
    }
    //Token hasn't moved, means it's time to move to a new quadrant.  First check if we can continue using the same method in the next quadrant.
    if (movetaken == false)
    {
        switch (k->getQuadrant())
        {
            case 1:
                if (k->getXPos() == 3 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(2, 4) == 0)
                    {
                        k->updatePosition(2, 4);
                        cb->takeSpace(2, 4);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 1 && k->getYPos() == 3)
                {
                    if(cb->checkSpace(0, 5) == 0)
                    {
                        k->updatePosition(0, 5);
                        cb->takeSpace(0, 5);
                        movetaken = true;
                    }
                }
                break;
            case 2:
                if (k->getXPos() == 2 && k->getYPos() == 4)
                {
                    if(cb->checkSpace(4, 5) == 0)
                    {
                        k->updatePosition(4, 5);
                        cb->takeSpace(4, 5);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 3 && k->getYPos() == 6)
                {
                    if(cb->checkSpace(5, 7) == 0)
                    {
                        k->updatePosition(5, 7);
                        cb->takeSpace(5, 7);
                        movetaken = true;
                    }
                }  
                break;
            case 3:
                if (k->getXPos() == 6 && k->getYPos() == 4)
                {
                    if(cb->checkSpace(7, 2) == 0)
                    {
                        k->updatePosition(7, 2);
                        cb->takeSpace(7, 2);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 4 && k->getYPos() == 5)
                {
                    if(cb->checkSpace(5, 3) == 0)
                    {
                        k->updatePosition(5, 3);
                        cb->takeSpace(5, 3);
                        movetaken = true;
                    }
                }  
                break;
            case 4:
                if (k->getXPos() == 4 && k->getYPos() == 1)
                {
                    if(cb->checkSpace(2, 0) == 0)
                    {
                        k->updatePosition(2, 0);
                        cb->takeSpace(2, 0);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 5 && k->getYPos() == 3)
                {
                    if(cb->checkSpace(3, 2) == 0)
                    {
                        k->updatePosition(3, 2);
                        cb->takeSpace(3, 2);
                        movetaken = true;
                    }
                }  
                break;
        }
    }
    //We can't stay within the same system, so it's time to move to another
    if (movetaken == false)
    {
        moveToNextSolvingMethod(cb,  k);
    }
}

//Solves the current quadrant using the Left Square method
// (1,0), (3,1), (0,2), (2,3)
void solveQuadUsingLSquare(ChessBoard * cb, knight * k)
{
    int xoffset = 0, yoffset = 0; //offsets to help with relative to absolute x/y conversions based on quadrant
    bool movetaken = false; //flag if we need to change quadrants
    //calculate offsets.  Quadrant 1 is omitted because no offset is needed.
    switch (k->getQuadrant())
    {
        case 2:
            yoffset = 4;
            break;
        case 3:
            xoffset = 4;
            yoffset = 4;
            break;
        case 4:
            xoffset = 4;
            break;
    }
    if(k->getXPos() - xoffset == 1 && k->getYPos() - yoffset == 0)
    {
        if(cb->checkSpace(3 + xoffset, 1 + yoffset)  == 0)
        {
            k->updatePosition(3 + xoffset, 1 + yoffset);
            cb->takeSpace(3 + xoffset, 1 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 3 && k->getYPos() - yoffset == 1)
    {
        if(cb->checkSpace(2 + xoffset, 3 + yoffset)  == 0)
        {
            k->updatePosition(2 + xoffset, 3 + yoffset);
            cb->takeSpace(2 + xoffset, 3 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 2 && k->getYPos() - yoffset == 3)
    {
        if(cb->checkSpace(0 + xoffset, 2 + yoffset)  == 0)
        {
            k->updatePosition(0 + xoffset, 2 + yoffset);
            cb->takeSpace(0 + xoffset, 2 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 0 && k->getYPos() - yoffset == 2)
    {
        if(cb->checkSpace(1 + xoffset, 0 + yoffset)  == 0)
        {
            k->updatePosition(1 + xoffset, 0 + yoffset);
            cb->takeSpace(1 + xoffset, 0 + yoffset);
            movetaken = true;
        }
    }
    //Token hasn't moved, means it's time to move to a new quadrant.  First check if we can continue using the same method in the next quadrant.
    if (movetaken == false)
    {
        switch (k->getQuadrant())
        {
            case 1:
                if (k->getXPos() == 3 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(5, 0) == 0)
                    {
                        k->updatePosition(5, 0);
                        cb->takeSpace(5, 0);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 2 && k->getYPos() == 3)
                {
                    if(cb->checkSpace(5, 2) == 0)
                    {
                        k->updatePosition(5, 2);
                        cb->takeSpace(5, 2);
                        movetaken = true;
                    }
                }
                break;
            case 2:
                if (k->getXPos() == 1 && k->getYPos() == 4)
                {
                    if(cb->checkSpace(0, 2) == 0)
                    {
                        k->updatePosition(0, 2);
                        cb->takeSpace(0, 2);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 3 && k->getYPos() == 5)
                {
                    if(cb->checkSpace(2, 3) == 0)
                    {
                        k->updatePosition(2, 3);
                        cb->takeSpace(2, 3);
                        movetaken = true;
                    }
                }  
                break;
            case 3:
                if (k->getXPos() == 5 && k->getYPos() == 4)
                {
                    if(cb->checkSpace(3, 5) == 0)
                    {
                        k->updatePosition(3, 5);
                        cb->takeSpace(3, 5);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 4 && k->getYPos() == 6)
                {
                    if(cb->checkSpace(2, 7) == 0)
                    {
                        k->updatePosition(2, 7);
                        cb->takeSpace(2, 7);
                        movetaken = true;
                    }
                }  
                break;
            case 4:
                if (k->getXPos() == 4 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(5, 4) == 0)
                    {
                        k->updatePosition(5, 4);
                        cb->takeSpace(5, 4);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 6 && k->getYPos() == 3)
                {
                    if(cb->checkSpace(7, 5) == 0)
                    {
                        k->updatePosition(7, 5);
                        cb->takeSpace(7, 5);
                        movetaken = true;
                    }
                }  
                break;
        }
        //We can't stay within the same system, so it's time to move to another
        if (movetaken == false)
        {
            moveToNextSolvingMethod(cb,  k);
        }
    }
}

//Solves the current quadrant using the Right Diamond method
// (3,0), (1,1), (2,2), (0,3)
void solveQuadUsingRDiamond(ChessBoard * cb, knight * k)
{
    int xoffset = 0, yoffset = 0; //offsets to help with relative to absolute x/y conversions based on quadrant
    bool movetaken = false; //flag if we need to change quadrants
    //calculate offsets.  Quadrant 1 is omitted because no offset is needed.
    switch (k->getQuadrant())
    {
        case 2:
            yoffset = 4;
            break;
        case 3:
            xoffset = 4;
            yoffset = 4;
            break;
        case 4:
            xoffset = 4;
            break;
    }
    if(k->getXPos() - xoffset == 1 && k->getYPos() - yoffset == 1)
    {
        if(cb->checkSpace(3 + xoffset, 0 + yoffset)  == 0)
        {
            k->updatePosition(3 + xoffset, 0 + yoffset);
            cb->takeSpace(3 + xoffset, 0 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 3 && k->getYPos() - yoffset == 0)
    {
        if(cb->checkSpace(2 + xoffset, 2 + yoffset)  == 0)
        {
            k->updatePosition(2 + xoffset, 2 + yoffset);
            cb->takeSpace(2 + xoffset, 2 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 2 && k->getYPos() - yoffset == 2)
    {
        if(cb->checkSpace(0 + xoffset, 3 + yoffset)  == 0)
        {
            k->updatePosition(0 + xoffset, 3 + yoffset);
            cb->takeSpace(0 + xoffset, 3 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 0 && k->getYPos() - yoffset == 3)
    {
        if(cb->checkSpace(1 + xoffset, 1 + yoffset)  == 0)
        {
            k->updatePosition(1 + xoffset, 1 + yoffset);
            cb->takeSpace(1 + xoffset, 1 + yoffset);
            movetaken = true;
        }
    }
    //Token hasn't moved, means it's time to move to a new quadrant.  First check if we can continue using the same method in the next quadrant.
    if (movetaken == false)
    {
        switch (k->getQuadrant())
        {
            case 1:
                if (k->getXPos() == 3 && k->getYPos() == 0)
                {
                    if(cb->checkSpace(5, 1) == 0)
                    {
                        k->updatePosition(5, 1);
                        cb->takeSpace(5, 1);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 2 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(4, 2) == 0)
                    {
                        k->updatePosition(4, 2);
                        cb->takeSpace(4, 2);
                        movetaken = true;
                    }
                }
                break;
            case 2:
                if (k->getXPos() == 3 && k->getYPos() == 4)
                {
                    if(cb->checkSpace(2, 2) == 0)
                    {
                        k->updatePosition(2, 2);
                        cb->takeSpace(2, 2);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 1 && k->getYPos() == 5)
                {
                    if(cb->checkSpace(0, 3) == 0)
                    {
                        k->updatePosition(0, 3);
                        cb->takeSpace(0, 3);
                        movetaken = true;
                    }
                }  
                break;
            case 3:
                if (k->getXPos() == 5 && k->getYPos() == 5)
                {
                    if(cb->checkSpace(3, 4) == 0)
                    {
                        k->updatePosition(3, 4);
                        cb->takeSpace(3, 4);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 4 && k->getYPos() == 7)
                {
                    if(cb->checkSpace(6, 2) == 0)
                    {
                        k->updatePosition(6, 2);
                        cb->takeSpace(6, 2);
                        movetaken = true;
                    }
                }  
                break;
            case 4:
                if (k->getXPos() == 4 && k->getYPos() == 3)
                {
                    if(cb->checkSpace(5, 5) == 0)
                    {
                        k->updatePosition(5, 5);
                        cb->takeSpace(5, 5);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 6 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(7, 4) == 0)
                    {
                        k->updatePosition(7, 4);
                        cb->takeSpace(7, 4);
                        movetaken = true;
                    }
                }  
                break;
        }
        //We can't stay within the same system, so it's time to move to another
        if (movetaken == false)
        {
            moveToNextSolvingMethod(cb,  k);
        }
    }
}

//Solves the current quadrant using the Left Diamond method
// (0,0), (2,1), (1,2), (3,3)
void solveQuadUsingLDiamond(ChessBoard * cb, knight * k)
{
    int xoffset = 0, yoffset = 0; //offsets to help with relative to absolute x/y conversions based on quadrant
    bool movetaken = false; //flag if we need to change quadrants
    //calculate offsets.  Quadrant 1 is omitted because no offset is needed.
    switch (k->getQuadrant())
    {
        case 2:
            yoffset = 4;
            break;
        case 3:
            xoffset = 4;
            yoffset = 4;
            break;
        case 4:
            xoffset = 4;
            break;
    }
    if(k->getXPos() - xoffset == 0 && k->getYPos() - yoffset == 0)
    {
        if(cb->checkSpace(1 + xoffset, 2 + yoffset)  == 0)
        {
            k->updatePosition(1 + xoffset, 2 + yoffset);
            cb->takeSpace(1 + xoffset, 2 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 2 && k->getYPos() - yoffset == 1)
    {
        if(cb->checkSpace(3 + xoffset, 3 + yoffset)  == 0)
        {
            k->updatePosition(3 + xoffset, 3 + yoffset);
            cb->takeSpace(3 + xoffset, 3 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 3 && k->getYPos() - yoffset == 3)
    {
        if(cb->checkSpace(2 + xoffset, 1 + yoffset)  == 0)
        {
            k->updatePosition(2 + xoffset, 1 + yoffset);
            cb->takeSpace(2 + xoffset, 1 + yoffset);
            movetaken = true;
        }
    }
    else if(k->getXPos() - xoffset == 2 && k->getYPos() - yoffset == 1)
    {
        if(cb->checkSpace(0 + xoffset, 0 + yoffset)  == 0)
        {
            k->updatePosition(0 + xoffset, 0 + yoffset);
            cb->takeSpace(0 + xoffset, 0 + yoffset);
            movetaken = true;
        }
    }
    //Token hasn't moved, means it's time to move to a new quadrant.  First check if we can continue using the same method in the next quadrant.
    if (movetaken == false)
    {
        switch (k->getQuadrant())
        {
            case 1:
                if (k->getXPos() == 1 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(0, 4) == 0)
                    {
                        k->updatePosition(0, 4);
                        cb->takeSpace(0, 4);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 3 && k->getYPos() == 3)
                {
                    if(cb->checkSpace(2, 5) == 0)
                    {
                        k->updatePosition(2, 5);
                        cb->takeSpace(2, 5);
                        movetaken = true;
                    }
                }
                break;
            case 2:
                if (k->getXPos() == 2 && k->getYPos() == 5)
                {
                    if(cb->checkSpace(4, 4) == 0)
                    {
                        k->updatePosition(4, 4);
                        cb->takeSpace(4, 4);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 3 && k->getYPos() == 7)
                {
                    if(cb->checkSpace(5, 6) == 0)
                    {
                        k->updatePosition(5, 6);
                        cb->takeSpace(5, 6);
                        movetaken = true;
                    }
                }  
                break;
            case 3:
                if (k->getXPos() == 4 && k->getYPos() == 4)
                {
                    if(cb->checkSpace(5, 2) == 0)
                    {
                        k->updatePosition(5, 2);
                        cb->takeSpace(5, 2);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 6 && k->getYPos() == 5)
                {
                    if(cb->checkSpace(7, 3) == 0)
                    {
                        k->updatePosition(7, 3);
                        cb->takeSpace(7, 3);
                        movetaken = true;
                    }
                }  
                break;
            case 4:
                if (k->getXPos() == 4 && k->getYPos() == 0)
                {
                    if(cb->checkSpace(2, 1) == 0)
                    {
                        k->updatePosition(2, 1);
                        cb->takeSpace(2, 1);
                        movetaken = true;
                    }
                }
                else if (k->getXPos() == 5 && k->getYPos() == 2)
                {
                    if(cb->checkSpace(3, 3) == 0)
                    {
                        k->updatePosition(3, 3);
                        cb->takeSpace(3, 3);
                        movetaken = true;
                    }
                }  
                break;
        }
        //We can't stay within the same system, so it's time to move to another
        if (movetaken == false)
        {
            moveToNextSolvingMethod(cb,  k);
        }
    }
}


int main(int argc, char **argv) 
{
    srand ( time(NULL) ); //initialize the random number generator using time.
    // Create the knight and the board on the heap so we can manipulate them across methods
    ChessBoard * mainBoard = new ChessBoard;
    knight * lancelot = new knight;
    // Initialize the knight and place it randomly on the board
    lancelot->updatePosition(rand() % 8, rand() % 8);
    //lancelot->updatePosition(2,0);
    mainBoard->takeSpace(lancelot->getXPos(), lancelot->getYPos());
    
    //Loop until we solve the board
    while(mainBoard->checkSolved() == false)
    { 
        mainBoard->printBoard(*lancelot);
        switch (lancelot->getCurrentSolvingSystem())
        {
            case 1:
                solveQuadUsingRSquare(mainBoard, lancelot);
                break;
            case 2:
                solveQuadUsingLSquare(mainBoard, lancelot);
                break;
            case 3:
                solveQuadUsingRDiamond(mainBoard, lancelot);
                break;
            case 4:
                solveQuadUsingLDiamond(mainBoard, lancelot);
                break;
        }
    }
    delete lancelot, mainBoard; //Free up the heap memory
    return 0;
}
