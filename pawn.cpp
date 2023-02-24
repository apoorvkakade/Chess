#include "stdafx.h"
#include <iostream>
#include "pawn.h"
#include"Piece.h"
#include"Board.h"
using namespace std;



pawn::pawn(int iInitial, int jInitial, int colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}



bool pawn::gen_test(int a, int b, int c)
{
	bool gen_test = false;

	if (c == 1)
	{

		if (a == m_i && b == m_j + 1 && m_Chessboard->getPiece(a, b) == nullptr)
		{
			gen_test= true;
		}
		if (m_Chessboard->getPiece(a,b)!=nullptr)
		{
			if (a == m_i - 1 && b == m_j + 1 && m_Chessboard->getPiece(a, b)->m_color == !c)
			{
				gen_test = true;
			}
		}
		 if (m_Chessboard->getPiece(a, b) != nullptr)
		{
			if (a == m_i + 1 && b == m_j + 1 && m_Chessboard->getPiece(a, b)->m_color == !c)
			{
				gen_test = true;
			}
		}
		 if (m_Chessboard->getPiece(a, b) == nullptr)
		{
			if (m_j == 1)
			{
				if (a == m_i && b == m_j + 2)
				{
					gen_test = true;
				}
			}
		}

		

	}
	if (c == 0)
	{
		if (a == m_i && b == m_j - 1 && m_Chessboard->getPiece(a, b) == nullptr)
		{
			gen_test = true;

		}

		if (m_Chessboard->getPiece(a, b) != nullptr)
		{
			if (a == m_i - 1 && b == m_j - 1 && m_Chessboard->getPiece(a, b)->m_color == !c)
			{
				gen_test = true;
			}
		}

		 if (m_Chessboard->getPiece(a, b) != nullptr)
		{
			if (a == m_i + 1 && b == m_j - 1 && m_Chessboard->getPiece(a, b)->m_color == !c)
			{
				gen_test = true;
			}
		}

		 if (m_Chessboard->getPiece(a, b) == nullptr)
		{
			if (m_j == 6)
			{
				if (a == m_i && b == m_j - 2)
				{
					gen_test = true;
				}
			}
		}

		
	}
	return gen_test;

}

bool pawn::give_check(int a, int b, int c)
{
	bool give_check = false;

	if (m_color == 1)
	{
		if ((a == m_i + 1 && b == m_j + 1) || (a == m_i - 1 && b == m_j + 1))
		{
			give_check = true;
		}
	
	}
	

	if (m_color == 0)
	{
		if ((a == m_i + 1 && b == m_j - 1) || (a == m_i - 1 && b == m_j - 1))
		{
			give_check = true;
		}
	
	}
	return give_check;
}

void pawn::printPiece()
{
	if (m_color == 1)
	{
		cout << "Paw:W";
	}

	if (m_color == 0)
	{
		cout << "Paw:B";
	}
}

pawn::~pawn()
{

}
