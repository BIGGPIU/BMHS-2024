#pragma once
#include "raylib.h"
#include "Timer.h"
#include <vector>

struct Piece {
	//position info
	int x;
	int y;
	int z;
	
	// piece info
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
	Rectangle block1Hitbox;
	Rectangle block2Hitbox;
	Rectangle block3Hitbox;
	Rectangle block4Hitbox;
};


struct Board {
	int rBound;
	int lBound;
	int uBound;
	int bBound; 

	std::vector<Rectangle> piecePositions;
};

struct Player {
	int lastHeldKey;
	Timer FFtimer;
	Timer spaceDelay;
};