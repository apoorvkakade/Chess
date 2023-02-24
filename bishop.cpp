#include "stdafx.h"
#include<iostream>
#include<cmath>
#include"Board.h"
#include"bishop.h"

using namespace std;

bishop::bishop(int iInitial, int jInitial, int colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}



bool bishop::gen_test(int a, int b, int c)
{
	bool gentest = false;
	bool flag = true;

	if (m_Chessboard->getPiece(a, b) == nullptr || m_Chessboard->getPiece(a, b)->m_color != c)
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
	return (flag&&gentest);

}
void bishop::printPiece()
{
	if (m_color == 1)
	{
		cout << "Bis:W";
	}

	if (m_color == 0)
	{
		cout << "Bis:B";
	}
}

bool bishop::give_check(int a, int b, int c)
{
	return gen_test(a, b, !c);
}


bishop::~bishop()
{

}
