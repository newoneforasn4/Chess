#pragma once
#ifndef movegen_h
#define movegen_h

#include "bitboard.h"

// Piece Movement
u64 knightAttacks(u64 knights, u64 board);
u64 bishopAttacks(u64 bishops);
u64 rookAttacks(u64 rooks);
u64 queenAttacks(u64 queens);
u64 kingAttacks(u64 kings, u64 board);

// Move simulation
u64 move(u64 board[]); // The function that actually moves a piece

// Helper
void printBoard(u64 n);

#endif // movegen_h
