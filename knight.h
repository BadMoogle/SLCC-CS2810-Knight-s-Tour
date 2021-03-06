/* Daniel Harper
 * CS2430-001
 * Knight's Tour
 */

#ifndef KNIGHT_H
#define KNIGHT_H

class knight
{
private:
    //			Variables
    int xPos;
    int yPos;
    int iPreviousQuadrant;
    int relativeXPos; //xPos as it relates to the quadrant
    int relativeYPos; //yPos as it relates to the quadrant
    
    //			Private methods
    
    
public:
    knight();
    virtual ~knight();
    
    //Appropriate getters and setters for private variables
    int getXPos();
    int getYPos();
    int getRelativeXPos();
    int getRelativeYPos();
    int getCurrentSolvingSystem();
    int getPreviousQuadrant();
    void setPreviousQuadrant(int iPrevQuad);
    
    //Other public methods
    void updatePosition(int iNewX, int iNewY);
    int getQuadrant();
    void updateRelativePos();
    
};

#endif // KNIGHT_H
