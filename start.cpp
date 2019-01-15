#include <iostream>
#include <stdio.h>
#include "Curses_Viewer.hpp"
#include "Controller.hpp"

int main(int argc, char* argv[])
{
	Curses_Viewer view;
	Controller controller;

	view.init();
	view.draw_board(controller.board);
	getchar();

	view.end();

	std::cout << controller.board["a2"]->symbol << std::endl;
	return 0;
}
