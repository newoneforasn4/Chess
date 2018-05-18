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

u64 bitboard::getboard()
{
	u64 bboard = 0;
	for (int i = 0; i < 12; i++)
		bboard^=board[i];
	return bboard;
}

void bitboard::setBoard(u64 bboard[])
{
	for (int i = 0; i < 12; i++)
		board[i] = bboard[i]
	return;
}

void bitboard::resetBoard()
{
	board = {wP,wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK};
	return;
}