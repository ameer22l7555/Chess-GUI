#include "BoardState.h"
#include <iostream>

BoardState::BoardState() {
	hasBlackKingMoved = false;
	hasWhiteKingMoved = false;
	hasBlackQueensideRookMoved = false;
	hasBlackKingsideRookMoved = false;
	hasWhiteQueensideRookMoved = false;
	hasWhiteKingsideRookMoved = false;
	for (int i = 0; i < 2; i++) {
		enPassantXPos[i] = -1;
		enPassantYPos[i] = -1;
		enPassantXPosWhite[i] = -1;
		enPassantYPosWhite[i] = -1;
	}

}


BoardState::~BoardState() {

}

//Initialize the chess board with pieces in starting position.
void BoardState::init() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = 'e';
		}
	}
	currentTurn = 'w';
	hasBlackKingMoved = false;
	hasWhiteKingMoved = false;

	hasBlackQueensideRookMoved = false;
	hasBlackKingsideRookMoved = false;
	hasWhiteQueensideRookMoved = false;
	hasWhiteKingsideRookMoved = false;

	for (int i = 0; i < 2; i++) {
		enPassantXPos[i] = -1;
		enPassantYPos[i] = -1;
	}

	
	//White pawns
	for (int i = 0; i < 8; i++) {
		board[i][6] = 'P';
	}
	//Black pawns
	for (int i = 0; i < 8; i++) {
		board[i][1] = 'p';
	}
	//White Rooks
	board[0][7] = 'R';
	board[7][7] = 'R';
	//Black Rooks
	board[0][0] = 'r';
	board[7][0] = 'r';
	//White Knights
	board[1][7] = 'N';
	board[6][7] = 'N';
	//Black Knights
	board[1][0] = 'n';
	board[6][0] = 'n';
	//White Bishops
	board[2][7] = 'B';
	board[5][7] = 'B';
	//Black Bishops
	board[2][0] = 'b';
	board[5][0] = 'b';
	//White Queen
	board[3][7] = 'Q';
	//Black Queen
	board[3][0] = 'q';
	//White King
	board[4][7] = 'K';
	//Black King
	board[4][0] = 'k';


}


char BoardState::getPieceAt(int x, int y) {
	return board[x][y];
}

void BoardState::setPieceAt(int x, int y, char piece) {
	board[x][y] = piece;
}



void BoardState::setEnPassantPos(int idx, int x, int y) {
	enPassantXPos[idx] = x;
	enPassantYPos[idx] = y;
}

void BoardState::setWhiteEnPassantPos(int idx, int x, int y) {
	enPassantXPosWhite[idx] = x;
	enPassantYPosWhite[idx] = y;
}

int BoardState::getEnPassantXPos(int idx) {
	return enPassantXPos[idx];
}

int BoardState::getEnPassantYPos(int idx) {
	return enPassantYPos[idx];
}

int BoardState::getWhiteEnPassantXPos(int idx) {
	return enPassantXPosWhite[idx];
}

int BoardState::getWhiteEnPassantYPos(int idx) {
	return enPassantYPosWhite[idx];
}

void BoardState::clearEnPassant() {
	for (int i = 0; i < 2; i++) {
		enPassantXPos[i] = -1;
		enPassantYPos[i] = -1;
	}
}

void BoardState::clearWhiteEnPassant() {
	for (int i = 0; i < 2; i++) {
		enPassantXPosWhite[i] = -1;
		enPassantYPosWhite[i] = -1;
	}
}

char BoardState::getCurrentTurn() {
	return currentTurn;
}

void BoardState::setCurrentTurn(char turn) {
	currentTurn = turn;
}

//Castling getters and setters
bool BoardState::getBlackKingMoved() {
	return hasBlackKingMoved;
}
bool BoardState::getWhiteKingMoved() {
	return hasWhiteKingMoved;
}
bool BoardState::getBlackQueensideRookMoved() {
	return hasBlackQueensideRookMoved;
}
bool BoardState::getBlackKingsideRookMoved() {
	return hasBlackKingsideRookMoved;
}
bool BoardState::getWhiteQueensideRookMoved() {
	return hasWhiteQueensideRookMoved;
}
bool BoardState::getWhiteKingsideRookMoved() {
	return hasWhiteKingsideRookMoved;
}

void BoardState::setBlackKingMoved(bool moved) {
	hasBlackKingMoved = moved;
}
void BoardState::setWhiteKingMoved(bool moved) {
	hasWhiteKingMoved = moved;
}
void BoardState::setBlackQueensideRookMoved(bool moved) {
	hasBlackQueensideRookMoved = moved;
}
void BoardState::setBlackKingsideRookMoved(bool moved) {
	hasBlackKingsideRookMoved = moved;
}
void BoardState::setWhiteQueensideRookMoved(bool moved) {
	hasWhiteQueensideRookMoved = moved;
}
void BoardState::setWhiteKingsideRookMoved(bool moved) {
	hasWhiteKingsideRookMoved = moved;
}

