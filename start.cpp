#include <iostream>
#include <stdio.h>
#include "Curses_Viewer.hpp"

int main(int argc, char* argv[])
{
	Curses_Viewer view;
	Board board;

	board.loadPosition("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
	view.init();
	view.draw_board(board);
	getchar();

	view.end();

	std::cout << board["a2"]->symbol << std::endl;
	return 0;
}
