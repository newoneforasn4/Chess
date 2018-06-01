#ifndef node_h
#define node_h

#include "movegen.h"

class node // Used for minimax search
{
private:
	u64 board[12]; // The board that will be evaluated
	short score; // The score of the evaluation
	node *children[]; // Children

public:
	node();
	~node();
};

#endif // node_h