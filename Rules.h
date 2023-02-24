#pragma once
#ifndef RULES_H_
#define RULES_H_
class Board;

class Piece;

class Rules
{
public:
	Rules(Board*chessboard,Piece*chessgamepieces[32]);
	~Rules();
	bool Castle_Rule_l(bool w[3],bool b[3],int color);
	bool Castle_Rule_r(bool w[3], bool b[3], int color);
	bool Pawn_Rule(int color,int i,int j);
	bool checkforfinish(int color);
	void test();
	
private:
	
	Board * m_Chessboard;
	Piece*m_chessGamePieces[32];
};

#endif // !BOARD_H_