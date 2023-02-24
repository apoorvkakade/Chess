#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "knight.h"
#include"Board.h"

using namespace std;



knight::knight(int iInitial, int jInitial, int colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}

bool knight::gen_test(int a, int b, int c)
{
	bool gen_test=false;

	if (m_Chessboard->getPiece(a, b) == nullptr || m_Chessboard->getPiece(a, b)->m_color != c)
	{

		if (abs(b - m_j) == 1 || abs(a - m_i) == 1)
		{
			if (abs(b - m_j) + abs(a - m_i) == 3)
			{
				gen_test = true;
			}
			
		}
	}
	return gen_test;

}
bool knight::give_check(int a, int b, int c) // here c is the color of the king.
{
	return gen_test(a, b, !c);
}
void knight::printPiece()
{
	if (m_color == 1)
	{
		cout << "Kni:W";
	}

	if (m_color == 0)
	{
		cout << "Kni:B";
	}
}


knight::~knight()
{

}