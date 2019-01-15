#include <ncurses.h>
#include "Board.hpp"

class Curses_Viewer
{
	public:
		void init();
		void end();
		void draw_board(Board&);
		WINDOW* boardView;
};
