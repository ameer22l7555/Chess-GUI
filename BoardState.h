#pragma once
class BoardState
{
private:
	char board[8][8];
	//e means empty. lowercase piece means black, uppercase piece means white.
	//the player with the lowercase piece moves first (black)
	char currentTurn;
	//Castling stuff
	bool hasBlackKingMoved;
	bool hasWhiteKingMoved;
	bool hasBlackQueensideRookMoved;
	bool hasBlackKingsideRookMoved;
	bool hasWhiteQueensideRookMoved;
	bool hasWhiteKingsideRookMoved;

	//en passant stuff.
	int enPassantXPos[2];
	int enPassantYPos[2];
	int enPassantXPosWhite[2];
	int enPassantYPosWhite[2];
public:
	BoardState();
	~BoardState();

void init();
	//board getters and setters
	char getPieceAt(int x, int y);
	void setPieceAt(int x, int y, char piece);
	

	//En passant stuff
	void setEnPassantPos(int, int,int);
	void setWhiteEnPassantPos(int, int, int);
	void clearEnPassant();
	void clearWhiteEnPassant();
	int getEnPassantXPos(int idx);
	int getEnPassantYPos(int idx);
	int getWhiteEnPassantXPos(int idx);
	int getWhiteEnPassantYPos(int idx);

	//Gets and sets the current turn
	char getCurrentTurn();
	void setCurrentTurn(char);


	//castling getter/setter
	bool getBlackKingMoved();
	void setBlackKingMoved(bool);
	bool getWhiteKingMoved();
	void setWhiteKingMoved(bool);
	bool getBlackQueensideRookMoved();
	void setBlackQueensideRookMoved(bool);
	bool getBlackKingsideRookMoved();
	void setBlackKingsideRookMoved(bool);
	bool getWhiteQueensideRookMoved();
	void setWhiteQueensideRookMoved(bool);
	bool getWhiteKingsideRookMoved();
	void setWhiteKingsideRookMoved(bool);

};