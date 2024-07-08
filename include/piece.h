#pragma once

#include "../include/Board.h"
#include "../include/enums.h" 

class Board; 

class Piece {
protected:
    Color color;      
    PieceType type;
    Board* board; 
    int x;
    int y;
    int currHp; // current health
    int maxHp; // max health
    int atk; // attack stat
    int acc; // accuracy stat

public:
    Piece(Color color, int x, int y, PieceType type, Board* board, int maxHp, int atk, int acc) 
        : color(color), x(x), y(y), type(type), board(board),
          maxHp(maxHp), currHp(maxHp), atk(atk), acc(acc) {}
    virtual ~Piece() {}

    bool isInBounds(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
    
    virtual bool move(int x1, int y1, int x2, int y2) = 0;  

    void takeDamage(int damage) {
        currHp -= damage;
        if (currHp < 0) { currHp = 0; }
    }

    std::string colorToString(const Piece* piece) {
        if (piece == nullptr) {
            return "No piece";
        }
        return colorToString(piece->getColor());
    }

    std::string colorToString(Color color) {
        if (color == Color::WHITE) {
            return "White";
        } else {
            return "Black";
        }
    }
    std::string pieceTypeToString(const Piece* piece) {
        if (piece == nullptr) {
            return "No piece";  // Handle the case where the pointer is null.
        }
        return pieceToString(piece->getType());
    } 

    Color getColor() const { return color; }
    PieceType getType() const { return type; }
    void getPosition(int& outX, int& outY) const { outX = x; outY = y; }
    int getHp() const { return currHp; }
    int getMaxHp() const { return maxHp; }
    int getAtk() const { return atk; }
    int getAcc() const { return acc; }
    int getX() const { return x; }
    int getY() const { return y; }
};