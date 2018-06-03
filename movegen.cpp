#include "movegen.h"
#include <iostream>
#include <algorithm>
#include <string>

u64 knightAttacks(u64 knights, u64 board)
{
	u64 l1 = (knights >> 1) & 0x7F7F7F7F7F7F7F7F;
	u64 l2 = (knights >> 2) & 0x3F3F3F3F3F3F3F3F;
	u64 r1 = (knights << 1) & 0xFEFEFEFEFEFEFEFE;
	u64 r2 = (knights << 2) & 0xFCFCFCFCFCFCFCFC;
	u64 h1 = l1 | r1;
	u64 h2 = l2 | r2;

	u64 attacks = (h1 << 16) | (h1 >> 16) | (h2 << 8) | (h2 >> 8);
	attacks = attacks&~board;

	return attacks;
}

u64 bishopAttacks(u64 bishops)
{

}

u64 rookAttacks(u64 rooks)
{

}

u64 queenAttacks(u64 queens)
{
	return rookAttacks(queens) | bishopAttacks(queens);
}

u64 kingAttacks(u64 kings, u64 board)
{
	u64 left = (kings >> 1) & 0x7F7F7F7F7F7F7F7F;
	u64 right = (kings << 1) & 0xFEFEFEFEFEFEFEFE;
	u64 up = kings << 8;
	u64 down = kings >> 8;

	u64 attacks = left | (left << 8) | (left >> 8) | 
				right | (right << 8) | (right >> 8) |
				up | down;
	attacks = attacks&~board;

	return attacks;
}

u64 move(u64 board[])
{
	
}

void printBoard(u64 n)
{
	std::string bin;
	while (n)
	{
		bin.push_back((n&1) + '0');
		n>>=1;
	}
	while (bin.length() < 64)
		bin.push_back('0');
	if (bin.empty()) bin = '0';
	else std::reverse(bin.begin(), bin.end());
	for (int i = 0; i < 64; i++)
	{
		if (i%8 == 0) std::cout << std::endl;
		std::cout << bin[i];
	}
	std::cout << std::endl;
}

// TEST
int main()
{
	bitboard board = bitboard();
	printBoard(~board.getWhiteBoard());
	printBoard(knightAttacks(board.wN, board.getWhiteBoard()));
	printBoard(knightAttacks(board.bN, board.getBlackBoard()));
	return 0;
}
