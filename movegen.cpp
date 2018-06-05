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

u64 generateDiagonalUp(u64 bishops , u8 shift ){
	u64 u1 =( bishops << shift )&0x000000000000FF00;
	u64 u = u1;
	u1 = ( bishops << shift * 2 ) & 0x0000000000FF0000;
	u = u | u1;
	u1 = ( bishops << shift * 3 ) & 0x00000000FF000000;
	u = u | u1;
	u1 = ( bishops << shift * 4 ) & 0x000000FF00000000;
	u = u | u1;
	u1 = ( bishops << shift * 5 ) & 0x0000FF0000000000;
	u = u | u1;
	u1 = ( bishops << shift * 6 ) & 0x00FF000000000000;
	u = u | u1;
	u1 = ( bishops << shift * 7 ) & 0xFF00000000000000;
	u = u | u1;
	
	return  u;
}

u64 generateDiagonalDown(u64 bishops, u8 shift){
	u64 u1 =( bishops >> shift )&0x000000000000FF00;
	u64 u = u1;
	u1 = ( bishops >> shift * 2 ) & 0x0000000000FF0000;
	u = u | u1;
	u1 = ( bishops >> shift * 3 ) & 0x00000000FF000000;
	u = u | u1;
	u1 = ( bishops >> shift * 4 ) & 0x000000FF00000000;
	u = u | u1;
	u1 = ( bishops >> shift * 5 ) & 0x0000FF0000000000;
	u = u | u1;
	u1 = ( bishops >> shift * 6 ) & 0x00FF000000000000;
	u = u | u1;
	u1 = ( bishops >> shift * 7 ) & 0xFF00000000000000;
	u = u | u1;
}

u64 bishopAttacks(u64 bishops , u64 currentboard, u64 targetboard)
{
	
	//wip
	u64 out = generateDiagonalUp(bishops,7)|generateDiagonalUp(bishops,9)|generateDiagonalDown(bishops,7)|generateDiagonalDown(bishops,9);
	/*u64 out = (generateDiagonalUp(bishops,7)^(generateDiagonalUp(currentboard,7)^currentboard))|
 		  (generateDiagonalUp(bishops,9)^(generateDiagonalUp(currentboard,9)^currentboard))|
 		  (generateDiagonalDown(bishops,7)^(generateDiagonalDown(currentboard,7)^currentboard))|
 		  (generateDiagonalDown(bishops,9)^(generateDiagonalDown(currentboard,9)^currentboard));*/
	return out;
	
	
}

u64 rookAttacks(u64 rooks)
{

}

u64 queenAttacks(u64 queens)
{
	//return rookAttacks(queens) | bishopAttacks(queens);
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
	return;
}

// TEST
int main()
{
	bitboard board = bitboard();
	printBoard(board.wB);
	printBoard(board.getWhiteBoard());
	//printBoard(knightAttacks(board.wN, board.getWhiteBoard()));
	//printBoard(knightAttacks(board.bN, board.getBlackBoard()));
	//bishopAttacks(board.wB);
	//printBoard(bishopAttacks(0x0000000000000080));
	printBoard(bishopAttacks(board.wB,board.wR,board.getBlackBoard()));
	return 0;
}
