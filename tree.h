#pragma once
#ifndef tree_h
#define tree_h

#include "node.h"

class tree // Used for minimax search
{
private:
	node* root;
	u8 height;

public:
	tree();
	tree(u64 bboard[12]);
	~tree();

	void remove(node* root);
	void populate();
	void update();
};

#endif // tree_h
