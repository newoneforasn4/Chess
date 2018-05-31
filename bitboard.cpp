#include "bitboard.h"

// Initializer
bitboard::bitboard()
{
	resetBoard();
}

bitboard::bitboard(u64 bboard[])
{
	setBoard(bboard);
}

bitboard::~bitboard()
{
}

u64 bitboard::getBoard()
{
	u64 bboard = 0;
	for (int i = 0; i < 12; i++)
		bboard|=board[i];
	return bboard;
}

void bitboard::setBoard(u64 bboard[])
{
	for (int i = 0; i < 12; i++)
		board[i] = bboard[i];
	return;
}

void bitboard::resetBoard()
{
	board[0] = wP;
	board[1] = wN;
	board[2] = wB;
	board[3] = wR;
	board[4] = wQ;
	board[5] = wK;
	board[6] = bP;
	board[7] = bN;
	board[8] = bB;
	board[9] = bR;
	board[10] = wQ;
	board[11] = wK;
	return;
}

int bitboard::getPlayer()
{
	return turn%2;
}

int bitboard::getTurn()
{
	return turn;
}

void bitboard::incrementTurn()
{
	turn++;
}