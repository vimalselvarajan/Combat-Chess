#pragma once

class Piece;
class Game;

// class responsible for storing where pieces are on the board
class Board {
	private:
		// board is a 2d array storing pointers to the pieces (if there is no piece it stores nullptr) 
		Piece* square[8][8];
		Game* game;
		// determines there a player can move whatever is at the location
		bool verifyPieceToMove(int x, int y) const;
	public:
		// sets up the board to the standard start for chess
		Board();
		~Board();
		// moves a piece
		void updateBoard(int oldX, int oldY, int newX, int newY);
		// determines if the player is making a possible move
		int verifyMove(int oldX, int oldY, int newX, int newY);
		// Returns whatever piece is at that square
		Piece* getPiece(int x, int y) const;
		// places a piece (for pawn promotion)
		void placePiece(int x, int y, Piece* piece);
		// sets the game
		void setGame(Game* game);
};