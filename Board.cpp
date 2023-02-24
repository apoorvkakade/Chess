#include "stdafx.h"
#include <iostream>

#include<cassert>
#include "Board.h"
#include "Piece.h"
#include"Table.h"

using namespace std;

Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_piecePosition[i][j] = nullptr;
		}
	}
	


}
void Board::display_board()
{
	
	for (int j = 7; j > -1; j--)
	{
		cout << j << "\t";

		for (int i = 0; i < 8; i++)
		{
		

			if (m_piecePosition[i][j] == nullptr)
			{
				cout << "- \t";
			}
			else
			{
				m_piecePosition[i][j]->printPiece();
				cout << "\t";
			}
			
		}
		cout << "\n";
		cout << "\n";
		cout << "\n";
	}
	cout << "\t";
	for (int i = 0; i < 8; i++)
	{
		cout << i << "\t";
	}

	cout << "\n\n";
}

void Board::set(int i, int j, Piece* piece)
{
	m_piecePosition[i][j] = piece;
}

Piece* Board::getPiece(int i, int j)
{
	assert(i >= 0 && i < 8 && j >= 0 && j < 8);

	if (m_piecePosition[i][j] == nullptr)
	{
		return nullptr;
	}
	else
		return m_piecePosition[i][j];
}
Board::~Board()
{

}


