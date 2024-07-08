#include "../include/Display.h"
#include "../include/piece.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Display::Display(Board* b) {
	board = b;
}

void Display::displayBoard() {
	cout << "   |";
	for (int i = 0; i < 8; i++) {
		cout << " " << i << " |";
	}

	cout << endl << std::setfill('-') << std::setw(37) << "" << endl;

	for (int i = 0; i < 8; i++) {
		cout << " " << i << " ";
		for (int j = 0; j < 8; j++) {
			Piece* curr = board->getPiece(i, j);
			cout << "|";
			if (curr != nullptr) {
				if (curr->getColor() == Color::WHITE) {
					switch (curr->getType()) {
						case PieceType::King: 
						{
							cout << " ♚ ";
							break;
						}
						case PieceType::Queen:
						{
							cout << " ♛ ";
							break;
						}
						case PieceType::Pawn:
						{
							cout << " ♟ ";
							break;
						}
						case PieceType::Knight:
						{
							cout << " ♞ ";
							break;
						}
						case PieceType::Bishop:
						{
							cout << " ♝ ";
							break;
						}
						case PieceType::Rook:
						{
							cout << " ♜ ";
							break;
						}
					}
				}
				else {
					switch (curr->getType()) {
						case PieceType::King: 
						{
							cout << " ♔ ";
							break;
						}
						case PieceType::Queen:
						{
							cout << " ♕ ";
							break;
						}
						case PieceType::Pawn:
						{
							cout << " ♙ ";
							break;
						}
						case PieceType::Knight:
						{
							cout << " ♘ ";
							break;
						}
						case PieceType::Bishop:
						{
							cout << " ♗ ";
							break;
						}
						case PieceType::Rook:
						{
							cout << " ♖ ";
							break;
						}
					}
				}
			}
			else { cout << "   "; }
		}
		cout << "|\n";
		cout << std::setfill('-') << std::setw(37) << "" << endl;
	}
}

void Display::displayCombat(Piece* attacker, Piece* defender) {
	std::cout << "\n------------------------------------\n";

	// white is attacker
	if (attacker->getColor() == Color::WHITE) {
		vector<string> attackPiece = displayWhitePiece(attacker);
		vector<string> defendPiece = displayBlackPiece(defender);
		cout << attackPiece.at(0) << std::setfill(' ') << std::setw(2) << "" << "VERSUS" << std::setfill(' ') << std::setw(2) << "" << defendPiece[0] << endl;
		for (int i = 1; i < 8; i++) {
			cout << attackPiece[i];
			cout << std::setfill(' ') << std::setw(10) << "";
			cout << defendPiece[i] << endl;
		}
	}
	// black is attacker
	else {
		vector<string> defendPiece = displayBlackPiece(defender);
		vector<string> attackPiece = displayWhitePiece(attacker);
		cout << defendPiece.at(0) << std::setfill(' ') << std::setw(2) << "" << "VERSUS" << std::setfill(' ') << std::setw(2) << "" << attackPiece[0] << endl;
		for (int i = 1; i < 8; i++) {
			cout << defendPiece[i];
			cout << std::setfill(' ') << std::setw(10) << "";
			cout << attackPiece[i] << endl;
		}
	}
}

void Display::displayStats(Piece* attacker, Piece* defender, int turn){
	std::string colorAndType = colorToString(attacker->getColor()) + " " 
								+ pieceToString(attacker->getType()) + "'s Stats";
    int totalWidth = 32; // total width of box
    int padding = (totalWidth - 2 - colorAndType.size()) / 2; // padding for centering text

	std::cout << std::setw((totalWidth/2)+6) << "Turn " << turn << "\n";
	// Attacker stats
    std::cout << " ╔══════════════════════════════╗\n";
    std::cout << " ║" << std::string(padding, ' ') << colorAndType << std::string(padding + (colorAndType.size() % 2 == 0 ? 0 : 1), ' ') << "║\n";
    std::cout << " ╠══════════════════════════════╣\n"; 
    std::cout << " ║" << std::setw(9) << "HP:" << std::setw(11) << attacker->getHp() << " / " << attacker->getMaxHp() << std::setw(9) << "║\n";
    std::cout << " ║" << std::setw(13) << "Attack:" << std::setw(7) << attacker->getAtk() << std::setw(14) << "║\n";
    std::cout << " ║" << std::setw(15) << "Accuracy:" << std::setw(5) << attacker->getAcc() << " %" << std::setw(12) << "║\n";
    std::cout << " ╚══════════════════════════════╝\n";

	colorAndType = colorToString(defender->getColor()) + " " 
					+ pieceToString(defender->getType()) + "'s Stats";
	padding = (totalWidth - 2 - colorAndType.size()) / 2;
    // Defender stats
    std::cout << " ╔══════════════════════════════╗\n";
    std::cout << " ║" << std::string(padding, ' ') << colorAndType << std::string(padding + (colorAndType.size() % 2 == 0 ? 0 : 1), ' ') << "║\n";
    std::cout << " ╠══════════════════════════════╣\n"; 
    std::cout << " ║" << std::setw(9) << "HP:" << std::setw(11) << defender->getHp() << " / " << defender->getMaxHp() << std::setw(9) << "║\n";
    std::cout << " ║" << std::setw(13) << "Attack:" << std::setw(7) << defender->getAtk() << std::setw(14) << "║\n";
    std::cout << " ║" << std::setw(15) << "Accuracy:" << std::setw(5) << defender->getAcc() << " %" << std::setw(12) << "║\n";
    std::cout << " ╚══════════════════════════════╝\n";
}

vector<string> Display::displayWhitePiece(Piece* piece) {
	switch(piece->getType()) {
		case PieceType::Pawn:
		{
			return printWhitePawn();
		}
		case PieceType::Knight:
		{
			return printWhiteKnight();
		}
		case PieceType::Bishop:
		{
			return printWhiteBishop();
		}
		case PieceType::Rook:
		{
			return printWhiteRook();
		}
		case PieceType::Queen:
		{
			return printWhiteQueen();
		}
		case PieceType::King:
		{
			return printWhiteKing();
		}
	}
	vector<string> nothing;
	return nothing;
}

vector<string> Display::displayBlackPiece(Piece* piece) {
	switch(piece->getType()) {
		case PieceType::Pawn:
		{
			return printBlackPawn();
		}
		case PieceType::Knight:
		{
			return printBlackKnight();
		}
		case PieceType::Bishop:
		{
			return printBlackBishop();
		}
		case PieceType::Rook:
		{
			return printBlackRook();
		}
		case PieceType::Queen:
		{
			return printBlackQueen();
		}
		case PieceType::King:
		{
			return printBlackKing();
		}
	}
	vector<string> nothing;
	return nothing;
}

vector<string> Display::printWhitePawn() {
	vector<string> out;
	out.push_back("  WHITE PAWN ");
	out.push_back("             ");
	out.push_back("     ■■■     ");
	out.push_back("    ■■■■■    ");
	out.push_back("     ■■■     ");
	out.push_back("    ■■■■■    ");
	out.push_back("   ■■■■■■■   ");
	out.push_back("  ■■■■■■■■■  ");
	return out;
}

vector<string> Display::printWhiteKnight() {
	vector<string> out;
	out.push_back(" WHITE KNIGHT");
	out.push_back("             ");
	out.push_back("     ■■■     ");
	out.push_back("  ■■■■■■■    ");
	out.push_back("  ■■■■■■■    ");
	out.push_back("    ■■■■■    ");
	out.push_back("   ■■■■■■■   ");
	out.push_back("  ■■■■■■■■■  ");
	return out;
}

vector<string> Display::printWhiteBishop() {
	vector<string> out;
	out.push_back(" WHITE BISHOP");
	out.push_back("     ■■      ");
	out.push_back("    ■■  ■    ");
	out.push_back("    ■■■■■    ");
	out.push_back("     ■■■     ");
	out.push_back("     ■■■     ");
	out.push_back("    ■■■■■    ");
	out.push_back("   ■■■■■■■   ");
	return out;
}

vector<string> Display::printWhiteRook() {
	vector<string> out;
	out.push_back("  WHITE ROOK ");
	out.push_back("             ");
	out.push_back("   ■ ■ ■ ■   ");
	out.push_back("   ■■■■■■■   ");
	out.push_back("    ■■■■■    ");
	out.push_back("    ■■■■■    ");
	out.push_back("   ■■■■■■■   ");
	out.push_back("  ■■■■■■■■■  ");
	return out;
}

vector<string> Display::printWhiteQueen() {
	vector<string> out;
	out.push_back(" WHITE QUEEN ");
	out.push_back("    ■ ■ ■    ");
	out.push_back("    ■■■■■    ");
	out.push_back("     ■■■     ");
	out.push_back("     ■■■     ");
	out.push_back("     ■■■     ");
	out.push_back("    ■■■■■    ");
	out.push_back("   ■■■■■■■   ");
	return out;
}

vector<string> Display::printWhiteKing() {
	vector<string> out;
	out.push_back("  WHITE KING ");
	out.push_back("      ■      ");
	out.push_back("   ■■■■■■■   ");
	out.push_back("    ■■■■■    ");
	out.push_back("     ■■■     ");
	out.push_back("     ■■■     ");
	out.push_back("    ■■■■■    ");
	out.push_back("   ■■■■■■■   ");
	return out; 
}

vector<string> Display::printBlackPawn() {
	vector<string> out;
	out.push_back("  BLACK PAWN ");
	out.push_back("             ");
	out.push_back("     |||     ");
	out.push_back("    |||||    ");
	out.push_back("     |||     ");
	out.push_back("    |||||    ");
	out.push_back("   |||||||   ");
	out.push_back("  |||||||||  ");
	return out;
}

vector<string> Display::printBlackKnight() {
	vector<string> out;
	out.push_back(" BLACK KNIGHT");
	out.push_back("             ");
	out.push_back("     |||     ");
	out.push_back("  |||||||    ");
	out.push_back("  |||||||    ");
	out.push_back("    |||||    ");
	out.push_back("   |||||||   ");
	out.push_back("  |||||||||  ");
	return out;
}

vector<string> Display::printBlackBishop() {
	vector<string> out;
	out.push_back(" BLACK BISHOP");
	out.push_back("     ||      ");
	out.push_back("    ||  |    ");
	out.push_back("    |||||    ");
	out.push_back("     |||     ");
	out.push_back("     |||     ");
	out.push_back("    |||||    ");
	out.push_back("   |||||||   ");
	return out; 
}

vector<string> Display::printBlackRook() {
	vector<string> out;
	out.push_back("  BLACK ROOK ");
	out.push_back("             ");
	out.push_back("   | | | |   ");
	out.push_back("   |||||||   ");
	out.push_back("    |||||    ");
	out.push_back("    |||||    ");
	out.push_back("   |||||||   ");
	out.push_back("  |||||||||  ");
	return out;
}

vector<string> Display::printBlackQueen() {
	vector<string> out;
	out.push_back(" BLACK QUEEN ");
	out.push_back("    | | |    ");
	out.push_back("    |||||    ");
	out.push_back("     |||     ");
	out.push_back("     |||     ");
	out.push_back("     |||     ");
	out.push_back("    |||||    ");
	out.push_back("   |||||||   ");
	return out;
}

vector<string> Display::printBlackKing() {
	vector<string> out;
	out.push_back("  BLACK KING ");
	out.push_back("      |      ");
	out.push_back("   |||||||   ");
	out.push_back("    |||||    ");
	out.push_back("     |||     ");
	out.push_back("     |||     ");
	out.push_back("    |||||    ");
	out.push_back("   |||||||   ");
	return out; 
}