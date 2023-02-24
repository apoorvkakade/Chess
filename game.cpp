#include"stdafx.h"
#include<iostream>
#include<string>
#include"Board.h"
#include"pawn.h"
#include"King.h"
#include"Queen.h"
#include"rook.h"
#include"bishop.h"
#include"knight.h"
#include"Piece.h"
#include "game.h"
#include"Rules.h"
#include"Table.h";
using namespace std;

game::game()
{

	m_Chessboard = new Board();

	//Creating white pieces

	m_chessGamePieces[0] = new pawn(0, 1, 1, m_Chessboard);
	m_Chessboard->set(0, 1, m_chessGamePieces[0]);
	m_chessGamePieces[1] = new pawn(1, 1, 1, m_Chessboard);
	m_Chessboard->set(1, 1, m_chessGamePieces[1]);
	m_chessGamePieces[2] = new pawn(2, 1, 1, m_Chessboard);
	m_Chessboard->set(2, 1, m_chessGamePieces[2]);
	m_chessGamePieces[3] = new pawn(3, 1, 1, m_Chessboard);
	m_Chessboard->set(3, 1, m_chessGamePieces[3]);
	m_chessGamePieces[4] = new pawn(4, 1, 1, m_Chessboard);
	m_Chessboard->set(4, 1, m_chessGamePieces[4]);
	m_chessGamePieces[5] = new pawn(5, 1, 1, m_Chessboard);
	m_Chessboard->set(5, 1, m_chessGamePieces[5]);
	m_chessGamePieces[6] = new pawn(6, 1, 1, m_Chessboard);
	m_Chessboard->set(6, 1, m_chessGamePieces[6]);
	m_chessGamePieces[7] = new pawn(7, 1, 1, m_Chessboard);
	m_Chessboard->set(7, 1, m_chessGamePieces[7]);

	m_chessGamePieces[8] = new King(4, 0, 1, m_Chessboard);


	m_Chessboard->set(4, 0, m_chessGamePieces[8]);

	m_chessGamePieces[9] = new Queen(3, 0, 1, m_Chessboard);
	m_Chessboard->set(3, 0, m_chessGamePieces[9]);

	m_chessGamePieces[10] = new bishop(2, 0, 1, m_Chessboard);
	m_Chessboard->set(2, 0, m_chessGamePieces[10]);
	m_chessGamePieces[11] = new bishop(5, 0, 1, m_Chessboard);
	m_Chessboard->set(5, 0, m_chessGamePieces[11]);

	m_chessGamePieces[12] = new knight(1, 0, 1, m_Chessboard);
	m_Chessboard->set(1, 0, m_chessGamePieces[12]);
	m_chessGamePieces[13] = new knight(6, 0, 1, m_Chessboard);
	m_Chessboard->set(6, 0, m_chessGamePieces[13]);

	m_chessGamePieces[14] = new rook(0, 0, 1, m_Chessboard);
	m_Chessboard->set(0, 0, m_chessGamePieces[14]);
	m_chessGamePieces[15] = new rook(7, 0, 1, m_Chessboard);
	m_Chessboard->set(7, 0, m_chessGamePieces[15]);

	//Creating black pieces
	m_chessGamePieces[16] = new pawn(0, 6, 0, m_Chessboard);
	m_Chessboard->set(0, 6, m_chessGamePieces[16]);

	m_chessGamePieces[17] = new pawn(1, 6, 0, m_Chessboard);
	m_Chessboard->set(1, 6, m_chessGamePieces[17]);

	m_chessGamePieces[18] = new pawn(2, 6, 0, m_Chessboard);

	m_Chessboard->set(2, 6, m_chessGamePieces[18]);

	m_chessGamePieces[19] = new pawn(3, 6, 0, m_Chessboard);

	m_Chessboard->set(3, 6, m_chessGamePieces[19]);

	m_chessGamePieces[20] = new pawn(4, 6, 0, m_Chessboard);

	m_Chessboard->set(4, 6, m_chessGamePieces[20]);

	m_chessGamePieces[21] = new pawn(5, 6, 0, m_Chessboard);

	m_Chessboard->set(5, 6, m_chessGamePieces[21]);

	m_chessGamePieces[22] = new pawn(6, 6, 0, m_Chessboard);

	m_Chessboard->set(6, 6, m_chessGamePieces[22]);

	m_chessGamePieces[23] = new pawn(7, 6, 0, m_Chessboard);

	m_Chessboard->set(7, 6, m_chessGamePieces[23]);

	m_chessGamePieces[24] = new King(4, 7, 0, m_Chessboard);

	m_Chessboard->set(4, 7, m_chessGamePieces[24]);

	m_chessGamePieces[25] = new Queen(3, 7, 0, m_Chessboard);

	m_Chessboard->set(3, 7, m_chessGamePieces[25]);

	m_chessGamePieces[26] = new bishop(2, 7, 0, m_Chessboard);

	m_Chessboard->set(2, 7, m_chessGamePieces[26]);

	m_chessGamePieces[27] = new bishop(5, 7, 0, m_Chessboard);

	m_Chessboard->set(5, 7, m_chessGamePieces[27]);

	m_chessGamePieces[28] = new knight(1, 7, 0, m_Chessboard);

	m_Chessboard->set(1, 7, m_chessGamePieces[28]);

	m_chessGamePieces[29] = new knight(6, 7, 0, m_Chessboard);

	m_Chessboard->set(6, 7, m_chessGamePieces[29]);

	m_chessGamePieces[30] = new rook(0, 7, 0, m_Chessboard);

	m_Chessboard->set(0, 7, m_chessGamePieces[30]);

	m_chessGamePieces[31] = new rook(7, 7, 0, m_Chessboard);

	m_Chessboard->set(7, 7, m_chessGamePieces[31]);
}
void game::test(int i,int j)
{
	if (m_Chessboard->getPiece(i, j) == nullptr)
	{
		cout << "no piece there\n";
	}
}



void game::execute()
{
	Table *table = new Table(m_Chessboard,m_chessGamePieces);

	int whiteplay = 1;
	Rules r1(m_Chessboard,m_chessGamePieces);
	King*Whiteking = static_cast<King*>(m_chessGamePieces[8]);
	King*Blackking = static_cast<King*>(m_chessGamePieces[24]);

	bool castle_flag_w[3] = { true,true,true };
	bool castle_flag_b[3] = { true,true,true };
	cout << "WELCOME TO CHESS\n\n\n";

	while (1)
	{
		table->Displaytable();
		m_Chessboard->display_board(); 
		cout << "\n\n";
		
		
		bool finished=r1.checkforfinish(whiteplay);
		if (finished)
		{
			if (whiteplay)
			{
				cout << "Black wins\n";
			}
			else if (!whiteplay)
			{
				cout << "white wins\n";
			}
			break;
		}

		if (Whiteking->isunder_check(Whiteking->getI(), Whiteking->getJ(), 1))
		{
			cout << "White king under check,play accordingly\n";
		}
		else if (Blackking->isunder_check(Blackking->getI(), Blackking->getJ(), 0))
		{
			cout << "Black king is under check,play accordingly\n";
		}
		int i, j;

		Piece* selectedpiece=getpiece(whiteplay,i,j);//getpiece to play
		if (selectedpiece)
		{
			cout << "You selected:\t";
			selectedpiece->printPiece();
		
		cout << endl;
		int inext, jnext;
		
		getindexes(inext, jnext, whiteplay);  //get inext and jnext only if on the board(exception for castle);

		Piece*temp = m_Chessboard->getPiece(inext, jnext);

		if (selectedpiece == m_chessGamePieces[8])
		{
			castle_flag_w[1] = false;
		}
		if (selectedpiece == m_chessGamePieces[14])
		{
			castle_flag_w[0] = false;
		}
		if (selectedpiece == m_chessGamePieces[15])
		{
			castle_flag_w[2] = false;
		}

		if (selectedpiece == m_chessGamePieces[24])
		{
			castle_flag_b[1] = false;
		}
		if (selectedpiece == m_chessGamePieces[30])
		{
			castle_flag_b[0] = false;
		}
		if (selectedpiece == m_chessGamePieces[31])
		{
			castle_flag_b[2] = false;
		}
		
		if (selectedpiece->gen_test(inext, jnext, whiteplay) && selectedpiece->m_color == whiteplay)
		{
			move(selectedpiece, inext, jnext);
			bool whitecheck = Whiteking->isunder_check(Whiteking->getI(), Whiteking->getJ(), Whiteking->m_color);
			bool blackcheck = Blackking->isunder_check(Blackking->getI(), Blackking->getJ(), Blackking->m_color);
			promotion(r1.Pawn_Rule(whiteplay, inext, jnext), inext, jnext, whiteplay);		//if promotion valid apply the rule
			whiteplay = !whiteplay;
			if (whiteplay == 0)
			{
				if (whitecheck)
				{
					cout << "Move not valid as white king is coming under check \n";
					move(selectedpiece, i, j);
					if (temp)
					{
						move(temp, inext, jnext);
					}
					else if (!temp)
					{
						m_Chessboard->set(inext, jnext, nullptr);
					}
					whiteplay = 1;
				}

			}

			else if (whiteplay == 1)
			{
				if (blackcheck)
				{
					cout << "Move not valid,black king coming under check \n";
					move(selectedpiece, i, j);
					if (temp)
					{
						move(temp, inext, jnext);
					}
					else if (!temp)
					{
						m_Chessboard->set(inext, jnext, nullptr);
					}
					whiteplay = 0;
				}
			}


		}

		else
			cout << "Not a valid move\n";

		}

		else if (!selectedpiece)
		{
			if (i == -1 && j == -1)
			{
				bool castlevalid = r1.Castle_Rule_l(castle_flag_w, castle_flag_b, whiteplay);
				if (castlevalid)
				{
					castle(castlevalid, 'l', whiteplay);
					whiteplay = !whiteplay;
				}
				else
					cout << "Castle not valid\n";


			}
			else if (i == -2 && j == -2)
			{
				bool castlevalid = r1.Castle_Rule_r(castle_flag_w, castle_flag_b, whiteplay);
				if (castlevalid)
				{
					castle(castlevalid, 'r', whiteplay);
					whiteplay = !whiteplay;
				}
				else
					cout << "Castle not valid\n";


			}
			else
				cout << "Not a piece there\n";
		}

	}
}

void game::move(Piece* piece, int iNext, int jNext)
{
	int i = piece->getI();
	int j = piece->getJ();
	m_Chessboard->set(i, j, nullptr);
	piece->setI(iNext);
	piece->setJ(jNext);
	m_Chessboard->set(iNext, jNext, piece);
}

bool game::checkConstrainedMove(int iNext, int jNext)
{
	bool checkConstrainedMove = true;

	if (iNext < 0 || jNext < 0 || iNext > 7 || jNext > 7)
	{
		checkConstrainedMove = false;
	}

	return checkConstrainedMove;
}

void game::promotion(bool valid, int i, int j, int color)
{
	if (valid)
	{
		int choice;
		cout << "Enter choice number of the piece to revive\n";
		cout << "1.)Queen\n2.)Rook\n3.)Knight\n4.)Bishop\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			m_Chessboard->set(i, j, nullptr);
			Piece*newptr = new Queen(i, j, color, m_Chessboard);
			m_Chessboard->set(i, j, newptr);
			break;
		}
		case 2:
		{
			m_Chessboard->set(i, j, nullptr);
			Piece*newptr = new rook(i, j, color, m_Chessboard);
			m_Chessboard->set(i, j, newptr);
			break;
		}
		case 3:
		{
			m_Chessboard->set(i, j, nullptr);
			Piece*newptr = new knight(i, j, color, m_Chessboard);
			m_Chessboard->set(i, j, newptr);
			break;
		}
		case 4:
		{
			m_Chessboard->set(i, j, nullptr);
			Piece*newptr = new bishop(i, j, color, m_Chessboard);
			m_Chessboard->set(i, j, newptr);
			break;
		}
		default:
			break;
		}
	}
}


void game::castle(bool valid, char choice, int color)
{
	if (valid)
	{

		if (choice == 'l')
		{
			if (color == 1)
			{
				move(m_chessGamePieces[8], 2, 0);
				move(m_chessGamePieces[14], 3, 0);
			}
			else if (color == 0)
			{
				move(m_chessGamePieces[24], 2, 7);
				move(m_chessGamePieces[30], 3, 7);
			}
		}

		else if (choice == 'r')

		{
			if (color == 1)
			{
				move(m_chessGamePieces[8], 6, 0);
				move(m_chessGamePieces[15], 5, 0);
			}
			else if (color == 0)
			{
				move(m_chessGamePieces[24], 6, 7);
				move(m_chessGamePieces[31], 5, 7);
			}
		}

	}
	else
		cout << "Castle not valid\n";
}
Piece * game::getpointer(int i)
{
	return m_chessGamePieces[i];
}
game::~game()
{
}
Piece* game::getpiece(int color,int &i,int &j)
{
	Piece*selectedpiece = nullptr;
	Rules castlerule(m_Chessboard, m_chessGamePieces);
	
	while (1)
	{ 
		if (color == 1)
		{
			cout<<"White will play\n";
		}
		else
		{
			cout<<"Black will play\n";
		}
		cout << "Enter indexes of the piece of the piece you want to move\n";

		cin >> i >> j;

		if (checkConstrainedMove(i, j))
		{
			if (m_Chessboard->getPiece(i,j) != nullptr && m_Chessboard->getPiece(i, j)->m_color == color)
			{
				selectedpiece = m_Chessboard->getPiece(i, j);
				break;
			}
			else
			{
				cout<<"Invalid piece selection\n";
			}
			
		}
		
		if ((i == -1 && j == -1) || (i == -2 && j == -2))
		{
			break;
		}
		else if (!checkConstrainedMove(i, j))
		{
			cout << "Indexes should be within the board\n";
		}
	      
		
			
	}

	return(selectedpiece);
}

void game::getindexes(int & iNext, int & jNext,int color)
{
	while (1)
	{
		cout << "Enter desired location\n";
		cin >> iNext >> jNext;
		if (checkConstrainedMove(iNext,jNext))
		{
			break;
		}
		else if(!checkConstrainedMove(iNext,jNext))
		{
			cout << "Invalid Move\n";
			continue;
		}
	}
}


