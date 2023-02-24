#pragma once
#ifndef knight_H
#define knight_H
#include"Piece.h"
class Board;

class knight :public Piece
{
public:
	knight(int a, int b, int c, Board* d);
	~knight();
	bool gen_test(int a, int b, int c);
	bool give_check(int a, int b, int c);

	void printPiece();
};
#endif // !KNIGHT_H_