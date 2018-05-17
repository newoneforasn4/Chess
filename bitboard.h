#ifndef bitboard_h
#define bitboard_h
#define u64 unsigned long long

class bitboard
{
public:
	u64 wP, wN, wB, wR, wQ, wK
	u64 bP, bN, bB, bR, bQ, bK

	bitboard();
	~bitboard();
};

#endif // bitboard_h