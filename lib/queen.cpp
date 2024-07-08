#include "../include/queen.h"
#include <cmath>
#include <iostream>
using std::cout;

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Queen::move(int y1, int x1, int y2, int x2) {
    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
        return false;
    }

    // find absolute value difference of start and end x and y coordinates
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    // queen movement: combination of rook AND bishop
    if (dx != dy && x1 != x2 && y1 != y2) {
        return false;
    }

    int xStep = 0;
    int yStep = 0;
    
    /* determine direction of movement (calculate step movement) */
    // vertical movement (if horizontal coordinate is same)
    if (x1 == x2) { 
        yStep = (y2 > y1) ? 1 : -1;
    } 
    
    // horizontal movement (if vertical coordinate is same)
    else if (y1 == y2) { 
        xStep = (x2 > x1) ? 1 : -1;
    } 
    
    // diagonal movement (else)
    else { 
        xStep = (x2 > x1) ? 1 : -1;
        yStep = (y2 > y1) ? 1 : -1; 
    }
  
    // start moving towards destination coordinates
    int x = x1 + xStep;
    int y = y1 + yStep;

    // check if all squares between the start and end are empty
    // (stops right before destination coordinate!)
    while (x != x2 || y != y2) {
        if (board->getPiece(y, x) != nullptr) {
            return false;
        }
        x += xStep;
        y += yStep;
    }

    Piece* target = board->getPiece(y2, x2);
    // check if destination is empty or occupied by an opponent's piece
    if (target == nullptr || target->getColor() != this->getColor()) {
        // update own coordinates
        this->x = x2;
        this->y = y2;
    
        return true; // has moved
    }

    return false;
}
