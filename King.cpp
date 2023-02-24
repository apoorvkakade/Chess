#include "stdafx.h"
#include<iostream>
#include"King.h"
#include"Board.h"
#include"game.h"


using namespace std;

King::King(int iInitial, int jInitial, int colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}

bool King::gen_test(int a, int b, int c)
{
	bool gen_test = false;

	if (m_Chessboard->getPiece(a, b) == nullptr || m_Chessboard->getPiece(a, b)->m_color != c)
	{
		if (a == m_i + 1 && b == m_j + 1)
		{
			gen_test = true;
		}
		if (a == m_i + 1 && b == m_j)
		{
			gen_test = true;
		}
		if (a == m_i + 1 && b == m_j - 1)
		{
			gen_test = true;
		}
		if (a == m_i && b == m_j - 1)
		{
			gen_test = true;
		}
		if (a == m_i - 1 && b == m_j - 1)
		{
			gen_test = true;
		}
		if (a == m_i - 1 && b == m_j)
		{
			gen_test = true;
		}
		if (a == m_i - 1 && b == m_j + 1)
		{
			gen_test = true;
		}
		if (a == m_i && b == m_j + 1)
		{
			gen_test = true;
		}
	}
	return gen_test;
}

void King::printPiece()
{
	if (m_color == 1)
	{
		cout << "Kin:W";
	}

	if (m_color == 0)
	{
		cout << "Kin:B";
	}
}

bool King::isunder_check(int kingi,int kingj,int color)
{
	bool isunder_check = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Chessboard->getPiece(i, j) != nullptr)
			{
				if (m_Chessboard->getPiece(i, j)->m_color == !m_color)

				{
					if (m_Chessboard->getPiece(i, j)->give_check(kingi,kingj,color) == true)
					{
						isunder_check = true;
						break;
					}
				}
			}
			
		}
	}
	return isunder_check;
}

bool King::check_mate()
{
	game g1;
	bool check_mate[9];
	bool checkmate = false;
	int counter = 0;
	bool blocked = true;


	//check how many opposite pieces are giving check
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Piece*temp = m_Chessboard->getPiece(j, i);

			if (temp != nullptr)
			{
				if (temp->m_color != this->m_color)
				{
					if (temp->give_check(this->m_i, this->m_j, this->m_color))
					{
						counter++;
					}
				}
			}
		}
	}




	for (int i = 0; i < 9; i++)
	{
		check_mate[i] = false;
	}

	if (g1.checkConstrainedMove(m_i, m_j) == true)
	{
		if (isunder_check(m_i, m_j, m_color))
		{
			check_mate[0] = true;
		}
	}
	/*else if (g1.checkConstrainedMove(m_i, m_j) == false)
	{
		check_mate[0] = true;
	}*/


	if (g1.checkConstrainedMove(m_i + 1, m_j + 1) == true)
	{
		if (isunder_check(m_i + 1, m_j + 1, m_color) || !gen_test(m_i + 1, m_j + 1, m_color))
		{
			check_mate[1] = true;
		}
	}
	else if (g1.checkConstrainedMove(m_i + 1, m_j + 1) == false)
	{
		check_mate[1] = true;
	}



	if (g1.checkConstrainedMove(m_i + 1, m_j) == true)
	{
		if (isunder_check(m_i + 1, m_j, m_color) || !gen_test(m_i + 1, m_j, m_color))
		{
			check_mate[2] = true;
		}
	}

	else if (g1.checkConstrainedMove(m_i + 1, m_j) == false)
	{
		check_mate[2] = true;
	}

	if (g1.checkConstrainedMove(m_i + 1, m_j - 1) == true)
	{
		if (isunder_check(m_i + 1, m_j - 1, m_color) || !gen_test(m_i + 1, m_j - 1, m_color))
		{
			check_mate[3] = true;
		}
	}

	else if (g1.checkConstrainedMove(m_i + 1, m_j - 1) == false)
	{
		check_mate[3] = true;
	}



	if (g1.checkConstrainedMove(m_i, m_j - 1) == true)
	{
		if (isunder_check(m_i, m_j - 1, m_color) || !gen_test(m_i, m_j - 1, m_color))
		{
			check_mate[4] = true;
		}
	}

	else if (g1.checkConstrainedMove(m_i, m_j - 1) == false)
	{
		check_mate[4] = true;
	}

	if (g1.checkConstrainedMove(m_i - 1, m_j - 1) == true)
	{
		if (isunder_check(m_i - 1, m_j - 1, m_color) || !gen_test(m_i - 1, m_j - 1, m_color))
		{
			check_mate[5] = true;
		}
	}
	else if (g1.checkConstrainedMove(m_i - 1, m_j - 1) == false)
	{
		check_mate[5] = true;
	}

	if (g1.checkConstrainedMove(m_i - 1, m_j) == true)
	{
		if (isunder_check(m_i - 1, m_j, m_color) || !gen_test(m_i - 1, m_j, m_color))
		{
			check_mate[6] = true;
		}
	}

	else if (g1.checkConstrainedMove(m_i - 1, m_j) == false)
	{
		check_mate[6] = true;
	}

	if (g1.checkConstrainedMove(m_i - 1, m_j + 1) == true)
	{
		if (isunder_check(m_i - 1, m_j + 1, m_color) || !gen_test(m_i - 1, m_j + 1, m_color))
		{
			check_mate[7] = true;
		}
	}

	else if (g1.checkConstrainedMove(m_i - 1, m_j + 1) == false)
	{
		check_mate[7] = true;
	}
	if (g1.checkConstrainedMove(m_i, m_j + 1) == true)
	{
		if (isunder_check(m_i, m_j + 1, m_color) || !gen_test(m_i, m_j + 1, m_color))
		{
			check_mate[8] = true;
		}
	}
	else if (g1.checkConstrainedMove(m_i, m_j + 1) == false)
	{
		check_mate[8] = true;
	}

	//blocked is true if king cannot move to any position

	for (int i =1; i < 9; i++)
	{
		blocked = blocked && check_mate[i];
	}

	//if king is not blocked,check mate not done,return false;
	if (!blocked)
	{
		return false;
	}

	//if theres more than one piece giving check and king is blocked ,checkmate is definitely true
	if (counter > 1 && blocked)
	{
		checkmate = true;
	}

	//if theres only one piece giving check find out their indices
	if (counter == 1)
	{
		int a, b;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Piece*temp = m_Chessboard->getPiece(i, j);
				if (temp != nullptr)
				{
					if (temp->m_color != m_color)
					{
						if (temp->give_check(this->m_i, this->m_j, m_color))
						{
							 a = temp->getI();
						     b = temp->getJ();
							 break;
						}
					}
				}
			}
		}

		//counter 3 is number of pieces of the kings color
		int counter3 = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Piece*temp = m_Chessboard->getPiece(i, j);
				if (temp != nullptr)
				{
					if (temp->m_color == m_color)
					{
						counter3++;
					}
				}
			}
		}

		//check if any piece of kings color can kill that one piece which is blocking the king
		//counter2 is number of pieces which cannot kill that one piece of opposite color.
		int counter2 = 0;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				Piece*temp = m_Chessboard->getPiece(i, j);
				if (temp != nullptr)
				{
					if (temp->m_color == m_color)
					{
						if ((temp->gen_test(a,b,m_color)==false)&&blocked)
						{
							counter2++;

						}
					}
				}
			}
		}
		if (counter2==counter3)
		{
			checkmate = true;
	    }

	}

	return checkmate;
		

}

bool King::give_check(int a, int b, int c)  //c is the color of the opposite color.
{
	return gen_test(a, b, !c);
}

King::~King()
{
}
