#include "bitboard.h"

// Initializer
bitboard::bitboard()
{
	resetBoard();
	turn = 1;
	fifty_move_counter = 0;
}

bitboard::bitboard(u64 bboard[], u8 t, u8 fmc)
{
	setBoard(bboard);
	turn = t;
	fifty_move_counter = fmc;
}

bitboard::~bitboard()
{
}

u64 bitboard::getBoard()
{
	u64 bboard = 0;
	for (u8 i = 0; i < 12; i++)
		bboard|=board[i];
	return bboard;
}

void bitboard::setBoard(u64 bboard[])
{
	for (u8 i = 0; i < 12; i++)
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

u64 bitboard::getBlackBoard()
{
	u64 black_board = 0;
	for (u8 i = 6; i < 12; i++)
		black_board |= board[i];
	return black_board;
}

u64 bitboard::getWhiteBoard()
{
	u64 white_board = 0;
	for (u8 i = 0; i < 6; i++)
		white_board |= board[i];
	return white_board;
}

u8 bitboard::getPlayer()
{
	return turn%2;
}

u8 bitboard::getTurn()
{
	return turn;
}

void bitboard::incrementTurn()
{
	turn++;
	return;
}
