all:
	g++ bitboard.h bitboard.cpp movegen.h movegen.cpp node.h node.cpp tree.h tree.cpp -std=c++11 -o chess
