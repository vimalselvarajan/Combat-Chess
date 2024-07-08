#include "../include/pawn.h"

#include <cmath> 
//#include <iostream>

bool Pawn::move(int y1, int x1, int y2, int x2) 
// change x1 and y1 and x2 and y2 after
{
    //std::cout << "Move from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;

    if (!isInBounds(x2, y2) || (x1 == x2 && y1 == y2)) 
    {
        return false;
    }
    // Check if the destination is out of bounds or if there is no actual movement

    int direction;

    Piece* curr = board->getPiece(y1, x1);

    //std::cout << "PIECE A: " << colorToString(curr) << " " << pieceTypeToString(curr) << std::endl;
    
    if (getColor() == Color::WHITE) {
        direction = -1;
    } else {
        direction = 1;
    }
    // Set the direction based on pawn color, WHITE = 1(moves up), BLACK -1(moves down)

    Piece* target = board->getPiece(y2, x2);

    //std::cout << "PIECE B: " << pieceTypeToString(target) << std::endl;

    if (x1 == x2 && (y2 - y1) == direction && target == nullptr) 
    {
        // if (y2 == (getColor() == Color::WHITE ? 7 : 0)) 
        // {
        //     promoteToQueen(x2, y2);
        // }

        return true;
    }
    // Normal move forward by one square

    bool isSameColumn = x1 == x2;
    //std::cout << "Is same column: " << (isSameColumn? "true" : "false") << std::endl;

    bool isTwoSquaresForward = (y2 - y1) == 2 * direction;
    //std::cout << "Is two squares forward: " << (isTwoSquaresForward? "true" : "false") << std::endl;

    bool isStartingPosition;

    if (getColor() == Color::WHITE) 
    {
        isStartingPosition = y1 == 6;
    }
    else 
    {
        isStartingPosition = y1 == 1;
    }
    //std::cout << "Is starting position: " << (isStartingPosition? "true" : "false") << std::endl;

    bool isEmptySquare = board->getPiece(y1 + direction, x1) == nullptr;
    //std::cout << "Is empty square: " << (isEmptySquare? "true" : "false") << std::endl;

    bool isTargetEmpty = target == nullptr;
    //std::cout << "Is target empty: " << (isTargetEmpty? "true" : "false") << std::endl;

    if (isSameColumn && isTwoSquaresForward && isStartingPosition && isEmptySquare && isTargetEmpty) {
        return true;
    }
    // Initial move from starting position by two squares

    if (abs(x2 - x1) == 1 && (y2 - y1) == direction && target != nullptr && target->getColor() != getColor()) 
    {
        // if (y2 == (getColor() == Color::WHITE ? 7 : 0)) 
        // {
        //     promoteToQueen(x2, y2);
        // }

        return true;
    }
    // Capture move in diagonal direction

    return false;
}

// void Pawn::promoteToQueen(int x, int y) 
// {
//     // delete board[y][x];
//     // board[y][x] = new Queen(getColor(), x, y); // Assuming Queen constructor is defined.
//     return;
// }