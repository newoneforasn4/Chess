#include "bitboard.h"

// Initializer
bitboard::bitboard()
{
	
}

bitboard::~bitboard()
{
}

u64 bitboard::getboard()
{
	return board;
}

void bitboard::resetBoard()
{
	board = {wP,wN,wB,wR,wQ,wK,bP,bN,bB,bR,bQ,bK};
}