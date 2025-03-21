#include "PieceLocations.h"
#include <iostream>

PieceLocations::PieceLocations() {
	//Initialize the locations container
	locations = new std::vector<Box>();
	rookLocations = new std::vector<Box>();
	bishopLocations = new std::vector<Box>();
	queenLocations = new std::vector<Box>();
	knightLocations = new std::vector<Box>();
	kingLocations = new std::vector<Box>();
	pawnLocations = new std::vector<Box>();

}


PieceLocations::~PieceLocations() {
	delete locations;
	delete rookLocations;
	delete bishopLocations;
	delete queenLocations;
	delete knightLocations;
	delete kingLocations;
	delete pawnLocations;
}

std::vector<Box>* PieceLocations::getRookLocations() {
	return rookLocations;
}
std::vector<Box>* PieceLocations::getBishopLocations() {
	return bishopLocations;
}
std::vector<Box>* PieceLocations::getQueenLocations() {
	return queenLocations;
}
std::vector<Box>* PieceLocations::getKnightLocations() {
	return knightLocations;
}
std::vector<Box>* PieceLocations::getKingLocations() {
	return kingLocations;
}
std::vector<Box>* PieceLocations::getPawnLocations() {
	return pawnLocations;
}




//Fills in the location information based on the board state.
//Basically just loops over the board, finds chars that match
//our desired player, and records the (x,y) coordinates in
//the locations vector, as well as specialized vectors for each piece type.
void PieceLocations::init(char playerToSearch, BoardState* boardState) {
	//Clear all of the vectors
	clearSearches();
	searchChar = playerToSearch;
	
	if (playerToSearch == 'w' || playerToSearch == 'b') {
		char baseChar = 'r';
		if (searchChar == 'w') {
			baseChar = 'R';
		}
		else {
			baseChar = 'r';
		}
		//Search for rooks.
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char currentPiece = boardState->getPieceAt(i, j);
				if (currentPiece == baseChar) {
					Box rook = { i,j };
					rookLocations->push_back(rook);
					locations->push_back(rook);
				}
			}
		}

		if (searchChar == 'w') {
			baseChar = 'B';
		}
		else {
			baseChar = 'b';
		}
		//Search for bishops.
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char currentPiece = boardState->getPieceAt(i, j);
				if (currentPiece == baseChar) {
					Box bishop = { i,j };
					bishopLocations->push_back(bishop);
					locations->push_back(bishop);
				}
			}
		}

		if (searchChar == 'w') {
			baseChar = 'Q';
		}
		else {
			baseChar = 'q';
		}
		//Search for queens.
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char currentPiece = boardState->getPieceAt(i, j);
				if (currentPiece == baseChar) {
					Box queen = { i,j };
					queenLocations->push_back(queen);
					locations->push_back(queen);
				}
			}
		}

		if (searchChar == 'w') {
			baseChar = 'N';
		}
		else {
			baseChar = 'n';
		}
		//Search for knights.
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char currentPiece = boardState->getPieceAt(i, j);
				if (currentPiece == baseChar) {
					Box knight = { i,j };
					knightLocations->push_back(knight);
					locations->push_back(knight);
				}
			}
		}

		if (searchChar == 'w') {
			baseChar = 'K';
		}
		else {
			baseChar = 'k';
		}
		//Search for kings.
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char currentPiece = boardState->getPieceAt(i, j);
				if (currentPiece == baseChar) {
					Box king = { i,j };
					kingLocations->push_back(king);
					locations->push_back(king);
				}
			}
		}

		if (searchChar == 'w') {
			baseChar = 'P';
		}
		else {
			baseChar = 'p';
		}
		//Search for pawns.
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char currentPiece = boardState->getPieceAt(i, j);
				if (currentPiece == baseChar) {
					Box pawn = { i,j };
					pawnLocations->push_back(pawn);
					locations->push_back(pawn);
				}
			}
		}
	}


}




void PieceLocations::clearSearches() {
	locations->clear();
	rookLocations->clear();
	bishopLocations->clear();
	queenLocations->clear();
	knightLocations->clear();
	kingLocations->clear();
	pawnLocations->clear();
}