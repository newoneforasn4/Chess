#pragma once
#ifndef bitboard_h
#define bitboard_h
#define u64 unsigned long long
#define u8 unsigned short

class bitboard
{
private:
	u64 board[12];
	u8 turn = 1; // odd turns = white, even turns = black
	u8 fifty_move_counter = 0;

public:
	// constants
	u64 wP = 0x000000000000FF00;
	u64 wN = 0x0000000000000042;
	u64 wB = 0x0000000000000024;
	u64 wR = 0x0000000000000081;
	u64 wQ = 0x0000000000000010;
	u64 wK = 0x0000000000000008;

	u64 bP = 0x00FF000000000000;
	u64 bN = 0x4200000000000000;
	u64 bB = 0x2400000000000000;
	u64 bR = 0x8100000000000000;
	u64 bQ = 0x1000000000000000;
	u64 bK = 0x0800000000000000;
	
	bool wCastle[2] = {false, false}; // castle[0] = King side castle, castle[1] = Queen side castle
	bool bCastle[2] = {false, false};

	bitboard();
	bitboard(u64 bboard[], u8 t, u8 fmc);
	~bitboard();

	u64 getBoard();
	void setBoard(u64 bboard[]);
	void resetBoard();

	u64 getBlackBoard();
	u64 getWhiteBoard();

	u8 getPlayer();
	u8 getTurn();
	void incrementTurn();
};

#endif // bitboard_h
