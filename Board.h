#pragma once
#ifndef BOARD_H_
#define BOARD_H_

class Piece;
class Table;
class Board
{
public:
	Board();
	~Board();
	void display_board();
	void set(int i, int j, Piece* piece);
	Piece* getPiece(int i, int j);
private:
	Piece * m_piecePosition[8][8];
	

};

#endif // !BOARD_H_