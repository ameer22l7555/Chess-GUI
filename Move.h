#pragma once
#include "Box.h"

struct Move {
	Box fromBox;
	Box toBox;
	bool isEnPassant;
	bool isCastling;
};
