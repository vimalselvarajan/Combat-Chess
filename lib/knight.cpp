#include "../include/knight.h"

#include <cstdlib>
#include <iostream>
using std::cout;

// [start coordinate] (x1, y1) 
//  move to 
// [destination coordinate] (x2, y2)
bool Knight::move(int y1, int x1, int y2, int x2) {
  if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) {
    return false;
  }

  // calculate difference in coordinates
  int dx = std::abs(x2 - x1);
  int dy = std::abs(y2 - y1);

  // check for valid L-shaped moves (2 by 1 or 1 by 2)
  if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
    return false;
  }

  Piece* target = board->getPiece(y2, x2);
  // check if destination is empty or occupied by opponent's piece
  if (target == nullptr || target->getColor() != this->getColor()) {
    // update own coordinates
    this->x = x2;
    this->y = y2;
    return true; // has moved
  }
  return false;
}
