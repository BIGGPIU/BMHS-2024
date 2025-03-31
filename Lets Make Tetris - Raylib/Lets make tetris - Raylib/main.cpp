#include "raylib.h";
#include "main.h";
#include "timer.h";
#include "Gameplay.h"
#include <vector>;
#include <stdio.h>
#include <iostream>


typedef enum Gamescreen { TITLE, CHOOSE, GAMEPLAY, GAMEOVER } Gamescreen;
enum Lastheld { LEFT, RIGHT, DOWN, NONE };

int main(void) {
	const int screenWidth = GetScreenWidth();
	const int screenHeight = GetScreenHeight();

	Gamescreen currentscreen = TITLE;

	// player information

	Player player;
	player.lastHeldKey = NULL;

	// piece and board information

	const int maxarrow = 1;
	int arrowval = 0;
	int positions[] = { 60,100 };



	// timers

	Timer lockdown;
	double beforeTime = 0;
	double currentTime;


	//mainloop

	int keyCode = 0;

	InitWindow(screenWidth, screenHeight, "TETRIS - BMHS 2025");
	ToggleFullscreen();
	SetTargetFPS(60);


	while (!WindowShouldClose()) {
		switch (currentscreen) {
		case (TITLE):
			if (IsKeyPressed(KEY_ENTER)) {
				currentscreen = CHOOSE;
			}break;
		case (CHOOSE):
			if (IsKeyPressed(KEY_UP)) {
				if (arrowval != 0) {
					arrowval += -1;
				}
			}
			if (IsKeyPressed(KEY_DOWN)) {
				if (arrowval != maxarrow) {
					arrowval += 1;
				}
			}
			if (IsKeyPressed(KEY_ENTER)) {
				if (arrowval == 1) {
					currentscreen = GAMEPLAY;
				}
				if (arrowval == 0) {
					OpenURL("https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS_-4-SL59qwne5iTdsq7mx1Oz97BC2-kq0lFhby2ik8tjQQ5Ix6YPCJLRXgL8N-7UjStw&usqp=CAU");
					CloseWindow();
					// # trolled
				}
			}
		}
		BeginDrawing();
		ClearBackground(BLACK);
		switch (currentscreen) {
		case(TITLE):
			DrawText("Blockstack", 20, 20, 32, WHITE);
			DrawText("Hit Enter To Start", 20, 60, 32, WHITE); break;
		case(CHOOSE): {
			DrawText("CHOOSE YOUR MODE", 20, 20, 32, WHITE);
			DrawText("Marathon", 20, 60, 32, WHITE);
			DrawText("40L", 20, 100, 32, WHITE);
			DrawText("<", 300, positions[arrowval], 32, WHITE); break;
			//DrawText(TextFormat("%02i", arrowval), 500, 500, 32, WHITE); break;
		}
		}
		EndDrawing();
	}
}
