#include <stdio.h>
#include "Curses_Viewer.hpp"

int main(int argc, char* argv[])
{
	Curses_Viewer view;
	Board board;

	board.loadPositionIntoRow("2Kpp2q",3);
	view.init();
	view.draw_board(board);
	getchar();

	view.end();
	return 0;
}
