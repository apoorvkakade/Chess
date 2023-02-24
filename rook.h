#pragma once
#ifndef rook_H
#define rook_H
#include"Piece.h"
class Board;
class rook :public Piece
{
public:
	rook(int a, int b, int c, Board* d);
	~rook();
	bool gen_test(int a, int b, int c);
	bool give_check(int a, int b, int c);
	void printPiece();
};
#endif // !ROOK_H_