#ifndef tree_h
#define tree_h

#include "node.h"

class tree // Used for minimax search
{
private:
	node* root;
	short height;

public:
	tree();
	tree(u64 bboard[12]);
	~tree();

	void populate();
};

#endif // tree_h
