#include "MoveStack.h"

MoveStack::MoveStack()
{
	currentIdx = -1;
}


MoveStack::~MoveStack()
{
}

void MoveStack::init() {
	currentIdx = -1;
	previousMoves.clear();
}

//Push a move onto the stack. Increments the currentidx
void MoveStack::pushMove(StoreMove move) {
	//Need to also make sure that the capacity is correct.
	if (previousMoves.size() > 0 && currentIdx < previousMoves.size() - 1) {
		//currentIdx is smaller than container size.
		//Need to chop off container from currentIdx onwards.
		//Use a std:vector iterator to erase from begin + currentIdx + 1 to end().
		//if container size is 10, and currentIdx = 5, then we erase from begin+6 to end() (exclusive)
		//7, 8, 9
		// 0 1 2 3 4 5 6 7 8 9
		previousMoves.erase(previousMoves.begin() + currentIdx + 1, previousMoves.end());
	}
	previousMoves.push_back(move);
	currentIdx++;
}

StoreMove MoveStack::popMove() {

	if (currentIdx < 0 || previousMoves.size() == 0 || previousMoves.size() <= currentIdx) {
		std::cout << "Error: movestack is bad. Size = " << previousMoves.size() << " currentidx = " << currentIdx << std::endl;
		StoreMove sm;
		return sm;
	}
	
	StoreMove returnMove = previousMoves[currentIdx];
	currentIdx--;
	return returnMove;
}

int MoveStack::getSize() {
	return previousMoves.size();
}


StoreMove MoveStack::getLastMove() {
	if (previousMoves.size() > 0) {
		return previousMoves[previousMoves.size() - 1];
	}
	StoreMove sm;
	return sm;
}

void MoveStack::clear() {
	previousMoves.clear();
	currentIdx = -1;
}