#pragma once
#ifndef Queen_H
#define Queen_H
#include"Piece.h"
class Board;


class Queen :public Piece
{
public:
	Queen(int a, int b, int c, Board* d);
	~Queen();
	bool gen_test(int a, int b, int c);
	bool give_check(int a, int b, int c);
	void printPiece();
};
#endif // !QUEEN_H_