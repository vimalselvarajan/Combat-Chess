#include "../include/enums.h"

// convert enum to string
std::string colorToString(Color color) {
    return (color == Color::WHITE) ? "WHITE" : "BLACK";
}

std::string pieceToString(PieceType pieceType) {
    switch (pieceType) {
        case PieceType::Pawn:    return "Pawn";
        case PieceType::Knight:  return "Knight";
        case PieceType::Bishop:  return "Bishop";
        case PieceType::Rook:    return "Rook";
        case PieceType::Queen:   return "Queen";
        case PieceType::King:    return "King";
    }
    return "Unknown";
}