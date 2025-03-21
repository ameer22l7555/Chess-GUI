#include "StoreMove.h"

StoreMove::StoreMove()
{
}

StoreMove::StoreMove(Move aMove, BoardState* state) {
	move = aMove;

	// Store the previous player
	previousPlayer = state->getCurrentTurn();

	// Store the old castling state
	fromHasBlackKingMoved = state->getBlackKingMoved();
	fromHasWhiteKingMoved = state->getWhiteKingMoved();
	fromHasBlackQueensideRookMoved = state->getBlackQueensideRookMoved();
	fromHasBlackKingsideRookMoved = state->getBlackKingsideRookMoved();
	fromHasWhiteQueensideRookMoved = state->getWhiteQueensideRookMoved();
	fromHasWhiteKingsideRookMoved = state->getWhiteKingsideRookMoved();

	// Store the current en passant state
	for (int i = 0; i < 2; i++) {
		fromXEnPassant[i] = state->getEnPassantXPos(i);
		fromYEnPassant[i] = state->getEnPassantYPos(i);
		fromXWhiteEnPassant[i] = state->getWhiteEnPassantXPos(i);
		fromYWhiteEnPassant[i] = state->getWhiteEnPassantYPos(i);
	}

	// Get the captured piece (if any)
	capturedPiece = state->getPieceAt(aMove.toBox.x, aMove.toBox.y);

	isEnPassantCapture = aMove.isEnPassant;
	isCastlingCapture = aMove.isCastling;
}


StoreMove::~StoreMove()
{
}

Move StoreMove::getMove() {
	return move;
}

// Access stored information about previous state
int StoreMove::getFromXEnPassant(int idx) {
	return fromXEnPassant[idx];
}

int StoreMove::getFromYEnPassant(int idx) {
	return fromYEnPassant[idx];
}

void StoreMove::setFromEnPassantXY(int idx, int x, int y) {
	fromXEnPassant[idx] = x;
	fromYEnPassant[idx] = y;
}

int StoreMove::getFromXWhiteEnPassant(int idx) {
	return fromXWhiteEnPassant[idx];
}

int StoreMove::getFromYWhiteEnPassant(int idx) {
	return fromYWhiteEnPassant[idx];
}

void StoreMove::setFromWhiteEnPassantXY(int idx, int x, int y) {
	fromXWhiteEnPassant[idx] = x;
	fromYWhiteEnPassant[idx] = y;
}

char StoreMove::getCapturedPiece() {
	return capturedPiece;
}

void StoreMove::setCapturedPiece(char piece) {
	capturedPiece = piece;
}

bool StoreMove::getIsEnPassantCapture() {
	return isEnPassantCapture;
}

void StoreMove::setIsEnPassantCapture(bool value) {
	isEnPassantCapture = value;
}

bool StoreMove::getIsCastlingCapture() {
	return isCastlingCapture;
}

void StoreMove::setIsCastlingCapture(bool value) {
	isCastlingCapture = value;
}

// Castling state getters/setters
bool StoreMove::getFromHasBlackKingMoved() {
	return fromHasBlackKingMoved;
}

void StoreMove::setFromHasBlackKingMoved(bool value) {
	fromHasBlackKingMoved = value;
}

bool StoreMove::getFromHasWhiteKingMoved() {
	return fromHasWhiteKingMoved;
}

void StoreMove::setFromHasWhiteKingMoved(bool value) {
	fromHasWhiteKingMoved = value;
}

bool StoreMove::getFromHasBlackQueensideRookMoved() {
	return fromHasBlackQueensideRookMoved;
}

void StoreMove::setFromHasBlackQueensideRookMoved(bool value) {
	fromHasBlackQueensideRookMoved = value;
}

bool StoreMove::getFromHasBlackKingsideRookMoved() {
	return fromHasBlackKingsideRookMoved;
}

void StoreMove::setFromHasBlackKingsideRookMoved(bool value) {
	fromHasBlackKingsideRookMoved = value;
}

bool StoreMove::getFromHasWhiteQueensideRookMoved() {
	return fromHasWhiteQueensideRookMoved;
}

void StoreMove::setFromHasWhiteQueensideRookMoved(bool value) {
	fromHasWhiteQueensideRookMoved = value;
}

bool StoreMove::getFromHasWhiteKingsideRookMoved() {
	return fromHasWhiteKingsideRookMoved;
}

void StoreMove::setFromHasWhiteKingsideRookMoved(bool value) {
	fromHasWhiteKingsideRookMoved = value;
}

char StoreMove::getPreviousPlayer() {
	return previousPlayer;
}

void StoreMove::setPreviousPlayer(char player) {
	previousPlayer = player;
}

void StoreMove::setCastlingRookMove(Move move) {
	castlingRookMove = move;
}

std::string StoreMove::toString() {
	std::string result = "Move from (" + std::to_string(move.fromBox.x) + "," + std::to_string(move.fromBox.y) + ") to (" + 
						std::to_string(move.toBox.x) + "," + std::to_string(move.toBox.y) + ")";
	if (isEnPassantCapture) {
		result += " (en passant)";
	}
	if (isCastlingCapture) {
		result += " (castling)";
	}
	if (capturedPiece != 'e') {
		result += " captured: " + std::string(1, capturedPiece);
	}
	return result;
}