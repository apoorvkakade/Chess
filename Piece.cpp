#include"stdafx.h"

#include<iostream>

#include"Piece.h"

using namespace std;

Piece::Piece(int i1, int j1, int color1, Board* chessBoard)
{
	m_i = i1;
	m_j = j1;
	m_color = color1;
	m_Chessboard = chessBoard;
}

int Piece::getI()
{
	return m_i;
}

int Piece::getJ()
{
	return m_j;
}

void Piece::setI(int i1)
{
	m_i = i1;
}

void Piece::setJ(int j1)
{
	m_j = j1;
}


Piece::~Piece()
{

}
