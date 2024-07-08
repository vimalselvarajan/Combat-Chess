#ifndef ENUMS_H
#define ENUMS_H

#include <string>

enum class Color {
    WHITE, BLACK
};

enum class PieceType {
    Pawn, Knight, Bishop, Rook, Queen, King
};

// Function to convert Color enum to string
std::string colorToString(Color color);

// Function to convert PieceType enum to string
std::string pieceToString(PieceType pieceType);

#endif 
