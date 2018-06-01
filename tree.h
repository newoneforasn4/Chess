#ifndef tree_h
#define tree_h

#include "node.h"

class tree // Used for minimax search
{
private:
	node root;
	short depth;

public:
	tree();
	~tree();
};

#endif // tree_h