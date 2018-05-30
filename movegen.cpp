#include "bitboard.h"
#include <iostream>
#include <cassert>

u64 knightAttacks(u64 knights)
{
	u64 l1 = (knights >> 1) & 0x7f7f7f7f7f7f7f7f;
	u64 l2 = (knights >> 2) & 0x3f3f3f3f3f3f3f3f;
	u64 r1 = (knights << 1) & 0xfefefefefefefefe;
	u64 r2 = (knights << 2) & 0xfcfcfcfcfcfcfcfc;
	u64 h1 = l1 | r1;
	u64 h2 = l2 | r2;
	return (h1 << 16) | (h1 >> 16) | (h2 << 8) | (h2 >> 8);
}

// TEST
int main()
{
	bitboard board = bitboard();
	std::cout << knightAttacks(board.wN) << std::endl;
	std::cout << knightAttacks(board.bN) << std::endl;
	return 0;
}

/* WHITE KNIGHT
00000000
00000000
00000000
00000000
00000000
00000000
00000000
01000010

00000000
00000000
00000000
00000000
00000000
10100101
00011000
00000000
*/

/* BLACK KNIGHT
01000010
00000000
00000000
00000000
00000000
00000000
00000000
00000000

00000000
00011000
10100101
00000000
00000000
00000000
00000000
00000000
*/