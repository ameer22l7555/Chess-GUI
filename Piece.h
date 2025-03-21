#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iostream>
class Piece {
private:
	static SDL_Texture* blackRook;
	static SDL_Texture* blackKnight;
	static SDL_Texture* blackBishop;
	static SDL_Texture* blackQueen;
	static SDL_Texture* blackKing;
	static SDL_Texture* blackPawn;

	static SDL_Texture* whiteRook;
	static SDL_Texture* whiteKnight;
	static SDL_Texture* whiteBishop;
	static SDL_Texture* whiteQueen;
	static SDL_Texture* whiteKing;
	static SDL_Texture* whitePawn;
	static std::map<char, SDL_Texture*> pieceTextures;
public:
	static void loadPieceTextures();
	static SDL_Texture* getPieceTexture(char piece);
	static void printPieceTextures();
	static void cleanUp();

};

