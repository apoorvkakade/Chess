#pragma once
#ifndef King_H
#define King_H
#include"Piece.h"
class Board;
class King :public Piece
{
public:
	King(int a, int b, int c, Board* d);
	~King();
	bool gen_test(int a, int b, int c);
	void printPiece();
	bool isunder_check(int i,int j,int color);
	bool check_mate();
	bool give_check(int a, int b, int c);

};
#endif // !KING_H_