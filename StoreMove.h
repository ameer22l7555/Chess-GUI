#pragma once
#include "Move.h"
#include "BoardState.h"
#include <string>
//Class to store a move. This consists of the pieces from, to and where they went
//as well as the state of the board before the move (en passant, castling)
//with these stored we can go backwards.
class StoreMove
{
public:
	StoreMove();
	StoreMove(Move move,BoardState* state);
	~StoreMove();

	Move getMove();

	//to recreate the state of things before the move.
	//en passant
	int getFromXEnPassant(int idx);
	int getFromYEnPassant(int idx);
	void setFromEnPassantXY(int idx, int x, int y);


	int getFromXWhiteEnPassant(int idx);
	int getFromYWhiteEnPassant(int idx);
	void setFromWhiteEnPassantXY(int idx, int x, int y);


	char getCapturedPiece();
	void setCapturedPiece(char);
	bool getIsEnPassantCapture();
	void setIsEnPassantCapture(bool);
	bool getIsCastlingCapture();
	void setIsCastlingCapture(bool);



	//castling
	//store the old castling state.
	bool getFromHasBlackKingMoved();
	void setFromHasBlackKingMoved(bool);

	bool getFromHasWhiteKingMoved();
	void setFromHasWhiteKingMoved(bool);

	bool getFromHasBlackQueensideRookMoved();
	void setFromHasBlackQueensideRookMoved(bool);

	bool getFromHasBlackKingsideRookMoved();
	void setFromHasBlackKingsideRookMoved(bool);

	bool getFromHasWhiteQueensideRookMoved();
	void setFromHasWhiteQueensideRookMoved(bool);

	bool getFromHasWhiteKingsideRookMoved();
	void setFromHasWhiteKingsideRookMoved(bool);
	//What was the previous player?
	char getPreviousPlayer();
	void setPreviousPlayer(char);

	Move castlingRookMove;
	void setCastlingRookMove(Move);
	

	std::string toString();
private:
	Move move;
	char capturedPiece;
	bool isEnPassantCapture;
	bool isCastlingCapture;
	

	//store the current en passant state
	int fromXEnPassant[2];
	int fromYEnPassant[2];

	int fromXWhiteEnPassant[2];
	int fromYWhiteEnPassant[2];


	//castling
	bool fromHasBlackKingMoved;
	bool fromHasWhiteKingMoved;
	bool fromHasBlackQueensideRookMoved;
	bool fromHasBlackKingsideRookMoved;
	bool fromHasWhiteQueensideRookMoved;
	bool fromHasWhiteKingsideRookMoved;

	//the current player.
	char previousPlayer;
};


