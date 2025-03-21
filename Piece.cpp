#include "Piece.h"
#include "Window.h"
#include <stdio.h>

SDL_Texture* Piece::blackRook;
SDL_Texture* Piece::blackKnight;
SDL_Texture* Piece::blackBishop;
SDL_Texture* Piece::blackQueen;
SDL_Texture* Piece::blackKing;
SDL_Texture* Piece::blackPawn;
SDL_Texture* Piece::whiteRook;
SDL_Texture* Piece::whiteKnight;
SDL_Texture* Piece::whiteBishop;
SDL_Texture* Piece::whiteQueen;
SDL_Texture* Piece::whiteKing;
SDL_Texture* Piece::whitePawn;
std::map<char, SDL_Texture*> Piece::pieceTextures;

#include <iostream>

void Piece::loadPieceTextures() {

	SDL_Surface* tempSurface;
	tempSurface = IMG_Load("./images/blackRook.png");
	blackRook = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['r'] = blackRook;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/blackKnight.png");
	blackKnight = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['n'] = blackKnight;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/blackBishop.png");
	blackBishop = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['b'] = blackBishop;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/blackQueen.png");
	blackQueen = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['q'] = blackQueen;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/blackKing.png");
	blackKing = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['k'] = blackKing;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/blackPawn.png");
	blackPawn = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['p'] = blackPawn;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/whiteRook.png");
	whiteRook = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['R'] = whiteRook;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/whiteKnight.png");
	whiteKnight = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['N'] = whiteKnight;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/whiteBishop.png");
	whiteBishop = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['B'] = whiteBishop;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/whiteQueen.png");
	whiteQueen = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['Q'] = whiteQueen;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/whiteKing.png");
	whiteKing = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['K'] = whiteKing;
	SDL_FreeSurface(tempSurface);

	tempSurface = IMG_Load("./images/whitePawn.png");
	whitePawn = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	pieceTextures['P'] = whitePawn;
	SDL_FreeSurface(tempSurface);
	


	
}

void Piece::printPieceTextures() {

	std::cout << "Piece textures:";
	for (auto const& x : pieceTextures) {
		std::cout << x.first << ":" << x.second << "\n";
	}

	std::cout << std::endl;
}

SDL_Texture* Piece::getPieceTexture(char piece) {
	return pieceTextures[piece];
}


void Piece::cleanUp() {
	SDL_DestroyTexture(blackRook);
	SDL_DestroyTexture(blackKnight);
	SDL_DestroyTexture(blackBishop);
	SDL_DestroyTexture(blackQueen);
	SDL_DestroyTexture(blackKing);
	SDL_DestroyTexture(blackPawn);
	SDL_DestroyTexture(whiteRook);
	SDL_DestroyTexture(whiteKnight);
	SDL_DestroyTexture(whiteBishop);
	SDL_DestroyTexture(whiteQueen);
	SDL_DestroyTexture(whiteKing);
	SDL_DestroyTexture(whitePawn);
}