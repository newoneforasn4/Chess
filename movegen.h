#ifndef movegen_h
#define movegen_h

#include "bitboard.h"
#include <iostream>
#include <algorithm>
#include <string>

// Piece Movement
u64 knightAttacks(u64 knights);
u64 bishopAttacks(u64 bishops);
u64 rookAttacks(u64 rooks);
u64 queenAttacks(u64 queens);
u64 kingAttacks(u64 kings);

// Helper
void printBoard(u64 n);

#endif // movegen_h
