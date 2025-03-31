//#include "raylib.h";
//#include "oldmain2.h";
//#include "timer.h";
//#include "oldGameplay.h"
//#include <vector>;
//#include <stdio.h>
//#include <iostream>
//
//
//typedef enum Gamescreen { TITLE, CHOOSE, GAMEPLAY, GAMEOVER } Gamescreen;
//enum Lastheld { LEFT, RIGHT, DOWN, NONE };
//
//int main(void) {
//	const int screenWidth = GetScreenWidth();
//	const int screenHeight = GetScreenHeight();
//	
//	Gamescreen currentscreen = TITLE;
//
//	// Information about the user
//	Player player;
//	player.lastHeldKey = NULL;
//
//	// menu variables 
//	
//	const int maxarrow = 1;
//	int arrowval = 0;
//	int positions[] = { 60,100 };
//
//	// piece and board information
//
//	Piece piece;
//	piece.pieceSize = 50;
//	piece.FFtime = 0.2;
//	piece.gravity = 0.5;
//
//	Board board;
//	board.lBound = piece.pieceSize;
//	board.rBound = piece.pieceSize * 12;
//	board.bBound = piece.pieceSize * 22;
//	board.uBound = piece.pieceSize;
//	
//	generateNewPiece(piece, board);
//
//	// timers
//
//	Timer lockdown;
//	double beforeTime = 0;
//	double currentTime;
//
//	// mainloop
//
//	int keyCode = 0;
//	InitWindow(screenWidth, screenHeight, "Tetris - BMHS");
//	ToggleFullscreen();
//	SetTargetFPS(60);
//	
//	while (!WindowShouldClose()) {
//		switch (currentscreen) {
//		case (TITLE):
//			if (IsKeyPressed(KEY_ENTER)) {
//				currentscreen = CHOOSE;
//			}break;
//		case (CHOOSE):
//			if (IsKeyPressed(KEY_UP)) {
//				if (arrowval != 0) {
//					arrowval += -1;
//				}
//			}
//			if (IsKeyPressed(KEY_DOWN)) {
//				if (arrowval != maxarrow) {
//					arrowval += 1;
//				}
//			}
//			if (IsKeyPressed(KEY_ENTER)) {
//				if (arrowval == 1) {
//					currentscreen = GAMEPLAY;
//				}
//				if (arrowval == 0) {
//					OpenURL("https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS_-4-SL59qwne5iTdsq7mx1Oz97BC2-kq0lFhby2ik8tjQQ5Ix6YPCJLRXgL8N-7UjStw&usqp=CAU");
//					CloseWindow();
//					// # trolled
//				}
//			}
//		}
//		BeginDrawing();
//		ClearBackground(BLACK);
//		switch (currentscreen) {
//		case(TITLE):
//			DrawText("Blockstack", 20, 20, 32, WHITE);
//			DrawText("Hit Enter To Start", 20, 60, 32, WHITE); break;
//		case(CHOOSE): {
//			DrawText("CHOOSE YOUR MODE", 20, 20, 32, WHITE);
//			DrawText("Marathon", 20, 60, 32, WHITE);
//			DrawText("40L", 20, 100, 32, WHITE);
//			DrawText("<", 300, positions[arrowval], 32, WHITE); break;
//			//DrawText(TextFormat("%02i", arrowval), 500, 500, 32, WHITE); break;
//		}
//		case(GAMEPLAY): {
//			const char x = char(sizeof(board.piecePositions) / sizeof(board.piecePositions[0]));
//			//std::cout << sizeof(board.piecePositions) / sizeof(board.piecePositions[0]) << std::endl;
//			std::cout << x << std::endl;
//			DrawText(&x, 900, 50, 32, WHITE);
//			currentTime = GetTime();
//			Makegrid(piece.pieceSize);
//			makeOldPieces(&board);
//
//			if (IsKeyDown(KEY_RIGHT)) { keyCode = KEY_RIGHT; }
//			else if (IsKeyDown(KEY_LEFT)) { keyCode = KEY_LEFT; }
//			else if (IsKeyDown(KEY_DOWN)) { keyCode = KEY_DOWN; }
//			else if (IsKeyDown(KEY_SPACE)) { keyCode = KEY_SPACE; }
//			else { keyCode = 0; };
//
//			if (canMove(&board, &piece, keyCode)) {
//				movePiece(keyCode, &piece, &board, &player);
//			}
//
//			if (currentTime > beforeTime + piece.gravity) {
//				canFall(piece, board, beforeTime, currentTime); // this is called once before the rectangles are placed on the board
//			}
//
//			
//			
//			allocatePieces(&piece);
//			makePiece(&piece);
//		}
//		}
//		DrawText("Made By The 2024-2025 BMHS Coding Club", GetScreenWidth() - 700, GetScreenHeight() - 50, 32, WHITE);
//		EndDrawing();
//	}
//	
//	return 0;
//}
//
//
