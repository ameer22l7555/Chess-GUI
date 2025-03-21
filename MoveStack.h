#pragma once
#include "StoreMove.h"
#include <vector>

class MoveStack
{
private:
	//previous board states
	std::vector<StoreMove> previousMoves;

	//current index in the previous moves. Allows movement forward and backward.
	int currentIdx;
public:
	MoveStack();
	~MoveStack();

	void init();
	void pushMove(StoreMove move);
	StoreMove popMove();
	int getSize();
	StoreMove getLastMove();
	void clear();
};

