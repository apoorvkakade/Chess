#include "stdafx.h"
#include <iostream>
#include "rook.h"
#include"Board.h"

using namespace std;



rook::rook(int iInitial, int jInitial, int colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}
bool rook::gen_test(int a, int b, int c)
{
	int s = 0;
	bool x = false;
	if ((a == m_i || b == m_j) && (m_Chessboard->getPiece(a, b) == nullptr ||(m_Chessboard->getPiece(a,b)!=nullptr&& m_Chessboard->getPiece(a, b)->m_color != c)))
	{
		if (a == m_i && b > m_j)
		{
			for (int k = m_j + 1; k < b; k++)
			{
				if (m_Chessboard->getPiece(m_i, k) == nullptr)
				{
					s = s + 1;
				}
			}
		}

		if (a == m_i && b<m_j)
		{
			for (int k = m_j - 1; k > b; k--)
			{
				if (m_Chessboard->getPiece(m_i, k) == nullptr)
				{
					s = s + 1;
				}
			}
		}

		if (b == m_j && a > m_i)
		{
			for (int k = m_i + 1; k < a; k++)
			{
				if (m_Chessboard->getPiece(k, m_j) == nullptr)
				{
					s = s + 1;
				}
			}
		}

		if (b == m_j && a<m_i)
		{
			for (int k = m_i - 1; k > a; k--)
			{
				if (m_Chessboard->getPiece(k, m_j) == nullptr)
				{
					s = s + 1;

				}
			}
		}
		if (s == b - m_j - 1 || s == m_j - b - 1 || s == a - m_i - 1 || s == m_i - a - 1)
		{
			x = true;;
		}
	}
	
	return x;
}

bool rook::give_check(int a, int b, int c) //c is the color of the king of opposite color.
{
	return gen_test(a, b, !c);
}

void rook::printPiece()
{
	if (m_color == 1)
	{
		cout << "Roo:W";
	}

	if (m_color == 0)
	{
		cout << "Roo:B";
	}
}


rook::~rook()
{

}