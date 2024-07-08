#pragma once

#include "piece.h"
#include <vector>
#include <string>

class Display {
	private:
		Board* board;
		std::vector<std::string> displayBlackPiece(Piece*);
		std::vector<std::string> displayWhitePiece(Piece*);
		std::vector<std::string> printWhitePawn();
		std::vector<std::string> printWhiteKnight();
		std::vector<std::string> printWhiteBishop();
		std::vector<std::string> printWhiteRook();
		std::vector<std::string> printWhiteQueen();
		std::vector<std::string> printWhiteKing();
		std::vector<std::string> printBlackPawn();
		std::vector<std::string> printBlackKnight();
		std::vector<std::string> printBlackBishop();
		std::vector<std::string> printBlackRook();
		std::vector<std::string> printBlackQueen();
		std::vector<std::string> printBlackKing();
	public: 
		Display(Board*);
		void displayBoard();
		void displayCombat(Piece*, Piece*);
		void displayStats(Piece*, Piece*, int);
};