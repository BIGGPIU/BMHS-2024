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

	Player player;
	player.lastHeldKey = NULL;

	const int maxarrow = 1;
	int arrowval = 0;
	int positions[] = { 60,100 };
}