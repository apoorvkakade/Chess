#pragma once
#ifndef Table_H_
#define Table_H_
class Piece;
class Board;

class Table
{
private:
	
	Board*m_Chessboard;
	int cell[3][3];
	Piece*pieces[32];
public:
	Table(Board*b,Piece*x[32]);
	void Displaytable();
	void calculate();


};

#endif // !Table_H_
