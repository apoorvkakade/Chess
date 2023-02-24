#pragma once
#ifndef GAME_H_
#define GAME_H_
class Board;
class Piece;
class game
{
public:
	game();
	void test(int i, int j);
	~game();
	Piece* getpiece(int color,int &i,int &j);
	void getindexes(int &iNext, int &jNext,int color);
	void execute();
	void move(Piece* piece, int iNext, int jNext);
	bool checkConstrainedMove(int iNext, int jNext);
	void promotion(bool valid,int i,int j,int color);
	void castle(bool valid,char choice,int color);
	Piece*getpointer(int i);
private:
	Board * m_Chessboard;
	Piece * m_chessGamePieces[32];
	
};
#endif // !GAME_H_


