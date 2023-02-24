#pragma once
#ifndef pawn_H
#define pawn_H
#include"Piece.h"
class Board;

class pawn :public Piece
{
public:
	pawn(int a, int b, int c, Board* d);
	~pawn();
	bool gen_test(int a, int b, int c);
	bool give_check(int a, int b, int c);
	void printPiece();
};
#endif // !PAWN_H_