#pragma once
#ifndef bishop_H
#define bishop_H
#include"Piece.h"
class Board;
class bishop :public Piece
{
public:
	bishop(int a, int b, int c, Board* d);
	~bishop();
	bool gen_test(int a, int b, int c);
	bool give_check(int a, int b, int c);
	void printPiece();
};
#endif // !BISHOP_H_