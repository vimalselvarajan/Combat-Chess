#include "../include/Board.h"
#include "../include/Game.h"
#include "../include/piece.h"
#include "../include/bishop.h"
#include "../include/king.h"
#include "../include/knight.h"
#include "../include/pawn.h"
#include "../include/queen.h"
#include "../include/rook.h"

#include <iostream>

using std::cout;
using std::endl;

// Constructor sets up the Board
Board::Board() {
    //set up black pieces
    King* blackKing = new King(Color::BLACK, 0, 4, this);
    square[0][0] = new Rook(Color::BLACK, 0, 0, this, blackKing);
    square[0][1] = new Knight(Color::BLACK, 0, 1, this);
    square[0][2] = new Bishop(Color::BLACK, 0, 2, this);
    square[0][3] = new Queen(Color::BLACK, 0, 3, this);
    square[0][4] = blackKing;
    square[0][5] = new Bishop(Color::BLACK, 0, 5, this);
    square[0][6] = new Knight(Color::BLACK, 0, 6, this);
    square[0][7] = new Rook(Color::BLACK, 0, 7, this, blackKing);
    for (int i = 0; i < 8; i++) {
        square[1][i] = new Pawn(Color::BLACK, 1, i, this);
    }

    // set up white pieces
    King* whiteKing = new King(Color::WHITE, 7, 4, this);
    square[7][0] = new Rook(Color::WHITE, 7, 0, this, whiteKing);
    square[7][1] = new Knight(Color::WHITE, 7, 1, this);
    square[7][2] = new Bishop(Color::WHITE, 7, 2, this);
    square[7][3] = new Queen(Color::WHITE, 7, 3, this);
    square[7][4] = whiteKing;
    square[7][5] = new Bishop(Color::WHITE, 7, 5, this);
    square[7][6] = new Knight(Color::WHITE, 7, 6, this);
    square[7][7] = new Rook(Color::WHITE, 7, 7, this, whiteKing);
    for (int i = 0; i < 8; i++) {
        square[6][i] = new Pawn(Color::WHITE, 6, i, this);
    }

}

Board::~Board() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			delete square[i][j];
		}
	}
}

void Board::updateBoard(int oldX, int oldY, int newX, int newY) {
	square[newX][newY] = square[oldX][oldY];
	square[oldX][oldY] = nullptr;
}

void Board::setGame(Game* game) {
	this->game = game;
}

// Correcting verifyPieceToMove
bool Board::verifyPieceToMove(int x, int y) const {
	Piece* curr = square[x][y];
	if (curr == nullptr) { return false; }
	return curr->getColor() == game->getTurn();
}

// returns -1 if a player attempts an invalid move, returns 1 if a piece initiates combat, returns 0 if a piece just moves
int Board::verifyMove(int oldX, int oldY, int newX, int newY) {
	if (!verifyPieceToMove(oldX, oldY)) {
		game->updateTurn();
		return -1;
	}

	Piece* selectedPiece = square[oldX][oldY];
	if (!selectedPiece->move(oldX, oldY, newX, newY)) {
		game->updateTurn();
		return -1; 
	}

	Piece* targetPiece = square[newX][newY];

	Color currentTurn = game->getTurn();
	
	if (targetPiece == nullptr) 
	{ 
		game->updateTurn();
		updateBoard(oldX, oldY, newX, newY);
		return 0;
	}
	
	else if(((targetPiece->getType() == PieceType::King) && (selectedPiece->getType() == PieceType::Rook))) 
	{
		game->updateTurn();
		Piece* temp = square[newX][newY];
		square[newX][newY] = square[oldX][oldY];
		square[oldX][oldY] = temp;
		return 0;
	}
	
	// if combat
	else if (currentTurn == Color::WHITE && targetPiece->getColor() == Color::BLACK || currentTurn == Color::BLACK && targetPiece->getColor() == Color::WHITE) { 
		return 1;
	}
	
	else {
		game->updateTurn();
		return -1;
	}
}

// Correcting getPiece
Piece* Board::getPiece(int x, int y) const {
    return square[x][y];
}

void Board::placePiece(int x, int y, Piece* piece) {
	// if is in bounds
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        square[x][y] = piece;
    }
}