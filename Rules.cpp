#include "stdafx.h"
#include<iostream>
#include"Board.h"
#include "Rules.h"
#include"King.h"
#include"rook.h"
#include"game.h"
using namespace std;
Rules::Rules(Board*chessboard,Piece*chessgamepieces[32])
{
	m_Chessboard = chessboard;
	for (int i = 0; i < 32; i++)
	{
		m_chessGamePieces[i] = chessgamepieces[i];
	}
}


bool Rules::Castle_Rule_l(bool a[3], bool b[3], int color)//a[0] for left rook,a[1] for king
{

	game g1;
	//m_chessGamePieces[8] = m_Chessboard->getPiece(4, 0);
	//m_chessGamePieces[24] = m_Chessboard->getPiece(4, 7);
	/*if (m_chessGamePieces[8] == nullptr)
	{
		cout << "p";
	}*/
	King*k1 = static_cast<King*>(m_chessGamePieces[8]);
	
	King*k2 = static_cast<King*>(m_chessGamePieces[24]);
	bool Test[4] = { false,true,false,true };
	if (color == 1)
	{

		if (a[0] == true && a[1] == true)
		{
			if (m_Chessboard->getPiece(0, 0) != nullptr)
			{
				if (m_Chessboard->getPiece(0, 0) == m_chessGamePieces[14])
				{
					for (int i = 1; i < 4; i++)
					{
						if (m_Chessboard->getPiece(i, 0) != nullptr)
						{
							Test[0] = false;
							break;
						}
						else
							Test[0] = true;
					}
					if (k1->isunder_check(4, 0, 1) || k1->isunder_check(2, 0, 1))
					{
						Test[1] = false;
					}
				}
			}
		}
	}




	if (color == 0)
	{

		if (b[0] == true && b[1] == true)
		{
			if (m_Chessboard->getPiece(0, 7) != nullptr)
			{
				if (m_Chessboard->getPiece(0, 7) == m_chessGamePieces[30])
				{
					for (int i = 1; i < 4; i++)
					{
						if (m_Chessboard->getPiece(i, 7) != nullptr)
						{
							Test[2] = false;
							break;
						}
						else
							Test[2] = true;
					}
					if (k2->isunder_check(4, 7, 0) || k2->isunder_check(2, 7, 0))
					{
						Test[3] = false;
					}

				}
			}
		}
	}

	if (color == 1)
	{
		return(Test[0] && Test[1]);
	}
	else if (color == 0)
	{
		return(Test[2] && Test[3]);
	}

}
bool Rules::Castle_Rule_r(bool a[3], bool b[3], int color)
{
	King*k1 = static_cast<King*>(m_chessGamePieces[8]);

	King*k2 = static_cast<King*>(m_chessGamePieces[24]);
	bool Test[4] = { false,true,false,true };
	if (color == 1)
	{
		
		if (a[2] == true && a[1] == true)
		{
			if (m_Chessboard->getPiece(7, 0) != nullptr)
			{
				if (m_Chessboard->getPiece(7, 0) == m_chessGamePieces[15])
				{
					for (int i = 5; i < 7; i++)
					{
						if (m_Chessboard->getPiece(i, 0) != nullptr)
						{
							Test[0] = false;
							break;
						}
						else
							Test[0] = true;
					}
					if (k1->isunder_check(4, 0, 1) || k1->isunder_check(6, 0, 1))
					{
						Test[1] = false;
					}
				}
			}
		}
	}




	if (color == 0)
	{

		if (b[2] == true && b[1] == true)
		{
			if (m_Chessboard->getPiece(7, 7) != nullptr)
			{
				if (m_Chessboard->getPiece(7, 7) == m_chessGamePieces[31])
				{
					for (int i = 5; i < 7; i++)
					{
						if (m_Chessboard->getPiece(i, 7) != nullptr)
						{
							Test[2] = false;
							break;
						}
						else
							Test[2] = true;
					}
					if (k2->isunder_check(4, 7, 0) || k2->isunder_check(6, 7, 0))
					{
						Test[3] = false;
					}

				}
			}
		}
	}

	if (color == 1)
	{
		return(Test[0] && Test[1]);
	}
	else if (color == 0)
	{
		return(Test[2] && Test[3]);
	}
}


bool Rules::Pawn_Rule(int color,int i,int j)
{
	bool prule_w = false;
	bool prule_b = false;
	if (color == 1)
	{
		for (int k = 0; k < 8; k++)
		{
			if (m_Chessboard->getPiece(i, j) == m_chessGamePieces[k]&&(j==7))
			{
				prule_w = true;
			}
		}
		return prule_w;
	}
	if (color == 0)
	{
		for (int k = 16; k < 24; k++)
		{
			if (m_Chessboard->getPiece(i, j) == m_chessGamePieces[k] && (j == 0))
			{
				prule_b = true;
			}
		}
		return prule_b;
	}
	

}
bool Rules::checkforfinish(int color)
{
	King*whiteking = static_cast<King*>(m_chessGamePieces[8]);
	King*blackking = static_cast<King*>(m_chessGamePieces[24]);
	if (color == 1)
	{
		return(whiteking->check_mate());
	}
	else if (color == 0)
	{
		return(blackking->check_mate());
	}
}
void Rules::test()
{
	m_Chessboard->set(1, 1, nullptr);
	Piece*newptr = new rook(1, 1, 1, m_Chessboard);
	m_Chessboard->set(1, 1, newptr);
	if (typeid(newptr) == typeid(m_Chessboard->getPiece(0, 0)))
	{
		cout << "Match\n";
	}
	if (typeid(newptr) == typeid(m_Chessboard->getPiece(1, 0)))
	{
		cout << "Double Match\n";
	}
		
}
Rules::~Rules()
{
}
