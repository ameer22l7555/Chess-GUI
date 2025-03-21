#pragma once
class KingThreatenedInfo {

private:
	int xPos, yPos;
	bool threatenedFromUp;
	bool threatenedFromDown;
	bool threatenedFromLeft;
	bool threatenedFromRight;

	bool threatenedFromUpLeft;
	bool threatenedFromUpRight;
	bool threatenedFromDownLeft;
	bool threatenedFromDownRight;



public:
	void setXPos(int x) { xPos = x; }
	void setYPos(int y) { yPos = y; }
	void setThreatenedFromUp(bool b) { threatenedFromUp = b; }
	void setThreatenedFromDown(bool b) { threatenedFromDown = b; }
	void setThreatenedFromLeft(bool b) { threatenedFromLeft = b; }
	void setThreatenedFromRight(bool b) { threatenedFromRight = b; }
	void setThreatenedFromUpLeft(bool b) { threatenedFromUpLeft = b; }
	void setThreatenedFromUpRight(bool b) { threatenedFromUpRight = b; }
	void setThreatenedFromDownLeft(bool b) { threatenedFromDownLeft = b; }
	void setThreatenedFromDownRight(bool b) { threatenedFromDownRight = b; }

	int getXPos() { return xPos; }
	int getYPos() { return yPos; }
	bool getThreatenedFromUp() { return threatenedFromUp; }
	bool getThreatenedFromDown() { return threatenedFromDown; }
	bool getThreatenedFromLeft() { return threatenedFromLeft; }
	bool getThreatenedFromRight() { return threatenedFromRight; }
	bool getThreatenedFromUpLeft() { return threatenedFromUpLeft; }
	bool getThreatenedFromUpRight() { return threatenedFromUpRight; }
	bool getThreatenedFromDownLeft() { return threatenedFromDownLeft; }
	bool getThreatenedFromDownRight() { return threatenedFromDownRight; }
};