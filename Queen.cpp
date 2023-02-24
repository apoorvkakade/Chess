#include "stdafx.h"
#include<iostream>
#include"Queen.h"
#include"Board.h"

using namespace std;

Queen::Queen(int iInitial, int jInitial, int colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}

//Queen as bishop
bool Queen::gen_test(int a, int b, int c)
{
	bool gentest = false;
	bool flag = true;

	bool x = false;
	bool y = false;
	bool z = false;

	if ((m_Chessboard->getPiece(a, b) == nullptr) ||(m_Chessboard->getPiece(a,b)!=nullptr&& m_Chessboard->getPiece(a, b)->m_color != c))
	{
		if (abs(a - m_i) == abs(b - m_j))

		{
			gentest = true;

			if (a > m_i && b> m_j)
			{
				int l = m_j + 1;

				for (int k = m_i + 1; k < a; k++)
				{
					if (m_Chessboard->getPiece(k, l) != nullptr)
					{
						flag = false;
					}
					l = l + 1;
				}
			}
			else if (a < m_i && b< m_j)
			{
				int l = m_j - 1;

				for (int k = m_i - 1; k > a; k--)
				{
					if (m_Chessboard->getPiece(k, l) != nullptr)
					{
						flag = false;
					}
					l = l - 1;
				}
			}
			else if (a > m_i && b< m_j)
			{
				int l = m_j - 1;

				for (int k = m_i + 1; k < a; k++)
				{
					if (m_Chessboard->getPiece(k, l) != nullptr)
					{
						flag = false;
					}
					l = l - 1;
				}
			}

			else if (a < m_i && b> m_j)
			{
				int l = m_j + 1;

				for (int k = m_i - 1; k > a; k--)
				{
					if (m_Chessboard->getPiece(k, l) != nullptr)
					{
						flag = false;
					}
					l = l + 1;
				}
			}

		}



	}
	x = gentest && flag;

	
	
	//Queen as Rook

	int s = 0;

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

		if (a == m_i && b < m_j)
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

		if (b == m_j && a < m_i)
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
			y = true;
		}
	}

	else
		y = false;

	z = x || y;
	return z;

}

bool Queen::give_check (int a, int b, int c)
{

	return gen_test(a, b, !c);
}


void Queen::printPiece()
{
	if (Piece::m_color == 1)
	{
		cout << "Que:W";
	}

	if (Piece::m_color == 0)
	{
		cout << "Que:B";
	}
}


Queen::~Queen()
{

}
