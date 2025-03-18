#include "oldmain2.h"


void Makegrid(int Piecesize);
void allocatePieces(Piece* piece);
void makePiece(Piece* piece);
void movePiece(int keyPressedKeyCode, Piece* piece, Board* board, Player* player);
bool canMove(Board* board, Piece* piece, int keyCode);
void canFall(Piece& piece, Board& board, double& beforeTime, double currentTime);
void makeOldPieces(Board* board);
void generateNewPiece(Piece& piece, Board& board);
//void makequeue(int* list);
//void BIGG_copy(int* mainList, int copyList[]);
//int Gameplayfunc();
//void Makepiece(Piece currentpiece);
//void getPieceLowestPosition(Piece currentpiece, int* lowestposition);
////void calculateGravity(Piece piece, double time);
//bool isOnFloor(Piece* piece, Board* board);