#include "../include/bishop.h"
#include <cmath>
#include <iostream>
using std::cout;

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Bishop::move(int y1, int x1, int y2, int x2) {
  if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
      return false;
  }

  int dx = std::abs(x2 - x1);
  int dy = std::abs(y2 - y1);

  // bishops move diagonally, so absolute difference b/n x and y coordinates must be equal
  if (dx != dy) {
      return false;
  }

  /* determine (diagonal) direction of bishop movement */
  // if ( ), then 1 = right \\ else, -1 = left 
  int xStep = (x2 > x1) ? 1 : -1;
  // if ( ), then 1 = up \\ else, -1 = down
  int yStep = (y2 > y1) ? 1 : -1;
  
  /* move once, towards destination coordinate */
  int x = x1 + xStep;
  int y = y1 + yStep;

  // check if all squares b/n start and end are empty
  // does NOT check the actual destination coordinate (stops right before)
  while (x != x2 && y != y2) {
    // return false if any coordinate b/n start and end is NOT valid 
    // if getPiece at currLocation is NOT nullptr then there's a piece there
    // THEREFORE should return false
    if (board->getPiece(y, x) != nullptr) {
      return false;
    }
    // step towards destination coordinate
    x += xStep;
    y += yStep;
  }

  Piece* target = board->getPiece(y2, x2);
  // if empty OR spot has piece on it
  if (target == nullptr || target->getColor() != this->getColor()) {
    // update own coordinates
    this->x = x2;
    this->y = y2;

    return true; // has moved
  }

  return false;
}
