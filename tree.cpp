#include "tree.h"

tree::tree()
{
	root = new node();
	height = 1;
}

tree::tree(u64 bboard[])
{
	root = new node(bboard);
	height = 1;
}

tree::~tree()
{
	// Recursively delete tree using free() and vector.clear()
}

void tree::populate()
{
	// Append children to current node recursively
	// Each child represents a board state after a move
}
