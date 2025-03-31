#pragma once

#include "Timer.h";


struct Board {
	int board[10][20];
};

struct Piece {
	//position info
	int x;
	int y;

	// pieceinfo
	int pieceSize;
	double gravity;
	double FFtime;
	int tetromino;
	int moves;

	//board info
	int lowestposition;
	double lockdowntimer;

	// Things for the blocks
	Rectangle block1;
	Rectangle block2;
	Rectangle block3;
	Rectangle block4;
};

struct Player {
	int lastHeldKey;
	Timer FFtimer;
	Timer spaceDelay;
};