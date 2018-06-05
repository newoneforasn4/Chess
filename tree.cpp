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
	remove(root); // This is very questionable
}

void tree::remove(node* root)
{
	for (u8 i = 0; i < root->children.size(); i++)
		remove(root->children[i]);
	delete root;
	return;
}

void tree::populate()
{
	// Append children to current node recursively
	// Each child represents a board state after a move
}
