#pragma once
#ifndef node_h
#define node_h

#include "bitboard.h"
#include <vector>

class node // Used for minimax search
{
private:
	u64 board[12]; // The board that will be evaluated
	u8 score; // The score of the evaluation
	std::vector<node> children; // Children

public:
	node();
	node(u64 bboard[]);
	~node();

	u64 getBoard();
	void setBoard(u64 bboard[]);

	u8 getScore();
	void setScore(u8 s);

	std::vector<node> getChildren();

	void addChild(node child);
};

#endif // node_h
