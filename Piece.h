#pragma once
#ifndef Piece_H_
#define Piece_H_
#include<string>

class Board;

class Piece
{
public:
	Piece(int i1, int j1, int colour, Board*chessBoard);
	virtual ~Piece();



	virtual void printPiece() = 0;

	int getI();

	int getJ();

	void setI(int i1);

	void setJ(int j1);

	virtual bool gen_test(int a, int b, int c) = 0;// a,b is the desired position to go and c the color of the piece
	virtual bool give_check(int a, int b, int c) = 0; //a,b the position of the king and c is kings color.
	int m_color;

protected:
	int m_i, m_j;

	Board* m_Chessboard;


};
#endif // !PIECE_H_