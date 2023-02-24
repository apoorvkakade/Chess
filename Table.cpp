#include "stdafx.h"
#include<iostream>
#include"Board.h"
#include"Piece.h"
#include "Table.h"

#include"King.h"
using namespace std;

Table::Table(Board*b,Piece*x[32])
{
	for (int i = 0; i < 32; i++)
	{
		pieces[i] = x[i];
	}
	m_Chessboard = b;
}
void Table:: calculate()
{
	int whities = 0, blackies = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Chessboard->getPiece(i, j))
			{
				if (m_Chessboard->getPiece(i, j)->m_color == 1)
				{
					whities++;
				}
			}
		}
	}
	cell[0][0] = whities;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Chessboard->getPiece(i, j))
			{
				if (m_Chessboard->getPiece(i, j)->m_color == 0)
				{
					blackies++;
				}
			}
		}
	}
	cell[0][1] = blackies;
	int wdead, bdead;
	wdead = 16 - whities;
	bdead = 16 - blackies;
	cell[1][0] = wdead;
	cell[1][1] = bdead;
	King*Whiteking = static_cast<King*>(pieces[8]);
	King*Blackking = static_cast<King*>(pieces[24]);
	if (Whiteking->isunder_check(Whiteking->getI(), Whiteking->getJ(), Whiteking->m_color))
	{
		cell[2][0] = 1;
	}
	if (Blackking->isunder_check(Blackking->getI(), Blackking->getJ(), Blackking->m_color))
	{
		cell[2][1] = 1;
	}

}

void Table::Displaytable()
{
	calculate();
	cout << "       " << "White\tBlack\n\n";
	cout <<"Alive:    "<<cell[0][0]<<"\t"<<cell[0][1]<<"\n\n";
	cout << "Dead:     " << cell[1][0] << "\t" << cell[1][1] << "\n\n";
	cout << "Undercheck:" << cell[2][0] << "\t" << cell[2][1] << "\n\n";
	
	
}
