#include <array>
#include <iterator>
#include <algorithm>
#include <raylib.h>
#include <vector>
#include "main.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include "utils.h"

//local functions n stuffs just for convienience
void setWH_Square(Rectangle* rect, int size);
// set Width AND Height, lets you customize width and height
void setWandH_Square(Rectangle* rect, int sizeX, int sizeY);
void setXY(Rectangle* rect, int x, int y);
void placePiece(Board& board, Piece& piece);
bool checkIfCanFall(Piece* piece, Board* board);
void allocatePieces(Piece* piece);
void generateNewPiece(Piece& piece, Board& board);


////typedef struct Piece {
////	int x_pos;
////	int y_pos;
////	int r_pos;
////};
//
//
//void BIGG_copy(int* mainList, int copyList[]);
//
//
//int bag[7] = { 1,2,3,4,5,6,7 };
//
//
//void makequeue(int* list) {
//	// returns nothign takes a pointer to a list so it can edit it 
//	for (int i = 0; i < 7; i++) {
//		int held = rand() % sizeof(bag);
//		list[i],list[held] = list[held],list[i];
//	}
//}
//
//void BIGG_copy(int* mainList, int copyList[]) {
//	for (int i = 0; i < sizeof(copyList); i++) {
//		mainList[i] = copyList[i];
//	}
//}
////
//int Gameplayfunc() {
//	//int visqueue[7];
//	//int queue[3][7] = { }; // L S Z R O L T
//	//BIGG_copy(queue[0], bag);
//	//BIGG_copy(queue[1], bag);
//	//BIGG_copy(queue[2], bag);
//	//// fills x with copies of bag
//
//	//makequeue(queue[0]);
//	//makequeue(queue[1]);
//	//makequeue(queue[2]);
//
//
//	///*while(true) {*/
//	//if (vpr == vpmax) {
//	//	vpr = 0;
//	//}
//	//else {
//	//	vpr++;
//	//}
//	//if (vpl == vpmax) {
//	//	vpl = 0;
//	//}
//	//else {
//	//	vpl++;
//	//}
//
//	
//	
//
//	/*int queue[3][7] = { {1,2,3,4,5,6,7},{7,6,5,4,3,2,1},{1,2,3,4,5,6,7} };
//	
//	int visqueue[7];
//
//	std::copy(std::begin(queue[0]),std::end(queue[0]),std::begin(visqueue));
//
//	Vector2 Piecepos = { (float)500 / 2, (float)500 / 2 };*/
//	
//	// BIGG_copy(visqueue,queue[0]);
//
//	//std::cout << queue << std::endl;
//
//	//std::cout << visqueue << std::endl;
//
//
//	//}
//	return 0;
//
//
//}
//
//
//
void Makegrid(int Piecesize) {
	int i = 1;
	while (i != 22) {
		DrawRectangle(50, i*Piecesize, Piecesize * 10, 1, WHITE);
		i++;
	}
	i = 1;
	while (i != 12) {
		DrawRectangle(Piecesize * i, 50, 1, Piecesize * 20, WHITE);
		i++;
	}
	DrawRectangle(Piecesize * 11, 50, Piecesize*6, Piecesize*8, WHITE);
	DrawRectangle(Piecesize * 11.5, Piecesize*2, Piecesize * 5, Piecesize * 6.5, BLACK);
	DrawText("Next", Piecesize * 11.5, Piecesize * 1, 32, BLACK);
}

void movePiece(int keyPressedKeyCode, Piece* piece, Board* board, Player* player) {
	// use GetKeyPressed for keyPressedKeyCode. or else..
	/*std::cout << keyPressedKeyCode << std::endl;
	std::cout << piece->FFtime << std::endl;
	std::cout << player->lastHeldKey << std::endl;*/
	//std::cout << GetElapsed(player->FFtimer) <<  std::endl;
	switch (keyPressedKeyCode) {
		case (KEY_LEFT): {
			if (player->lastHeldKey == keyPressedKeyCode && TimerDone(player->FFtimer)) {
				piece->x += -50;
				player->lastHeldKey = keyPressedKeyCode;
			}
			else if (keyPressedKeyCode == KEY_LEFT && player->lastHeldKey != keyPressedKeyCode) {
				piece->x += -50;
				player->lastHeldKey = keyPressedKeyCode;
				StartTimer(&player->FFtimer,piece->FFtime);
			}
			break;
		};
		case (KEY_RIGHT): {
			if (player->lastHeldKey == keyPressedKeyCode && TimerDone(player->FFtimer)) {
				piece->x += 50;
				player->lastHeldKey = keyPressedKeyCode;
			}
			else if (keyPressedKeyCode == KEY_RIGHT && player->lastHeldKey != keyPressedKeyCode) {
				
				piece->x += 50;
				player->lastHeldKey = keyPressedKeyCode;
				StartTimer(&player->FFtimer, piece->FFtime);
			}
			break;
		};
		case (KEY_DOWN): {

		};
		case (KEY_SPACE): {
			std::cout << "KEY_SPACE" << std::endl;
			if (player->lastHeldKey == KEY_SPACE && TimerDone(player->spaceDelay)) {
				player->lastHeldKey = KEY_SPACE;
				placePiece(*board, *piece);
				generateNewPiece(*piece, *board);

			}
			else if (player->lastHeldKey != KEY_SPACE) {
				player->lastHeldKey = KEY_SPACE;
				placePiece(*board, *piece);
				generateNewPiece(*piece, *board);
				StartTimer(&player->spaceDelay, 0.1);
			}
			
		};
		default: {
			StartTimer(&player->FFtimer, 999); // you're BMing me if you actually somehow make this timer end
			if (player->lastHeldKey == KEY_SPACE) {
				player->lastHeldKey = KEY_SPACE;
			}
			else {
				player->lastHeldKey = 0;
			}
		}
	}
}


bool pieceCollides(Board& board, Piece& piece) {
	std::cout << "piececollides" << std::endl;
	int i = 0;
	for (Rectangle rect : board.piecePositions)
	{
		std::cout << rect.x << std::endl;
		std::cout << rect.y << std::endl;
		// I dont think I need elif becuase it would escape if it were true anyways
		std::cout << CheckCollisionRecs(rect, piece.block1Hitbox) << std::endl;
		std::cout << CheckCollisionRecs(rect, piece.block2Hitbox) << std::endl;
		std::cout << CheckCollisionRecs(rect, piece.block3Hitbox) << std::endl;
		std::cout << CheckCollisionRecs(rect, piece.block4Hitbox) << std::endl;
		if (CheckCollisionRecs(rect, piece.block1Hitbox)) { return 1; };
		if (CheckCollisionRecs(rect, piece.block2Hitbox)) { return 1; };
		if (CheckCollisionRecs(rect, piece.block3Hitbox)) { return 1; };
		if (CheckCollisionRecs(rect, piece.block4Hitbox)) { return 1; };
	}
	return 0;

}

void generateNewPiece(Piece& piece, Board& board) {
	piece.x = board.rBound / 2;
	piece.x -= 50;
	piece.y = board.uBound;
	piece.tetromino = 1;
}



void placePiece(Board& board, Piece& piece) {
	 
	while (true) {
		if (pieceCollides(board, piece)) {
			break;
		}
		if (!checkIfCanFall(&piece, &board)) {
			break;
		}
		piece.y += 50;
		allocatePieces(&piece);
	}
	board.piecePositions.insert(board.piecePositions.begin(), (piece.block1));
	board.piecePositions.insert(board.piecePositions.begin(),(piece.block2));
	board.piecePositions.insert(board.piecePositions.begin(),(piece.block3));
	board.piecePositions.insert(board.piecePositions.begin(),(piece.block4));
	std::cout << sizeof(board.piecePositions) << std::endl;
}

bool canMove(Board* board, Piece* piece, int keyCode) {
	/*std::cout << piece->x + 100 << std::endl;
	std::cout << piece->x - 50 << std::endl;
	std::cout << board->lBound << std::endl;
	std::cout << board->rBound << std::endl;*/
	if ((piece->x + 100) == board->rBound && keyCode == KEY_RIGHT) {
		return 0;
	}
	else if ((piece->x) == board->lBound && keyCode == KEY_LEFT) {
		return 0;
	}
	else {
		return 1;
	}
}



void canFall(Piece& piece, Board& board, double& beforeTime, double currentTime)
{
	/*std::cout << "bBound " << board.bBound << std::endl;
	std::cout << "piece1 " <<piece.block1.y << std::endl;
	std::cout << "piece2 " <<piece.block2.y << std::endl;
	std::cout << "piece3 " <<piece.block3.y << std::endl;
	std::cout << "piece4 " <<piece.block4.y << std::endl;*/
	if ((piece.block1.y + piece.block1.height*2) >= board.bBound || (piece.block2.y + piece.block2.height*2) >= board.bBound || (piece.block3.y + piece.block3.height*2) >= board.bBound || (piece.block4.y + piece.block4.height*2) >= board.bBound) {
	
	}
	else {
		if (pieceCollides(board,piece)) {

		}
		else {
			piece.y += 50;
			beforeTime = currentTime;
		}
	}
}

bool checkIfCanFall(Piece* piece, Board* board){
	std::cout << "check if can fall" << std::endl;

	std::cout << "bBound " << board->bBound << std::endl;
	std::cout << "piece1 " << piece->block1.y << std::endl;
	std::cout << "piece2 " << piece->block2.y << std::endl;
	std::cout << "piece3 " << piece->block3.y << std::endl;
	std::cout << "piece4 " << piece->block4.y << std::endl;

	if ((piece->block1.y + piece->block1.height * 2) >= board->bBound || (piece->block2.y + piece->block2.height * 2) >= board->bBound || (piece->block3.y + piece->block3.height * 2) >= board->bBound || (piece->block4.y + piece->block4.height * 2) >= board->bBound) {
		return 0;
	}
	else {
		return 1;
	}
}

void makeOldPieces(Board* board) {
	for (Rectangle rect : board->piecePositions) {
		DrawRectangleRec(rect,GRAY);
	}
}

void makePiece(Piece* piece) {
	Color static color;
	switch (piece->tetromino) {
		case (1): {
			color = BLUE;
		}
	}
	
	DrawRectangleRec(piece->block1Hitbox, RED);
	DrawRectangleRec(piece->block2Hitbox, RED);
	DrawRectangleRec(piece->block3Hitbox, RED);
	DrawRectangleRec(piece->block4Hitbox, RED);
	DrawRectangleRec(piece->block1, color);
	DrawRectangleRec(piece->block2, color);
	DrawRectangleRec(piece->block3, color);
	DrawRectangleRec(piece->block4, color);
	/*std::cout << "drawing rect " << std::endl;
	std::cout << "x " << piece->x << std::endl;
	std::cout << "y " << piece->y<< std::endl;
	std::cout << "size " << piece->pieceSize << std::endl;
	std::cout << "block4 x " << piece->block4.x << std::endl;
	std::cout << "block4 y " << piece->block4.y << std::endl;
	std::cout << "block4 W " << piece->block4.width << std::endl;
	std::cout << "block4 H " << piece->block4.height << std::endl;
	std::cout << "block3 x " << piece->block3.x << std::endl;
	std::cout << "block3 y " << piece->block3.y << std::endl;
	std::cout << "block4 W " << piece->block3.width << std::endl;
	std::cout << "block4 H " << piece->block3.height << std::endl;
	std::cout << "block2 x " << piece->block2.x << std::endl;
	std::cout << "block2 y " << piece->block2.y << std::endl;
	std::cout << "block4 W " << piece->block2.width << std::endl;
	std::cout << "block4 H " << piece->block2.height << std::endl;
	std::cout << "block1 x " << piece->block1.x << std::endl;
	std::cout << "block1 y " << piece->block1.y << std::endl;
	std::cout << "block4 W " << piece->block1.width << std::endl;
	std::cout << "block4 H " << piece->block1.height << std::endl;*/
}

void allocatePieces(Piece* piece) {

	switch (piece->tetromino) {
		case (1): {
			setXY(&piece->block1, piece->x, piece->y);
			setXY(&piece->block2, piece->x, piece->y + piece->pieceSize);
			setXY(&piece->block3, piece->x, piece->y + piece->pieceSize + piece->pieceSize);
			setXY(&piece->block4, piece->x, piece->y + piece->pieceSize + piece->pieceSize + piece->pieceSize); // this is good code trust me 
			setXY(&piece->block1Hitbox, piece->x, piece->y - 2);
			setXY(&piece->block2Hitbox, piece->x, piece->y + piece->pieceSize - 2);
			setXY(&piece->block3Hitbox, piece->x, piece->y - 2 + piece->pieceSize + piece->pieceSize);
			setXY(&piece->block4Hitbox, piece->x, piece->y - 2 + piece->pieceSize + piece->pieceSize + piece->pieceSize);


			break;
		}
	}
	setWH_Square(&piece->block1, piece->pieceSize); 
	
	setWH_Square(&piece->block2, piece->pieceSize);
	setWH_Square(&piece->block3, piece->pieceSize);
	setWH_Square(&piece->block4, piece->pieceSize);
	setWandH_Square(&piece->block1Hitbox, piece->pieceSize ,piece->pieceSize + 4);
	setWandH_Square(&piece->block2Hitbox, piece->pieceSize ,piece->pieceSize + 4);
	setWandH_Square(&piece->block3Hitbox, piece->pieceSize ,piece->pieceSize + 4);
	setWandH_Square(&piece->block4Hitbox, piece->pieceSize ,piece->pieceSize + 4);
	/*std::cout << "x "  << piece->x << std::endl;
	std::cout << "y "  << piece->y << std::endl;
	std::cout << "size " << piece->pieceSize << std::endl;
	std::cout << "block4 x " << piece->block4.x << std::endl;
	std::cout << "block4 y " << piece->block4.y << std::endl;
	std::cout << "block4 W " << piece->block4.width << std::endl;
	std::cout << "block4 H " << piece->block4.height << std::endl;
	std::cout << "block3 x " << piece->block3.x << std::endl;
	std::cout << "block3 y " << piece->block3.y << std::endl;
	std::cout << "block4 W " << piece->block3.width << std::endl;
	std::cout << "block4 H " << piece->block3.height << std::endl;
	std::cout << "block2 x " << piece->block2.x << std::endl;
	std::cout << "block2 y " << piece->block2.y << std::endl;
	std::cout << "block4 W " << piece->block2.width << std::endl;
	std::cout << "block4 H " << piece->block2.height << std::endl;
	std::cout << "block1 x " << piece->block1.x << std::endl;
	std::cout << "block1 y " << piece->block1.y << std::endl;
	std::cout << "block4 W " << piece->block1.width << std::endl;
	std::cout << "block4 H " << piece->block1.height << std::endl;*/
}

void setXY(Rectangle *rect, int x, int y) {
	rect->x = x;
	rect->y = y;
}

void setWH_Square(Rectangle *rect, int size) {
	// set width and height whenever you want to make a square
	rect->width = size;
	rect->height = size;
}

void setWandH_Square(Rectangle* rect, int sizeX,int sizeY) {
	// set width and height whenever you want to make a square
	rect->width = sizeX;
	rect->height = sizeY;
}

//
//void getPieceLowestPosition(Piece currentpiece, int* lowestposition) {
//	switch (currentpiece.tetromino) {
//		case (1):
//			*lowestposition = currentpiece.y + 150;
//	}
//}
//
//void placePiece(Piece currentpiece) {
//	/*switch (currentpiece.tetromino) {
//	case (1):
//		int a = 0;
//	}*/
//}
//
//
//void Makepiece(Piece currentpiece) {
//	//std::string a = std::to_string(currentpiece.x);
//	//DrawText(a, 200, 200, 16, WHITE);
//	//DrawText(a, 400, 400, 16, WHITE);
//	// 
//	// ngl I Forgot what this even did
//	//const char* datax = reinterpret_cast<const char*>(&currentpiece.x); //convert to a char pointer
//
//	//const char* datay = reinterpret_cast<const char*>(&currentpiece.y); //convert to a char pointer
//	//const char* dataps = reinterpret_cast<const char*>(&currentpiece.piecesize); //convert to a char pointer
//	
//	switch (currentpiece.tetromino) {
//		case (1):
//			DrawText("case 1", 900, 500, 16, WHITE);
//			//DrawText(datax, 900, 520, 16, WHITE);
//			//DrawText(datay, 900, 540, 16, WHITE);
//			//DrawText(dataps, 900, 560, 16, WHITE);
//			//std::cout << "currentpiece.x" << currentpiece.x << std::endl;
//			//std::cout << "currentpiece.y" << currentpiece.y << std::endl;
//			//std::cout << "currentpiece.piecesize" << currentpiece.piecesize << std::endl;
//			DrawRectangle(currentpiece.x, currentpiece.y, currentpiece.piecesize, currentpiece.piecesize, BLUE);
//			DrawRectangle(currentpiece.x, currentpiece.y+50, currentpiece.piecesize, currentpiece.piecesize, BLUE);
//			DrawRectangle(currentpiece.x, currentpiece.y+100, currentpiece.piecesize, currentpiece.piecesize, BLUE);
//			DrawRectangle(currentpiece.x, currentpiece.y + 150, currentpiece.piecesize, currentpiece.piecesize, BLUE);
//	}
//}
//
////void calculateGravity(Piece piece, double time) {
////	if (int(time / piece.gravity) == time / piece.gravity) {
////		piece.y += 50;
////	}
////}