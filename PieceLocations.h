#pragma once
#include <vector>
#include "Box.h"
#include "BoardState.h"

//Class to keep track of piece locations. As in, once we find where all the 
//pieces are for one of the colors, we can save time by referring here rather 
//than checking each square. This class gets passed the boardState and then 
//is responsible for finding where all pieces are.
class PieceLocations
{
private:
	//stores locations of all pieces (doesn't say what the piece is).
	std::vector<Box>* locations;
	//Store location of just the rooks.
	std::vector<Box>* rookLocations;
	//Store locations of just the bishops.
	std::vector<Box>* bishopLocations;
	//Store locations of queens.
	std::vector<Box>* queenLocations;
	//Store location of just the knights.
	std::vector<Box>* knightLocations;
	//Store location of just the king.
	std::vector<Box>* kingLocations;
	//Store locations of pawns.
	std::vector<Box>* pawnLocations;
	
	
	char searchChar;
public:
	PieceLocations();
	~PieceLocations();
	void init(char playerToSearch, BoardState* boardState);
	
	std::vector<Box>* getRookLocations();
	std::vector<Box>* getBishopLocations();
	std::vector<Box>* getQueenLocations();
	std::vector<Box>* getKnightLocations();
	std::vector<Box>* getKingLocations();
	std::vector<Box>* getPawnLocations();
	void clearSearches();

};

