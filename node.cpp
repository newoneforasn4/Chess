#include "node.h"

node::node()
{
}

node::node(u64 bboard[])
{
	setBoard(bboard);
}

node::~node()
{
}

void node::setBoard(u64 bboard[])
{
	for (u8 i = 0; i < 12; i++)
		board[i] = bboard[i];
}

u8 node::getScore()
{
	return score;
}

void node::setScore(u8 s)
{
	score = s;
}

void node::addChild(node child)
{
	children.push_back(child);
}
